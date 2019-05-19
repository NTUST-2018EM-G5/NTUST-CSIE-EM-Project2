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
	if (variable.size() == 1) //單變數
	{
		double gradient, hessian, hessian_inverse, deltaX, preX;
		double h, lambda = 0.9, step = 1;
		double x = variable.at(0).init;
		int i = 0; //Step 0: set i=0
		while (1)
		{

			/*可行的方法
			preX = x;
			gradient = -this->equation.df_dx(x);
			x = x + (1 - lambda) * gradient;
			if (x < this->variable.at(0).begin) x = this->variable.at(0).begin;
			if (x > this->variable.at(0).end) x = this->variable.at(0).end;*/

			/*
			//Step 1
			deltaX = this->equation.df_dx(x); //compute search direction
			if (i != 0 && abs(deltaX) < ZERO) break; //stop
			h = -deltaX;

			//Step 2 : compute the step-size
			hessian = this->equation.ddf_dxdx(x);
			hessian_inverse = 1 / hessian;
			lambda = hessian * hessian * hessian_inverse;

			double tryValue = x + lambda * h;
			while (tryValue < this->variable.at(0).begin || tryValue > this->variable.at(0).end)
			{
				lambda *= 0.9;
				tryValue = x + lambda * h;
			}

			//Step 3
			x = tryValue;
			*/

			//Step 1
			gradient = -this->equation.df_dx(x);
			if (abs(gradient) < ZERO)
			{
				break;
			}
			
			//Step 2


			//Step 3
			lambda = gradient * gradient;
			
			//OUTPUT
			result += "i=" + i + Environment::NewLine;
			result += "h = [" + h.ToString("0.##########") + "]" + Environment::NewLine;
			result += "Lambda = [" + lambda.ToString("0.##########") + "]" + Environment::NewLine;
			result += ConvertToString(this->variable.at(0).name) + " = [" + x.ToString("0.##########") + "]" + Environment::NewLine + Environment::NewLine;
			//------
			i++;
			if (i >= MAX_TIME || abs(preX - x) < ZERO && abs(gradient) < ZERO) break;
		}
		//OUTPUT
		result += "[" + ConvertToString(this->variable.at(0).name) + "] = [" + x.ToString("0.##########") + "]" + Environment::NewLine;
		result += "min = [" + this->equation.calc(x, 0).ToString("0.##########") + "]" + Environment::NewLine;
		result += "-done-" + Environment::NewLine + Environment::NewLine;
		//------
	}
	else if (variable.size() == 2) //雙變數
	{
		
	}
	return result;
}