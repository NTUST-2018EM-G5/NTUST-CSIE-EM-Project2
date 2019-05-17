#include "Powell.h"
#include<cmath>
#include"DotNetUitilities.h"
#include<sstream>
Powell::Powell()
{
}

Powell::Powell(MyEquation equation, vector<Variable> variable)
{
	this->equation = equation;
	this->variable = variable;
}

double phi = (1 + sqrt(5)) / 2;
double resphi = 2 - phi;

double Powell::golden_section(double a, double b, double c)
{
	double tau = 0.00000001;
	double x;
	if (c - b > b - a)
	{
		x = b + resphi * (c - b);
	}
	else
	{
		x = b - resphi * (b - a);
	}
	if (abs(c - a) < tau * (abs(b) + abs(x)))
	{
		return (c + a) / 2;
	}
	if (this->equation.calc(x,0) < this->equation.calc(b,0))
	{
		if (c - b > b - a)
		{
			return golden_section(b, x, c);
		}
		else
		{
			return golden_section(a, x, b);
		}
	}
	else
	{
		if (c - b > b - a)
		{
			return golden_section(a, b, x);
		}
		else
		{
			return golden_section(x, b, c);
		}
	}
}

System::String^ Powell::getResult()
{
	//以下是測試輸出用，可以更改
	System::String^ result = "";
	string temp;
	double r = 0;
	double r2 = 0;
	if (variable.size() == 1)
	{
		r = golden_section(this->variable[0].begin, this->variable[0].init, this->variable[0].end);
		r2 = this->equation.calc(r, 0);
		ostringstream strs, strs2;
		strs << r;
		strs2 << r2;
		temp = "[" + this->variable[0].name + "] = " + "[" + strs.str()  + "]" + "\r\n" + "min = " + strs2.str() + "\r\n";
		result = ConvertToString(temp);
	}
	else if (variable.size() == 2)
	{
		//r = this->equation.calc(variable.at(0).init, variable.at(1).init);
	}
	
	return result;
}