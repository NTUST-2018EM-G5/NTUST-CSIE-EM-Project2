#include<iostream>
#include<string>


void MarshalString(System::String^ s, std::string& os);
std::string ToString_Sys2Std(System::String^ s);
std::wstring MQString2wstring(System::String^ IString);

//System::String^ �ন std::string
std::string ConvertToString(System::String^ s);

//std::string �ন System::String^
System::String^ ConvertToString(std::string s);
