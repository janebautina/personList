#pragma once

#include "QuickSoft.h"
#include "StringUtil.h"
#include "ContactListViewUtil.h"

namespace WinQuickSoft {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddContactForm
	/// </summary>
	public ref class AddContactForm : public System::Windows::Forms::Form
	{
	public:
		AddContactForm(ContactList* contactList, System::Windows::Forms::ListView^ contactListView)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
      this->contactList = contactList;
      this->contactListView = contactListView; 
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddContactForm()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::Label^  label1;
  protected: 
  private: System::Windows::Forms::Label^  label2;
  private: System::Windows::Forms::Label^  label3;
  private: System::Windows::Forms::Label^  label4;
  private: System::Windows::Forms::TextBox^  firstNameTextBox;
  private: System::Windows::Forms::TextBox^  lastNameTextBox;
  private: System::Windows::Forms::TextBox^  emailTextBox;
  private: System::Windows::Forms::TextBox^  streetAddressTextBox;
  private: System::Windows::Forms::Label^  label5;
  private: System::Windows::Forms::GroupBox^  groupBox1;
  private: System::Windows::Forms::TextBox^  cityTextBox;

  private: System::Windows::Forms::Label^  label6;
  private: System::Windows::Forms::TextBox^  zipCodeTextBox;

  private: System::Windows::Forms::Label^  label9;
  private: System::Windows::Forms::TextBox^  stateTextBox;

  private: System::Windows::Forms::Label^  label8;
  private: System::Windows::Forms::TextBox^  countryTextBox;

  private: System::Windows::Forms::Label^  label7;
  private: System::Windows::Forms::TextBox^  phoneTextBox;

  private: System::Windows::Forms::Label^  label10;
  private: System::Windows::Forms::TextBox^  notesTextBox;

  private: System::Windows::Forms::Label^  label11;
  private: System::Windows::Forms::Button^  saveButton;
  private: System::Windows::Forms::Button^  cancelButton;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

    ContactList* contactList;
    System::Windows::Forms::ListView^ contactListView;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
      this->label1 = (gcnew System::Windows::Forms::Label());
      this->label2 = (gcnew System::Windows::Forms::Label());
      this->label3 = (gcnew System::Windows::Forms::Label());
      this->label4 = (gcnew System::Windows::Forms::Label());
      this->firstNameTextBox = (gcnew System::Windows::Forms::TextBox());
      this->lastNameTextBox = (gcnew System::Windows::Forms::TextBox());
      this->emailTextBox = (gcnew System::Windows::Forms::TextBox());
      this->streetAddressTextBox = (gcnew System::Windows::Forms::TextBox());
      this->label5 = (gcnew System::Windows::Forms::Label());
      this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
      this->zipCodeTextBox = (gcnew System::Windows::Forms::TextBox());
      this->label9 = (gcnew System::Windows::Forms::Label());
      this->stateTextBox = (gcnew System::Windows::Forms::TextBox());
      this->label8 = (gcnew System::Windows::Forms::Label());
      this->countryTextBox = (gcnew System::Windows::Forms::TextBox());
      this->label7 = (gcnew System::Windows::Forms::Label());
      this->cityTextBox = (gcnew System::Windows::Forms::TextBox());
      this->label6 = (gcnew System::Windows::Forms::Label());
      this->phoneTextBox = (gcnew System::Windows::Forms::TextBox());
      this->label10 = (gcnew System::Windows::Forms::Label());
      this->notesTextBox = (gcnew System::Windows::Forms::TextBox());
      this->label11 = (gcnew System::Windows::Forms::Label());
      this->saveButton = (gcnew System::Windows::Forms::Button());
      this->cancelButton = (gcnew System::Windows::Forms::Button());
      this->groupBox1->SuspendLayout();
      this->SuspendLayout();
      // 
      // label1
      // 
      this->label1->AutoSize = true;
      this->label1->Location = System::Drawing::Point(25, 30);
      this->label1->Name = L"label1";
      this->label1->Size = System::Drawing::Size(76, 17);
      this->label1->TabIndex = 0;
      this->label1->Text = L"First Name";
      // 
      // label2
      // 
      this->label2->AutoSize = true;
      this->label2->Location = System::Drawing::Point(25, 57);
      this->label2->Name = L"label2";
      this->label2->Size = System::Drawing::Size(76, 17);
      this->label2->TabIndex = 1;
      this->label2->Text = L"Last Name";
      this->label2->Click += gcnew System::EventHandler(this, &AddContactForm::label2_Click);
      // 
      // label3
      // 
      this->label3->AutoSize = true;
      this->label3->Location = System::Drawing::Point(25, 292);
      this->label3->Name = L"label3";
      this->label3->Size = System::Drawing::Size(42, 17);
      this->label3->TabIndex = 2;
      this->label3->Text = L"Email";
      // 
      // label4
      // 
      this->label4->AutoSize = true;
      this->label4->Location = System::Drawing::Point(147, 124);
      this->label4->Name = L"label4";
      this->label4->Size = System::Drawing::Size(0, 17);
      this->label4->TabIndex = 3;
      // 
      // firstNameTextBox
      // 
      this->firstNameTextBox->Location = System::Drawing::Point(119, 27);
      this->firstNameTextBox->Name = L"firstNameTextBox";
      this->firstNameTextBox->Size = System::Drawing::Size(220, 22);
      this->firstNameTextBox->TabIndex = 0;
      // 
      // lastNameTextBox
      // 
      this->lastNameTextBox->Location = System::Drawing::Point(119, 57);
      this->lastNameTextBox->Name = L"lastNameTextBox";
      this->lastNameTextBox->Size = System::Drawing::Size(220, 22);
      this->lastNameTextBox->TabIndex = 1;
      // 
      // emailTextBox
      // 
      this->emailTextBox->Location = System::Drawing::Point(119, 292);
      this->emailTextBox->Name = L"emailTextBox";
      this->emailTextBox->Size = System::Drawing::Size(220, 22);
      this->emailTextBox->TabIndex = 8;
      // 
      // streetAddressTextBox
      // 
      this->streetAddressTextBox->Location = System::Drawing::Point(142, 28);
      this->streetAddressTextBox->Name = L"streetAddressTextBox";
      this->streetAddressTextBox->Size = System::Drawing::Size(220, 22);
      this->streetAddressTextBox->TabIndex = 3;
      // 
      // label5
      // 
      this->label5->AutoSize = true;
      this->label5->Location = System::Drawing::Point(14, 31);
      this->label5->Name = L"label5";
      this->label5->Size = System::Drawing::Size(102, 17);
      this->label5->TabIndex = 7;
      this->label5->Text = L"Street Address";
      // 
      // groupBox1
      // 
      this->groupBox1->Controls->Add(this->zipCodeTextBox);
      this->groupBox1->Controls->Add(this->label9);
      this->groupBox1->Controls->Add(this->stateTextBox);
      this->groupBox1->Controls->Add(this->label8);
      this->groupBox1->Controls->Add(this->countryTextBox);
      this->groupBox1->Controls->Add(this->label7);
      this->groupBox1->Controls->Add(this->cityTextBox);
      this->groupBox1->Controls->Add(this->label6);
      this->groupBox1->Controls->Add(this->streetAddressTextBox);
      this->groupBox1->Controls->Add(this->label5);
      this->groupBox1->Location = System::Drawing::Point(28, 96);
      this->groupBox1->Name = L"groupBox1";
      this->groupBox1->Size = System::Drawing::Size(377, 176);
      this->groupBox1->TabIndex = 2;
      this->groupBox1->TabStop = false;
      this->groupBox1->Text = L"Address";
      // 
      // zipCodeTextBox
      // 
      this->zipCodeTextBox->Location = System::Drawing::Point(142, 139);
      this->zipCodeTextBox->Name = L"zipCodeTextBox";
      this->zipCodeTextBox->Size = System::Drawing::Size(220, 22);
      this->zipCodeTextBox->TabIndex = 7;
      // 
      // label9
      // 
      this->label9->AutoSize = true;
      this->label9->Location = System::Drawing::Point(14, 142);
      this->label9->Name = L"label9";
      this->label9->Size = System::Drawing::Size(65, 17);
      this->label9->TabIndex = 15;
      this->label9->Text = L"Zip Code";
      // 
      // stateTextBox
      // 
      this->stateTextBox->Location = System::Drawing::Point(142, 111);
      this->stateTextBox->Name = L"stateTextBox";
      this->stateTextBox->Size = System::Drawing::Size(220, 22);
      this->stateTextBox->TabIndex = 6;
      // 
      // label8
      // 
      this->label8->AutoSize = true;
      this->label8->Location = System::Drawing::Point(14, 114);
      this->label8->Name = L"label8";
      this->label8->Size = System::Drawing::Size(41, 17);
      this->label8->TabIndex = 13;
      this->label8->Text = L"State";
      // 
      // countryTextBox
      // 
      this->countryTextBox->Location = System::Drawing::Point(142, 83);
      this->countryTextBox->Name = L"countryTextBox";
      this->countryTextBox->Size = System::Drawing::Size(220, 22);
      this->countryTextBox->TabIndex = 5;
      // 
      // label7
      // 
      this->label7->AutoSize = true;
      this->label7->Location = System::Drawing::Point(14, 86);
      this->label7->Name = L"label7";
      this->label7->Size = System::Drawing::Size(52, 17);
      this->label7->TabIndex = 11;
      this->label7->Text = L"County";
      // 
      // cityTextBox
      // 
      this->cityTextBox->Location = System::Drawing::Point(142, 56);
      this->cityTextBox->Name = L"cityTextBox";
      this->cityTextBox->Size = System::Drawing::Size(220, 22);
      this->cityTextBox->TabIndex = 4;
      this->cityTextBox->TextChanged += gcnew System::EventHandler(this, &AddContactForm::textBox1_TextChanged);
      // 
      // label6
      // 
      this->label6->AutoSize = true;
      this->label6->Location = System::Drawing::Point(14, 59);
      this->label6->Name = L"label6";
      this->label6->Size = System::Drawing::Size(31, 17);
      this->label6->TabIndex = 9;
      this->label6->Text = L"City";
      this->label6->Click += gcnew System::EventHandler(this, &AddContactForm::label6_Click);
      // 
      // phoneTextBox
      // 
      this->phoneTextBox->Location = System::Drawing::Point(119, 320);
      this->phoneTextBox->Name = L"phoneTextBox";
      this->phoneTextBox->Size = System::Drawing::Size(220, 22);
      this->phoneTextBox->TabIndex = 9;
      // 
      // label10
      // 
      this->label10->AutoSize = true;
      this->label10->Location = System::Drawing::Point(25, 320);
      this->label10->Name = L"label10";
      this->label10->Size = System::Drawing::Size(49, 17);
      this->label10->TabIndex = 10;
      this->label10->Text = L"Phone";
      // 
      // notesTextBox
      // 
      this->notesTextBox->Location = System::Drawing::Point(119, 348);
      this->notesTextBox->Multiline = true;
      this->notesTextBox->Name = L"notesTextBox";
      this->notesTextBox->Size = System::Drawing::Size(387, 117);
      this->notesTextBox->TabIndex = 10;
      // 
      // label11
      // 
      this->label11->AutoSize = true;
      this->label11->Location = System::Drawing::Point(25, 348);
      this->label11->Name = L"label11";
      this->label11->Size = System::Drawing::Size(45, 17);
      this->label11->TabIndex = 12;
      this->label11->Text = L"Notes";
      // 
      // saveButton
      // 
      this->saveButton->Location = System::Drawing::Point(25, 491);
      this->saveButton->Name = L"saveButton";
      this->saveButton->Size = System::Drawing::Size(100, 31);
      this->saveButton->TabIndex = 11;
      this->saveButton->Text = L"Add";
      this->saveButton->UseVisualStyleBackColor = true;
      this->saveButton->Click += gcnew System::EventHandler(this, &AddContactForm::saveButton_Click);
      // 
      // cancelButton
      // 
      this->cancelButton->Location = System::Drawing::Point(406, 491);
      this->cancelButton->Name = L"cancelButton";
      this->cancelButton->Size = System::Drawing::Size(100, 31);
      this->cancelButton->TabIndex = 12;
      this->cancelButton->Text = L"Cancel";
      this->cancelButton->UseVisualStyleBackColor = true;
      this->cancelButton->Click += gcnew System::EventHandler(this, &AddContactForm::cancelButton_Click);
      // 
      // AddContactForm
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(534, 548);
      this->Controls->Add(this->cancelButton);
      this->Controls->Add(this->saveButton);
      this->Controls->Add(this->notesTextBox);
      this->Controls->Add(this->label11);
      this->Controls->Add(this->phoneTextBox);
      this->Controls->Add(this->label10);
      this->Controls->Add(this->groupBox1);
      this->Controls->Add(this->emailTextBox);
      this->Controls->Add(this->lastNameTextBox);
      this->Controls->Add(this->firstNameTextBox);
      this->Controls->Add(this->label4);
      this->Controls->Add(this->label3);
      this->Controls->Add(this->label2);
      this->Controls->Add(this->label1);
      this->Name = L"AddContactForm";
      this->Text = L"Add Contact";
      this->Load += gcnew System::EventHandler(this, &AddContactForm::AddContactForm_Load);
      this->groupBox1->ResumeLayout(false);
      this->groupBox1->PerformLayout();
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
           }
  private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
           }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
           }
