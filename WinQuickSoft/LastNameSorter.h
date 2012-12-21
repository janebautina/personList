#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;

namespace WinQuickSoft {

  enum {
    LAST_NAME_COLUMN = 1
  };

  ref class LastNameComparer : public IComparer
  {
  private:
    virtual int Compare( Object^ x, Object^ y ) sealed = IComparer::Compare
    {
      return ((gcnew CaseInsensitiveComparer)->Compare( 
        (dynamic_cast<ListViewItem^>(x))->SubItems[LAST_NAME_COLUMN]->Text,
        (dynamic_cast<ListViewItem^>(y))->SubItems[LAST_NAME_COLUMN]->Text
      ));
    }
  };

}