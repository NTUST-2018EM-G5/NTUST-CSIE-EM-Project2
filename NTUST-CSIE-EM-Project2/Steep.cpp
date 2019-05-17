#include "Steep.h"



Steep::Steep()
{
}

Steep::Steep(MyEquation equation, vector<Variable> variable)
{
	this->equation = equation;
	this->variable = variable;
}

System::String^ Steep::getResult()
{
	System::String^ result = "";
	
	return result;
}