#pragma once

#include "QuickSoft.h"

#include "AddContactForm.h"
#include "FindContactsForm.h"
#include "ContactListViewUtil.h"
#include "LastNameSorter.h"

namespace WinQuickSoft {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindowForm
	/// </summary>
	public ref class MainWindowForm : public System::Windows::Forms::Form
	{
	public:
    ContactList* contactList;

		MainWindowForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
      contactList = new ContactList();

      string loadError;
      if (!contactList->loadContacts(loadError)) {
        MessageBox::Show(
            toWindowsString("Cannot load contact list: " + loadError),
            L"Cannot load contact list",
            MessageBoxButtons::OK, 
            MessageBoxIcon::Error);
        exit(1);
      }

      repopulateContactListView(contactListView, contactList);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindowForm()
		{
			if (components)
			{
				delete components;
			}
      if (contactList) {
        delete contactList;
      }
		}
	private: System::Windows::Forms::Button^  addNewContactButton;
	private: System::Windows::Forms::Button^  findByLastNameButton;

protected: 

	private: System::Windows::Forms::Button^  findByEmailButton;
	private: System::Windows::Forms::Button^  findAllByZipButton;
	private: System::Windows::Forms::Button^  deleteContactButton;
  private: System::Windows::Forms::ColumnHeader^  firstName;
  private: System::Windows::Forms::ColumnHeader^  lastName;
  private: System::Windows::Forms::ColumnHeader^  email;
  private: System::Windows::Forms::ColumnHeader^  phone;
  private: System::Windows::Forms::ColumnHeader^  streetAddress;
  private: System::Windows::Forms::ColumnHeader^  city;
  private: System::Windows::Forms::ColumnHeader^  country;
  private: System::Windows::Forms::ColumnHeader^  state;
  private: System::Windows::Forms::ColumnHeader^  zip;
  private: System::Windows::Forms::Button^  saveContactsButton;
  private: System::Windows::Forms::ListView^  contactListView;
  private: System::Windows::Forms::Button^  button1;
  private: System::Windows::Forms::ColumnHeader^  notes;

  private: System::Windows::Forms::ColumnHeader^  columnHeader1;
  private: System::Windows::Forms::ColumnHeader^  columnHeader2;
  private: System::Windows::Forms::ColumnHeader^  columnHeader3;
  private: System::Windows::Forms::ColumnHeader^  columnHeader4;
  private: System::Windows::Forms::ColumnHeader^  columnHeader5;
  private: System::Windows::Forms::ColumnHeader^  columnHeader6;
  private: System::Windows::Forms::ColumnHeader^  columnHeader7;
  private: System::Windows::Forms::ColumnHeader^  columnHeader8;
  private: System::Windows::Forms::ColumnHeader^  columnHeader9;
  private: System::Windows::Forms::ColumnHeader^  columnHeader10;

private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
      this->addNewContactButton = (gcnew System::Windows::Forms::Button());
      this->findByLastNameButton = (gcnew System::Windows::Forms::Button());
      this->contactListView = (gcnew System::Windows::Forms::ListView());
      this->firstName = (gcnew System::Windows::Forms::ColumnHeader());
      this->lastName = (gcnew System::Windows::Forms::ColumnHeader());
      this->streetAddress = (gcnew System::Windows::Forms::ColumnHeader());
      this->city = (gcnew System::Windows::Forms::ColumnHeader());
      this->country = (gcnew System::Windows::Forms::ColumnHeader());
      this->state = (gcnew System::Windows::Forms::ColumnHeader());
      this->zip = (gcnew System::Windows::Forms::ColumnHeader());
      this->email = (gcnew System::Windows::Forms::ColumnHeader());
      this->phone = (gcnew System::Windows::Forms::ColumnHeader());
      this->notes = (gcnew System::Windows::Forms::ColumnHeader());
      this->findByEmailButton = (gcnew System::Windows::Forms::Button());
      this->findAllByZipButton = (gcnew System::Windows::Forms::Button());
      this->deleteContactButton = (gcnew System::Windows::Forms::Button());
      this->saveContactsButton = (gcnew System::Windows::Forms::Button());
      this->button1 = (gcnew System::Windows::Forms::Button());
      this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
      this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
      this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
      this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
      this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
      this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
      this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
      this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
      this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
      this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
      this->SuspendLayout();
      // 
      // addNewContactButton
      // 
      this->addNewContactButton->Location = System::Drawing::Point(12, 12);
      this->addNewContactButton->Name = L"addNewContactButton";
      this->addNewContactButton->Size = System::Drawing::Size(156, 28);
      this->addNewContactButton->TabIndex = 0;
      this->addNewContactButton->Text = L"Add New Contact";
      this->addNewContactButton->UseVisualStyleBackColor = true;
      this->addNewContactButton->Click += gcnew System::EventHandler(this, &MainWindowForm::addNewContactButton_Click);
      // 
      // findByLastNameButton
      // 
      this->findByLastNameButton->Location = System::Drawing::Point(12, 81);
      this->findByLastNameButton->Name = L"findByLastNameButton";
      this->findByLastNameButton->Size = System::Drawing::Size(156, 28);
      this->findByLastNameButton->TabIndex = 20;
      this->findByLastNameButton->Text = L"Find by Last Name ";
      this->findByLastNameButton->UseVisualStyleBackColor = true;
      this->findByLastNameButton->Click += gcnew System::EventHandler(this, &MainWindowForm::findByLastNameHandler);
      // 
      // contactListView
      // 
      this->contactListView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
        | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right));
      this->contactListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(10) {this->firstName, 
        this->lastName, this->streetAddress, this->city, this->country, this->state, this->zip, this->email, this->phone, this->notes});
      this->contactListView->Location = System::Drawing::Point(185, 12);
      this->contactListView->Name = L"contactListView";
      this->contactListView->Size = System::Drawing::Size(690, 425);
      this->contactListView->TabIndex = 70;
      this->contactListView->UseCompatibleStateImageBehavior = false;
      this->contactListView->View = System::Windows::Forms::View::Details;
      this->contactListView->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindowForm::selectedIndexChangedHandler);
      // 
      // firstName
      // 
      this->firstName->Text = L"First Name";
      this->firstName->Width = 87;
      // 
      // lastName
      // 
      this->lastName->Text = L"Last Name";
      this->lastName->Width = 86;
      // 
      // streetAddress
      // 
      this->streetAddress->Text = L"Street Address";
      this->streetAddress->Width = 107;
      // 
      // city
      // 
      this->city->Text = L"City";
      this->city->Width = 41;
      // 
      // country
      // 
      this->country->Text = L"Country";
      // 
      // state
      // 
      this->state->Text = L"State";
      this->state->Width = 49;
      // 
      // zip
      // 
      this->zip->Text = L"Zip Code";
      this->zip->Width = 74;
      // 
      // email
      // 
      this->email->Text = L"Email";
      // 
      // phone
      // 
      this->phone->Text = L"Phone Number";
      this->phone->Width = 58;
      // 
      // notes
      // 
      this->notes->Text = L"Notes";
      // 
      // findByEmailButton
      // 
      this->findByEmailButton->Location = System::Drawing::Point(12, 115);
      this->findByEmailButton->Name = L"findByEmailButton";
      this->findByEmailButton->Size = System::Drawing::Size(156, 28);
      this->findByEmailButton->TabIndex = 30;
      this->findByEmailButton->Text = L"Find by Email";
      this->findByEmailButton->UseVisualStyleBackColor = true;
      this->findByEmailButton->Click += gcnew System::EventHandler(this, &MainWindowForm::findByEmailButton_Click);
      // 
      // findAllByZipButton
      // 
      this->findAllByZipButton->Location = System::Drawing::Point(12, 149);
      this->findAllByZipButton->Name = L"findAllByZipButton";
      this->findAllByZipButton->Size = System::Drawing::Size(156, 28);
      this->findAllByZipButton->TabIndex = 40;
      this->findAllByZipButton->Text = L"Find All by Zip Code";
      this->findAllByZipButton->UseVisualStyleBackColor = true;
      this->findAllByZipButton->Click += gcnew System::EventHandler(this, &MainWindowForm::findAllByZipButton_Click);
      // 
      // deleteContactButton
      // 
      this->deleteContactButton->Location = System::Drawing::Point(12, 183);
      this->deleteContactButton->Name = L"deleteContactButton";
      this->deleteContactButton->Size = System::Drawing::Size(156, 28);
      this->deleteContactButton->TabIndex = 50;
      this->deleteContactButton->Text = L"Delete by Last Name";
      this->deleteContactButton->UseVisualStyleBackColor = true;
      this->deleteContactButton->Click += gcnew System::EventHandler(this, &MainWindowForm::deleteContactByLastName);
      // 
      // saveContactsButton
      // 
      this->saveContactsButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
      this->saveContactsButton->Location = System::Drawing::Point(12, 409);
      this->saveContactsButton->Name = L"saveContactsButton";
      this->saveContactsButton->Size = System::Drawing::Size(156, 28);
      this->saveContactsButton->TabIndex = 60;
      this->saveContactsButton->Text = L"Save Contacts";
      this->saveContactsButton->UseVisualStyleBackColor = true;
      this->saveContactsButton->Click += gcnew System::EventHandler(this, &MainWindowForm::saveContactsHandler);
      // 
      // button1
      // 
      this->button1->Location = System::Drawing::Point(12, 46);
      this->button1->Name = L"button1";
      this->button1->Size = System::Drawing::Size(156, 28);
      this->button1->TabIndex = 10;
      this->button1->Text = L"Sort by Last Name";
      this->button1->UseVisualStyleBackColor = true;
      this->button1->Click += gcnew System::EventHandler(this, &MainWindowForm::sortByLastNameButtonClick);
      // 
      // columnHeader1
      // 
      this->columnHeader1->Text = L"First Name";
      this->columnHeader1->Width = 87;
      // 
      // columnHeader2
      // 
      this->columnHeader2->Text = L"Last Name";
      this->columnHeader2->Width = 86;
      // 
      // columnHeader3
      // 
      this->columnHeader3->Text = L"Street Address";
      this->columnHeader3->Width = 107;
      // 
      // columnHeader4
      // 
      this->columnHeader4->Text = L"City";
      this->columnHeader4->Width = 41;
      // 
      // columnHeader5
      // 
      this->columnHeader5->Text = L"Country";
      // 
      // columnHeader6
      // 
      this->columnHeader6->Text = L"State";
      this->columnHeader6->Width = 49;
      // 
      // columnHeader7
      // 
      this->columnHeader7->Text = L"Zip Code";
      this->columnHeader7->Width = 74;
      // 
      // columnHeader8
      // 
      this->columnHeader8->Text = L"Email";
      // 
      // columnHeader9
      // 
      this->columnHeader9->Text = L"Phone Number";
      this->columnHeader9->Width = 58;
      // 
      // columnHeader10
      // 
      this->columnHeader10->Text = L"Notes";
      // 
      // MainWindowForm
      // 
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
      this->ClientSize = System::Drawing::Size(910, 471);
      this->Controls->Add(this->button1);
      this->Controls->Add(this->saveContactsButton);
      this->Controls->Add(this->deleteContactButton);
      this->Controls->Add(this->findAllByZipButton);
      this->Controls->Add(this->findByEmailButton);
      this->Controls->Add(this->contactListView);
      this->Controls->Add(this->findByLastNameButton);
      this->Controls->Add(this->addNewContactButton);
      this->Name = L"MainWindowForm";
      this->Text = L"QuickSoft Contact List";
      this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainWindowForm::MainWindowForm_FormClosing);
      this->ResumeLayout(false);

    }