private: System::Void AddContactForm_Load(System::Object^  sender, System::EventArgs^  e) {
         }
private: System::Void saveButton_Click(System::Object^  sender, System::EventArgs^  e) {
    Person p;
    p.setFirstName(trimWindowsString(firstNameTextBox->Text));
    p.setLastName(trimWindowsString(lastNameTextBox->Text));
    p.setStreetAddress(trimWindowsString(streetAddressTextBox->Text));
    p.setCity(trimWindowsString(cityTextBox->Text));
    p.setCountry(trimWindowsString(countryTextBox->Text));
    p.setState(trimWindowsString(stateTextBox->Text));
    p.setZip(trimWindowsString(zipCodeTextBox->Text));
    p.setEmail(trimWindowsString(emailTextBox->Text));
    p.setPhone(trimWindowsString(phoneTextBox->Text));
    p.setNotes(trimWindowsString(notesTextBox->Text));

    string validationError;
    if (!p.isValid(validationError)) {
      MessageBox::Show(
          toWindowsString("Cannot add contact: " + validationError),
          L"Invalid contact information",
          MessageBoxButtons::OK, 
          MessageBoxIcon::Error);
      return;
    }

    if (contactList->firstLastNameExist(p.getFirstName(), p.getLastName())) {
      MessageBox::Show(
          toWindowsString("Cannot add contact: first/last name combination '" + 
              p.getFirstName() + " " + p.getLastName() + "' already exists"),
          L"Duplicate name",
          MessageBoxButtons::OK, 
          MessageBoxIcon::Error);
      return;
    }

    contactList->addContact(p);
    contactListView->Items->Add(createListViewItemForPerson(p));
    Close();
  };

  private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
    Close();
  }

};

};
