// QuickSoft Contact List Management Program
// Author: Evgeniya Bautina

#include <iostream>
#include <string>
#include <vector>
#include <exception>

#include "json/value.h"

using namespace std;

#ifndef QUICKSOFT_H_
#define QUICKSOFT_H_

class ValidationException : public exception {
private:
  string message;

public:
  ValidationException(const string& _message) : message(_message) {
  }

  ~ValidationException() throw() {
  }

  virtual const char* what() const throw() {
    return message.c_str();
  }
};

class Person {
private:
  string firstName;
  string lastName;
  string streetAddress;
  string city;
  string country;
  string state;
  string zip;
  string email;
  string phone;
  string notes;

public:
  Person();
  void print();

  bool isValid(string& error);

  void toJson(Json::Value& v);
  bool fromJson(const Json::Value& v, string& error);

  string getFirstName() const { return firstName; }
  void setFirstName(const string& _firstName) { firstName = _firstName; }

  string getLastName() const { return lastName; }
  void setLastName(const string& _lastName) { lastName = _lastName; }

  string getStreetAddress() const { return streetAddress; }
  void setStreetAddress(const string& _streetAddress) { streetAddress = _streetAddress; }

  string getCity() const { return city; }
  void setCity(const string& _city) { city = _city; }

  string getCountry() const { return country; }
  void setCountry(const string& _country) { country = _country; }

  string getState() const { return state; }
  void setState(const string& _state) { state = _state; }

  string getZip() const { return zip; }
  void setZip(const string& _zip) { zip = _zip; }

  string getEmail() const { return email; }
  void setEmail(const string& _email) { email = _email; }

  string getPhone() const { return phone; }
  void setPhone(const string& _phone) { phone = _phone; }

  string getNotes() const { return notes; }
  void setNotes(const string& _notes) { notes = _notes; }

};

enum SearchField {
  SEARCH_BY_LAST_NAME,
  SEARCH_BY_EMAIL,
  SEARCH_BY_ZIP_CODE
};

string getSearchFieldName(SearchField sf);

class ContactList {
private:
  vector<Person> listOfPersons;
  string fileName;

  void findInfoByLastName(vector<Person>* results, const string& lastName);
  void findInfoByEmail(vector<Person>* results, const string& email);
  void findInfoByZipCode(vector<Person>* results, const string& zipcode);


public:
  ContactList();
  ~ContactList();

  void addContact(const Person& person);
  bool firstLastNameExist(const string& firstName, const string& lastName);

  void findByField(vector<Person>* results, SearchField searchField, const string& value);

  bool saveContacts(string& error);
  bool loadContacts(string& error);

  void deleteContactByFirstAndLastName(const string& firstName, const string& lastName);

  const string& getFileName() { return fileName; }

  const vector<Person>& getPersonList() { return listOfPersons; }
};

#endif /* QUICKSOFT_H_ */