#pragma endregion
	private: System::Void deleteContactByLastName(System::Object^  sender, System::EventArgs^  e) {
             (gcnew FindContactsForm(contactList, SearchField::SEARCH_BY_LAST_NAME, true))->ShowDialog();
             repopulateContactListView(contactListView, contactList);
			 }

	private: System::Void findByLastNameHandler(System::Object^  sender, System::EventArgs^  e) {
             (gcnew FindContactsForm(contactList, SearchField::SEARCH_BY_LAST_NAME, false))->ShowDialog();
			     }

	private: System::Void selectedIndexChangedHandler(System::Object^  sender, System::EventArgs^  e) {
			 }

  private: System::Void addNewContactButton_Click(System::Object^  sender, System::EventArgs^  e) {
    Form ^ addContactForm = gcnew AddContactForm(contactList, contactListView);
    addContactForm->ShowDialog();
  }
  private: void saveContacts() {
    string saveError;
    if (contactList->saveContacts(saveError)) {
      MessageBox::Show(
          L"Contacts successfully saved",
          L"Contacts saved",
          MessageBoxButtons::OK, 
          MessageBoxIcon::Information);
    } else {
      MessageBox::Show(
          toWindowsString("Could not save contacts: " + saveError),
          L"Could not save contacts",
          MessageBoxButtons::OK, 
          MessageBoxIcon::Error);
    }
  }

  private: System::Void saveContactsHandler(System::Object^  sender, System::EventArgs^  e) {
    saveContacts();
  }

private: 
  System::Void sortByLastNameButtonClick(System::Object^  sender, System::EventArgs^  e) {
    contactListView->ListViewItemSorter = gcnew LastNameComparer;
    contactListView->Sort();
  }

private: System::Void MainWindowForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
    saveContacts();
  }

private: System::Void findByEmailButton_Click(System::Object^  sender, System::EventArgs^  e) {
           (gcnew FindContactsForm(contactList, SearchField::SEARCH_BY_EMAIL, false))->ShowDialog();
         }
private: System::Void findAllByZipButton_Click(System::Object^  sender, System::EventArgs^  e) {
           (gcnew FindContactsForm(contactList, SearchField::SEARCH_BY_ZIP_CODE, false))->ShowDialog();
         }

};
}

