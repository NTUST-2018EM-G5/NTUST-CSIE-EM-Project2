#include "EditFuncForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void EditFuncForm(cli::array<String^ > ^ args)
{
	//Application::EnableVisualStyles();
	//Application::SetCompatibleTextRenderingDefault(false);
	NTUSTCSIEEMProject2::EditFuncForm form;
	Application::Run(%form);
}