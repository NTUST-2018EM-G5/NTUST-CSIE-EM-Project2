#include "QuasiNewton.h"



QuasiNewton::QuasiNewton()
{
}

QuasiNewton::QuasiNewton(MyEquation equation, vector<Variable> variable)
{
	this->equation = equation;
	this->variable = variable;
}

System::String^ QuasiNewton::getResult()
{
	System::String^ result = "";

	return result;
}