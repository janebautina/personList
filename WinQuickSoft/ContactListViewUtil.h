#pragma once

#include "QuickSoft.h"

using System::Windows::Forms::ListView;
using System::Windows::Forms::ListViewItem;

ListViewItem^ createListViewItemForPerson(const Person& p);
void repopulateContactListView(ListView^ listView, ContactList* contactList);
