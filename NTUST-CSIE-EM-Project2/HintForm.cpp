#include "HintForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void HintForm(cli::array<String^ > ^ args)
{
	//Application::EnableVisualStyles();
	//Application::SetCompatibleTextRenderingDefault(false);
	NTUSTCSIEEMProject2::HintForm form;
	Application::Run(%form);
}