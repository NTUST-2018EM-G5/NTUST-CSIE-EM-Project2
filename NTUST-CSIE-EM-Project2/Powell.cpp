#include "Powell.h"



Powell::Powell()
{
}

Powell::Powell(MyEquation equation, vector<Variable> variable)
{
	this->equation = equation;
	this->variable = variable;
}

string Powell::getResult()
{
	//�H�U�O���տ�X�ΡA�i�H���
	string result = "";
	stringstream sstream;
	double r = 0;
	if (variable.size() == 1)
	{
		//r = this->equation.calc(variable.at(0).init, 0);
	}
	else if (variable.size() == 2)
	{
		//r = this->equation.calc(variable.at(0).init, variable.at(1).init);
	}
	sstream << r;
	sstream >> result;
	return result;
}