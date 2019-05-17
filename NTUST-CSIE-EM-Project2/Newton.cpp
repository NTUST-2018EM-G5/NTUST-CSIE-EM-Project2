#include "Newton.h"
#define ZERO 0.0000001


Newton::Newton()
{
}

Newton::Newton(MyEquation equation, vector<Variable> variable)
{
	this->equation = equation;
	this->variable = variable;
}

System::String^ Newton::getResult()
{
	System::String^ result = "";
	if (variable.size() == 1) //單變數
	{
		double gradient, hessian, hessian_inverse, deltaX, preX;
		double initX = variable.at(0).init;
		double x = initX;
		int k = 1;
		while (1)
		{
			gradient = this->equation.df_dx(x);
			hessian = this->equation.ddf_dxdx(x);
			hessian += 0.1;
			hessian_inverse = 1 / hessian;
			deltaX = -gradient * hessian_inverse;
			preX = x;
			x = x + deltaX;
			//OUTPUT
			result += "i=" + k + Environment::NewLine;
			result += "Hessian = [" + hessian.ToString("0.##########") + "]" + Environment::NewLine;
			result += "HessianInverse = [" + hessian_inverse.ToString("0.##########") + "]" + Environment::NewLine;
			result += ConvertToString(this->variable.at(0).name) + "=[" + x.ToString("0.##########") + "]" + Environment::NewLine + Environment::NewLine;
			//------
			k++;
			if (k > MAX_TIME || (this->equation.calc(x, 0) >= this->equation.calc(preX, 0) && abs(gradient) < ZERO)) break;
		}
		//OUTPUT
		result += "[" + ConvertToString(this->variable.at(0).name) + "] = [" + x.ToString("0.##########") + "]" + Environment::NewLine;
		result += "min = [" + this->equation.calc(x, 0).ToString("0.##########") + "]" + Environment::NewLine;
		result += "-done-" + Environment::NewLine + Environment::NewLine;
		//------
	}
	else if (variable.size() == 2) //雙變數
	{
		double gradient, hessian, hessian_inverse, deltaX, preX;
		double initX = variable.at(0).init;
		double initY = variable.at(1).init;
		double x = initX;
		double y = initY;
		int k = 1;
		while (1)
		{
			gradient = this->equation.df_dx(x);
			hessian = this->equation.ddf_dxdx(x);
			hessian += 0.1;
			hessian_inverse = 1 / hessian;
			deltaX = -gradient * hessian_inverse;
			preX = x;
			x = x + deltaX;
			//OUTPUT
			result += "i=" + k + Environment::NewLine;
			result += "Hessian = [" + hessian.ToString("0.##########") + "]" + Environment::NewLine;
			result += "HessianInverse = [" + hessian_inverse.ToString("0.##########") + "]" + Environment::NewLine;
			result += ConvertToString(this->variable.at(0).name) + "=[" + x.ToString("0.##########") + "]" + Environment::NewLine + Environment::NewLine;
			//------
			k++;
			if (k > MAX_TIME || (this->equation.calc(x, 0) >= this->equation.calc(preX, 0) && abs(gradient) < ZERO)) break;
		}
		//OUTPUT
		result += "[" + ConvertToString(this->variable.at(0).name) + "] = [" + x.ToString("0.##########") + "]" + Environment::NewLine;
		result += "min = [" + this->equation.calc(x, 0).ToString("0.##########") + "]" + Environment::NewLine;
		result += "-done-" + Environment::NewLine + Environment::NewLine;
		//------
	}
	return result;
}

void Newton::getHessian()
{
	


}