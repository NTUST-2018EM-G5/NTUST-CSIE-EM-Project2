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
		double x = variable.at(0).init;
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
			result += ConvertToString(this->variable.at(0).name) + " = [" + x.ToString("0.##########") + "]" + Environment::NewLine + Environment::NewLine;
			//------
			k++;
			if (k > MAX_TIME || (this->equation.calc(x, 0) < this->equation.calc(preX, 0) && abs(gradient) < ZERO)) break;
		}
		//OUTPUT
		result += "[" + ConvertToString(this->variable.at(0).name) + "] = [" + x.ToString("0.##########") + "]" + Environment::NewLine;
		result += "min = [" + this->equation.calc(x, 0).ToString("0.##########") + "]" + Environment::NewLine;
		result += "-done-" + Environment::NewLine + Environment::NewLine;
		//------
	}
	else if (variable.size() == 2) //雙變數
	{
		double gradient[2], pre[2], delta[2], hessian[2][2], hessian_inverse[2][2];
		double initX = variable.at(0).init;
		double initY = variable.at(1).init;
		double x = initX;
		double y = initY;
		double A;
		int k = 1;
		while (1)
		{
			//gradient
			gradient[0] = this->equation.f_x(x, y);
			gradient[1] = this->equation.f_y(x, y);
			//hessian matrix
			hessian[0][0] = this->equation.f_xx(x, y);
			hessian[0][1] = this->equation.f_xy(x, y);
			hessian[1][0] = this->equation.f_xy(x, y);
			hessian[1][1] = this->equation.f_yy(x, y);
			//hessian matrix inverse
			A = hessian[0][0] * hessian[1][1] - hessian[0][1] * hessian[1][0]; //|A| = ad-bc
			hessian_inverse[0][0] = (1 / A) * hessian[1][1];  //a = |A| * d
			hessian_inverse[0][1] = (1 / A) * -hessian[0][1]; //b = |A| * -b
			hessian_inverse[1][0] = (1 / A) * -hessian[1][0]; //c = |A| * -c
			hessian_inverse[1][1] = (1 / A) * hessian[0][0];  //d = |A| * a
			//x0
			pre[0] = x;
			pre[1] = y;
			//delta
			delta[0] = (-hessian_inverse[0][0]) * gradient[0] + (-hessian_inverse[0][1]) * gradient[1];
			delta[1] = (-hessian_inverse[1][0]) * gradient[0] + (-hessian_inverse[1][1]) * gradient[1];
			//x1
			x = x + delta[0];
			y = y + delta[1];
			if (abs(x) < ZERO) x = 0;
			if (abs(y) < ZERO) y = 0;
			
			//OUTPUT
			result += "i=" + k + Environment::NewLine;
			result += "Hessian = [" + hessian[0][0].ToString("0.##########") + " , " + hessian[0][1].ToString("0.##########") + "]" + Environment::NewLine;
			result += "          [" + hessian[1][0].ToString("0.##########") + " , " + hessian[1][1].ToString("0.##########") + "]" + Environment::NewLine;
			result += "HessianInverse = [" + hessian_inverse[0][0].ToString("0.##########") + " , " + hessian_inverse[0][1].ToString("0.##########") + "]" + Environment::NewLine;
			result += "                 [" + hessian_inverse[1][0].ToString("0.##########") + " , " + hessian_inverse[1][1].ToString("0.##########") + "]" + Environment::NewLine;
			result += ConvertToString(this->variable.at(0).name) + " = [" + x.ToString("0.##########") + "]" + Environment::NewLine;
			result += ConvertToString(this->variable.at(1).name) + " = [" + y.ToString("0.##########") + "]" + Environment::NewLine + Environment::NewLine;
			//------
			k++;
			if (k > MAX_TIME || (this->equation.calc(x, y) < this->equation.calc(pre[0], pre[1]) && abs(gradient[0]) < ZERO && abs(gradient[1]) < ZERO)) break;
		}
		//OUTPUT
		result += "[" + ConvertToString(this->variable.at(0).name) + "] = [" + x.ToString("0.##########") + "]" + Environment::NewLine;
		result += "[" + ConvertToString(this->variable.at(1).name) + "] = [" + y.ToString("0.##########") + "]" + Environment::NewLine;
		result += "min = [" + this->equation.calc(x, y).ToString("0.##########") + "]" + Environment::NewLine;
		result += "-done-" + Environment::NewLine + Environment::NewLine;
		//------
	}
	return result;
}