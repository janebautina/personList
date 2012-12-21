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
	/// Summary for FindContactsForm
	/// </summary>
	public ref class FindContactsForm : public System::Windows::Forms::Form
	{
	public:
		FindContactsForm(ContactList* _contactList, SearchField _searchField, bool _deletionEnabled)
		{
      InitializeComponent();
			contactList = _contactList;
      searchField = _searchField;
      searchFieldName = toWindowsString(getSearchFieldName(_searchField));
      this->label1->Text += " " + searchFieldName;
      this->Text += " " + searchFieldName;
      deletionEnabled = _deletionEnabled;
      if (!deletionEnabled) {
        this->deleteContactButton->Hide();
      }
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FindContactsForm()
		{
			if (components)
			{
				delete components;
			}
		}
  private: ContactList* contactList;
  private: SearchField searchField;
  private: String^ searchFieldName;
  private: bool deletionEnabled;
  private: System::Windows::Forms::Button^  searchButton;
          
  protected: 
  private: System::Windows::Forms::Label^  label1;
  private: System::Windows::Forms::TextBox^  textBox1;
  private: System::Windows::Forms::ListView^  listView1;
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
  private: System::Windows::Forms::Button^  closeButton;
  private: System::Windows::Forms::Button^  deleteContactButton;

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
      this->searchButton = (gcnew System::Windows::Forms::Button());
      this->label1 = (gcnew System::Windows::Forms::Label());
      this->textBox1 = (gcnew System::Windows::Forms::TextBox());
      this->listView1 = (gcnew System::Windows::Forms::ListView());
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
      this->closeButton = (gcnew System::Windows::Forms::Button());
      this->deleteContactButton = (gcnew System::Windows::Forms::Button());
      this->SuspendLayout();
      // 
      // searchButton
      // 
      this->searchButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->searchButton->Location = System::Drawing::Point(598, 21);
      this->searchButton->Name = L"searchButton";
      this->searchButton->Size = System::Drawing::Size(126, 29);
      this->searchButton->TabIndex = 0;
      this->searchButton->Text = L"Search";
      this->searchButton->UseVisualStyleBackColor = true;
      this->searchButton->Click += gcnew System::EventHandler(this, &FindContactsForm::searchButton_Click);
      // 
      // label1
      // 
      this->label1->AutoSize = true;
      this->label1->Location = System::Drawing::Point(24, 27);
      this->label1->Name = L"label1";
      this->label1->Size = System::Drawing::Size(111, 17);
      this->label1->TabIndex = 1;
      this->label1->Text = L"Find contacts by";
      // 
      // textBox1
      // 
      this->textBox1->AcceptsReturn = true;
      this->textBox1->Location = System::Drawing::Point(235, 24);
      this->textBox1->Name = L"textBox1";
      this->textBox1->Size = System::Drawing::Size(346, 22);
      this->textBox1->TabIndex = 2;
      // 
      // listView1
      // 
      this->listView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
        | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right));
      this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(10) {this->columnHeader1, this->columnHeader2, 
        this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6, this->columnHeader7, this->columnHeader8, 
        this->columnHeader9, this->columnHeader10});
      this->listView1->Location = System::Drawing::Point(27, 73);
      this->listView1->Name = L"listView1";
      this->listView1->Size = System::Drawing::Size(697, 383);
      this->listView1->TabIndex = 71;
      this->listView1->UseCompatibleStateImageBehavior = false;
      this->listView1->View = System::Windows::Forms::View::Details;
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
      // closeButton
      // 
      this->closeButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
      this->closeButton->Location = System::Drawing::Point(598, 472);
      this->closeButton->Name = L"closeButton";
      this->closeButton->Size = System::Drawing::Size(126, 29);
      this->closeButton->TabIndex = 72;
      this->closeButton->Text = L"Close";
      this->closeButton->UseVisualStyleBackColor = true;
      this->closeButton->Click += gcnew System::EventHandler(this, &FindContactsForm::closeButton_Click);
      // 
      // deleteContactButton
      // 
      this->deleteContactButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
      this->deleteContactButton->Enabled = false;
      this->deleteContactButton->Location = System::Drawing::Point(27, 472);
      this->deleteContactButton->Name = L"deleteContactButton";
      this->deleteContactButton->Size = System::Drawing::Size(202, 29);
      this->deleteContactButton->TabIndex = 73;
      this->deleteContactButton->Text = L"Delete selected contacts";
      this->deleteContactButton->UseVisualStyleBackColor = true;
      this->deleteContactButton->Click += gcnew System::EventHandler(this, &FindContactsForm::deleteContactButton_Click);
      // 
      // FindContactsForm
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(748, 517);
      this->Controls->Add(this->deleteContactButton);
      this->Controls->Add(this->closeButton);
      this->Controls->Add(this->listView1);
      this->Controls->Add(this->textBox1);
      this->Controls->Add(this->label1);
      this->Controls->Add(this->searchButton);
      this->Name = L"FindContactsForm";
      this->Text = L"Contact search by";
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: System::Void searchButton_Click(System::Object^  sender, System::EventArgs^  e) {
    string enteredText(trimWindowsString(textBox1->Text));
    if (enteredText.empty()) {
      MessageBox::Show(
          L"Please enter the value of " + searchFieldName,
          L"Invalid input",
          MessageBoxButtons::OK, 
          MessageBoxIcon::Error);
      return;
    }
    vector<Person> searchResults;
    contactList->findByField(&searchResults, searchField, enteredText);
    if (searchResults.empty()) {
      MessageBox::Show(
          L"No contacts found with " + searchFieldName + " of " + textBox1->Text,
          L"No results found",
          MessageBoxButtons::OK, 
          MessageBoxIcon::Error);
      return;
    }
    listView1->Items->Clear();
    for (vector<Person>::iterator iter = searchResults.begin();
        iter != searchResults.end();
        ++iter) {
      listView1->Items->Add(createListViewItemForPerson(*iter));
    }
    if (deletionEnabled) {
      deleteContactButton->Enabled = true;
    }
  }

private: System::Void closeButton_Click(System::Object^  sender, System::EventArgs^  e) {
           Close();
         }
private: System::Void deleteContactButton_Click(System::Object^  sender, System::EventArgs^  e) {
           int toDeleteIndex;
           if (listView1->Items->Count == 1) {
             toDeleteIndex = 0;
           } else if (listView1->SelectedIndices->Count == 1) {
             toDeleteIndex = listView1->SelectedIndices[0];
           } else {
             MessageBox::Show(
                 L"Please select exactly one contact to delete",
                 L"Invalid selection",
                 MessageBoxButtons::OK, 
                 MessageBoxIcon::Error);
             return;
           }

           string firstName = trimWindowsString(listView1->Items[toDeleteIndex]->SubItems[0]->Text);
           string lastName = trimWindowsString(listView1->Items[toDeleteIndex]->SubItems[1]->Text);
           if (MessageBox::Show(L"Do you want to delete the contact with first name " + 
               toWindowsString(firstName) + " and last name " + toWindowsString(lastName) + "?",
               L"Deletion confirmation",
               MessageBoxButtons::YesNo,
               MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
             contactList->deleteContactByFirstAndLastName(firstName, lastName);
             listView1->Items->Remove(listView1->Items[toDeleteIndex]);
           }
         }
};
}
