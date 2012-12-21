// QuickSoft Contact List Management Program
// Author: Evgeniya Bautina

#include "stdafx.h"

#include <ctype.h>

#include <iostream>
#include <sstream>
#include <fstream>

#include "QuickSoft.h"
#include "StringUtil.h"

#include "json/writer.h"
#include "json/reader.h"

using namespace std;

// Helper functions
bool isValidName(const string& name, string& error) {
  for (size_t i = 0; i < name.length(); i++) {
    if (isalpha(name[i])) {
      error = "Invalid name " + name + ": should contain only letters!"; 
      return false;
    }
  }
  return true;
}


static const int MIN_PHONE_NUMBER_LENGTH = 5;
static const int MAX_PHONE_NUMBER_LENGTH = 11;

bool isValidPhoneNumber(const string& phone, string& error) {
  if (phone.empty()) {
    // A phone number can be empty
    return true;
  }
  error = "";
  int numLength = (int) phone.length();
  if (numLength > MAX_PHONE_NUMBER_LENGTH) {
    stringstream ss;
    ss << "Invalid phone number " << phone << ": has to have the length of at most "
        << MAX_PHONE_NUMBER_LENGTH << " digits";
    error = ss.str();
    return false;
  }

  if (numLength < MIN_PHONE_NUMBER_LENGTH) {
    stringstream ss;
    ss << "Invalid phone number " << phone << ": has to have the length of at least "
        << MIN_PHONE_NUMBER_LENGTH << " digits";
    error = ss.str();
    return false;
  }

  for (size_t i = 0; i < phone.length(); i++){
    if (!isdigit(phone[i])) {
      error = "Invalid phone number " + phone + ": should contain only digits!"; 
      return false;
    }
  }
  return true;
}

bool isValidEmail(const string& email, string& error) {
  if (email.empty()) {
    // The email might not be specified.
    return true;
  }

  error = "";

  if (email[email.length() - 1] == '.') {
    error = "Email cannot end with a dot";
    return false;
  }

	bool seenAt = false;
	bool seenDot = false;
	for (size_t i = 0; i < email.length(); i++) {
		if (email[i] == '@') {
			seenAt = true;
		}
		if (email[i] == '.') {
			seenDot = true;
		}
	}
	if (!seenAt) {
		error = "Invalid email " + email + ": does not contain '@'";
    return false;
	}
	if (!seenDot) {
		error = "Invalid email " + email + ": does not contain a dot";
    return false;
	}
  return true;
}

// Person

Person::Person() {
}

bool Person::isValid(string& error) {
  error.clear();
  if (firstName.empty()) {
    error = "First name cannot be empty";
    return false;
  }
  if (lastName.empty()) {
    error = "Last name cannot be empty";
    return false;
  } 

  if (!isValidEmail(email, error)) {
    return false;
  }
  if (!isValidPhoneNumber(phone, error)) {
    return false;
  }

  return true;
}

void Person::toJson(Json::Value& v) {
  v = Json::Value(Json::ValueType::objectValue);
  v["firstName"] = firstName;
  v["lastName"] = lastName;
  v["streetAddress"] = streetAddress;
  v["city"] = city;
  v["country"] = country;
  v["state"] = state;
  v["zip"] = zip;
  v["email"] = email;
  v["phone"] = phone;
  v["notes"] = notes;
}

string getJsonString(const Json::Value& dict, const string& fieldName) {
  Json::Value v(dict[fieldName]);
  if (!v.isString()) {
    throw ValidationException("Field " + fieldName + " must be a string");
  }
  return v.asString();
}

bool Person::fromJson(const Json::Value& v, string& error) {
  try {
    firstName = getJsonString(v, "firstName");
    lastName = getJsonString(v, "lastName");
    streetAddress = getJsonString(v, "streetAddress");
    city = getJsonString(v, "city");
    country = getJsonString(v, "country");
    state = getJsonString(v, "state");
    zip = getJsonString(v, "zip");
    email = getJsonString(v, "email");
    phone = getJsonString(v, "phone");
    notes = getJsonString(v, "notes");
    return true;
  } catch (const ValidationException& ex) {
    error = ex.what();
    return false;
  }
}

string getSearchFieldName(SearchField sf) {
  switch (sf) {
  case SearchField::SEARCH_BY_EMAIL:
    return "email";
  case SearchField::SEARCH_BY_LAST_NAME:
    return "last name";
  case SearchField::SEARCH_BY_ZIP_CODE:
    return "zip code";
  }
  return "unknown";
}

// ContactList

ContactList::ContactList()
    : fileName("contact_list.json") {
}

ContactList::~ContactList() {
}

