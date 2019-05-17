#include "Conjugate.h"



Conjugate::Conjugate()
{
}

Conjugate::Conjugate(MyEquation equation, vector<Variable> variable)
{
	this->equation = equation;
	this->variable = variable;
}

System::String^ Conjugate::getResult()
{
	System::String^ result = "";

	return result;
}
