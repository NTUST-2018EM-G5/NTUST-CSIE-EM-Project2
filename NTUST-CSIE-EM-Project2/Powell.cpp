#include "Powell.h"



Powell::Powell()
{
}

Powell::Powell(MyEquation equation, vector<Variable> variable)
{
	this->equation = equation;
	this->variable = variable;
}

System::String^ Powell::getResult()
{
	//以下是測試輸出用，可以更改
	System::String^ result = "";
	double r = 0;
	if (variable.size() == 1)
	{
		//r = this->equation.calc(variable.at(0).init, 0);
	}
	else if (variable.size() == 2)
	{
		//r = this->equation.calc(variable.at(0).init, variable.at(1).init);
	}
	result = r.ToString();
	return result;
}