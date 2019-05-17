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
		double alpha, slope, gradient, hessian, hessian_inverse, deltaX, xpre;
		double x = variable.at(0).init;
		int k=0;
		do
		{
			gradient = this->equation.df_dx(x);
			hessian = this->equation.ddf_dxdx(x);
			hessian_inverse = 1 / hessian;
			alpha = gradient * hessian_inverse;

			xpre = x;
			x = x + alpha;
			//OUTPUT
			result += "i=" + k + Environment::NewLine;
			result += "Hessian=[" + hessian + "]" + Environment::NewLine;
			result += "HessianInverse=[" + hessian_inverse + "]" + Environment::NewLine;
			result += ConvertToString(this->variable.at(0).name) + "=[" + x + "]" + Environment::NewLine;
			//------
			k++;
		} while (k < MAX_TIME || (this->equation.calc(x, 0) < this->equation.calc(xpre, 0) && abs(gradient) < ZERO));
		
		//OUTPUT
		result += "[" + ConvertToString(this->variable.at(0).name) + "]=[" + x + "]" + Environment::NewLine;
		result += "min=[" + this->equation.calc(x, 0) + "]" + Environment::NewLine;
		//------
	}
	else if (variable.size() == 2) //雙變數
	{
	}
	return result;
}

void Newton::getHessian()
{
	


}