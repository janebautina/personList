// WinQuickSoft.cpp : main project file.

#include "stdafx.h"
#include "MainWindowForm.h"

using namespace WinQuickSoft;

static const bool ENABLE_CONSOLE = false;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{

  if (ENABLE_CONSOLE) {
    // Enable console:
    // http://stackoverflow.com/questions/11322726/how-to-write-to-console-log-in-vc-in-a-metro-app
    AllocConsole();
    freopen("CONOUT$", "w+t", stdout);
  }

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew MainWindowForm());
	return 0;
}
