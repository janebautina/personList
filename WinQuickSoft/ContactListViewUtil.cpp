#include "stdafx.h"

#include "ContactListViewUtil.h"
#include "StringUtil.h"

ListViewItem^ createListViewItemForPerson(const Person& p) {
  ListViewItem^ listItem = gcnew ListViewItem(toWindowsString(p.getFirstName()));
  listItem->SubItems->Add(toWindowsString(p.getLastName()));
  listItem->SubItems->Add(toWindowsString(p.getStreetAddress()));
  listItem->SubItems->Add(toWindowsString(p.getCity()));
  listItem->SubItems->Add(toWindowsString(p.getCountry()));
  listItem->SubItems->Add(toWindowsString(p.getState()));
  listItem->SubItems->Add(toWindowsString(p.getZip()));
  listItem->SubItems->Add(toWindowsString(p.getEmail()));
  listItem->SubItems->Add(toWindowsString(p.getPhone()));
  listItem->SubItems->Add(toWindowsString(p.getNotes()));

  return listItem;
}

void repopulateContactListView(ListView^ listView, ContactList* contactList) {
  vector<Person> personList = contactList->getPersonList();
  listView->Items->Clear();
  for (vector<Person>::iterator iter = personList.begin();
      iter != personList.end();
      iter++) {
    listView->Items->Add(createListViewItemForPerson(*iter));
  }
}