void ContactList::addContact(const Person& person) {
	listOfPersons.push_back(person);
}

void ContactList::findInfoByLastName(vector<Person>* results, const string& lastName) {
	results->clear();
	for (vector<Person>::iterator iter = listOfPersons.begin();
			iter != listOfPersons.end();
			++iter) {
		if (stricmp(iter->getLastName().c_str(), lastName.c_str()) == 0) {
			results->push_back(*iter);
		}
	}
}

void ContactList::findInfoByEmail(vector<Person>* results, const string& email) {
	results->clear();
	for (vector<Person>::iterator iter = listOfPersons.begin();
			iter != listOfPersons.end();
			++iter) {
		if (stricmp(iter->getEmail().c_str(), email.c_str()) == 0) {
			results->push_back(*iter);
		}
	}
}

void ContactList::findInfoByZipCode(vector<Person>* results, const string& zipcode) {
	results->clear();
	for (vector<Person>::iterator iter = listOfPersons.begin();
			iter != listOfPersons.end();
			++iter) {
		if (iter->getZip() == zipcode) {
			results->push_back(*iter);
		}
	}
}

bool ContactList::firstLastNameExist(const string& firstName, const string& lastName) {
	for (vector<Person>::iterator iter = listOfPersons.begin();
			iter != listOfPersons.end();
			++iter) {
     if (stricmp(firstName.c_str(), iter->getFirstName().c_str()) == 0 &&
         stricmp(lastName.c_str(), iter->getLastName().c_str()) == 0) {
       return true;
     }
  }
  return false;
}

void ContactList::findByField(vector<Person>* results, SearchField searchField, const string& value) {
  results->clear();
  switch (searchField) {
  case SearchField::SEARCH_BY_EMAIL:
    findInfoByEmail(results, value);
    break;
  case SearchField::SEARCH_BY_LAST_NAME:
    findInfoByLastName(results, value);
    break;
  case SearchField::SEARCH_BY_ZIP_CODE:
    findInfoByZipCode(results, value);
    break;
  default:
    break;
  }
}

bool ContactList::saveContacts(string& error) {
  Json::Value doc(Json::ValueType::arrayValue);

  int i = 0;
	for (vector<Person>::iterator iter = listOfPersons.begin();
			iter != listOfPersons.end();
			++iter, ++i) {
    Json::Value v;
    iter->toJson(v);
    doc[i] = v;
  }

  Json::StyledWriter jsonWriter;
  
  error.clear();

  ofstream out(fileName);
  out << jsonWriter.write(doc);
  out.close();
  if (out.fail() || out.bad()) {
    stringstream ss; 
    ss << "Could not write " << fileName << ": " << strerror(errno);
    error = ss.str();
    return false;
  }
  return true;
}

bool fexists(const char *filename)
{
  ifstream ifile(filename);
  return !ifile.bad() && !ifile.fail();
}

bool ContactList::loadContacts(string& error) {
  // Create file if it does not exist
  if (!fexists(fileName.c_str())) {
    ofstream out(fileName);
    out << "[]" << endl;
    out.close();
    if (out.fail() || out.bad()) {
      stringstream ss;
      ss << "File " << fileName << " did not exist and could not create: " << strerror(errno);
      error = ss.str();
      return false;
    }
  }

  ifstream in(fileName);
  string jsonText((std::istreambuf_iterator<char>(in)),
              std::istreambuf_iterator<char>());
  in.close();
  if (in.fail() || in.bad()) {
    stringstream ss; 
    ss << "Could not read " << fileName << ": " << strerror(errno);
    error = ss.str();
    return false;
  }

  Json::Reader reader;
  Json::Value doc;

  if (!reader.parse(jsonText, doc)) {
    error = "Could not parse " + fileName + ": " + reader.getFormatedErrorMessages();
    return false;
  }
  
  if (!doc.isArray()) {
    error = "JSON document is not an array";
    return false;
  }

  int n = doc.size();
  for (int i = 0; i < n; ++i) {
    Json::Value& personJson = doc[i];
    Person p;

    if (!p.fromJson(personJson, error)) {
      return false;
    }

    string personValidationError;
    if (!p.isValid(personValidationError)) {
      error = "Invalid contact record " + personJson.toStyledString() + ": " + personValidationError;
      return false;
    }

    addContact(p);
  }

  error.clear();
  return true;
}

void ContactList::deleteContactByFirstAndLastName(const string& firstName, const string& lastName) {
	for (vector<Person>::iterator iter = listOfPersons.begin();
			iter != listOfPersons.end();
			++iter) {
     if (firstName == iter->getFirstName() &&
         lastName == iter->getLastName()) {
       listOfPersons.erase(iter);
       return;
     }
  }
}
