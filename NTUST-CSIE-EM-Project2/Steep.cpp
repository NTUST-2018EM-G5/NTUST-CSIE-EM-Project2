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
	if (variable.size() == 1) //虫跑计
	{
		double gradient[2], hessian[2][2], lambda;
		double x = variable.at(0).init;
		double y = 0;
		int i = 1;
		while (1)
		{
			//gradient
			gradient[0] = -this->equation.f_x(x, y);
			gradient[1] = -this->equation.f_y(x, y);

			//Step 1
			if (abs(gradient[0]) < ZERO) break;

			//Step 2
			//hessian matrix
			hessian[0][0] = this->equation.f_xx(x, y);
			hessian[0][1] = this->equation.f_xy(x, y);
			hessian[1][0] = this->equation.f_xy(x, y);
			hessian[1][1] = this->equation.f_yy(x, y);

			//lambda
			double temp[2] = { gradient[0] * hessian[0][0] + gradient[1] * hessian[1][0] , gradient[0] * hessian[1][0] + gradient[1] * hessian[1][1] };
			lambda = (gradient[0] * gradient[0] + gradient[1] * gradient[1]) / (temp[0] * gradient[0] + temp[1] * gradient[1]);
			

			//Step 3
			double test = x + lambda * gradient[0];
			//耞琌獶计
			while (this->equation.calc(test, 0) != this->equation.calc(test, 0) || test > this->variable.at(0).end || test < this->variable.at(0).begin) 
			{
				lambda *= 0.9;
				test = x + lambda * gradient[0];
			}
			x = test;

			if (abs(x) < ZERO) x = 0;

			//OUTPUT
			result += "i=" + i + Environment::NewLine;
			result += "h = [" + gradient[0].ToString("0.##########") + "]" + Environment::NewLine;
			result += "Lambda = [" + lambda.ToString("0.##########") + "]" + Environment::NewLine;
			result += ConvertToString(this->variable.at(0).name) + " = [" + x.ToString("0.##########") + "]" + Environment::NewLine + Environment::NewLine;
			//------
			i++;
			if (i > MAX_TIME) break;
		}
		//OUTPUT
		result += "[" + ConvertToString(this->variable.at(0).name) + "] = [" + x.ToString("0.##########") + "]" + Environment::NewLine;
		result += "min = [" + this->equation.calc(x, 0).ToString("0.##########") + "]" + Environment::NewLine;
		result += "-done-" + Environment::NewLine + Environment::NewLine;
		//------
	}
	else if (variable.size() == 2) //虫跑计
	{
		double gradient[2], hessian[2][2], lambda;
		double x = variable.at(0).init;
		double y = variable.at(1).init;
		int i = 1;
		while (1)
		{
			//gradient
			gradient[0] = -this->equation.f_x(x, y);
			gradient[1] = -this->equation.f_y(x, y);

			//Step 1
			if (abs(gradient[0]) < ZERO && abs(gradient[1]) < ZERO) break;

			//Step 2
			//hessian matrix
			hessian[0][0] = this->equation.f_xx(x, y);
			hessian[0][1] = this->equation.f_xy(x, y);
			hessian[1][0] = this->equation.f_xy(x, y);
			hessian[1][1] = this->equation.f_yy(x, y);

			//lambda
			double temp[2] = { gradient[0] * hessian[0][0] + gradient[1] * hessian[1][0] , gradient[0] * hessian[1][0] + gradient[1] * hessian[1][1] };
			lambda = (gradient[0] * gradient[0] + gradient[1] * gradient[1]) / (temp[0] * gradient[0] + temp[1] * gradient[1]);
			
			//Step 3
			double test[2] = { x + lambda * gradient[0] , y + lambda * gradient[1] };
			//耞琌獶计
			while (this->equation.calc(test[0], test[1]) != this->equation.calc(test[0], test[1]) || test[0] > this->variable.at(0).end || test[0] < this->variable.at(0).begin
				|| test[1] > this->variable.at(1).end || test[1] < this->variable.at(1).begin )
			{
				lambda *= 0.9;
				test[0] = x + lambda * gradient[0];
				test[1] = y + lambda * gradient[1];
			}
			x = test[0];
			y = test[1];

			if (abs(x) < ZERO) x = 0;
			if (abs(y) < ZERO) y = 0;

			//OUTPUT
			result += "i=" + i + Environment::NewLine;
			result += "h = [" + gradient[0].ToString("0.##########") + " , " + gradient[1].ToString("0.##########") + "]" + Environment::NewLine;
			result += "Lambda = [" + lambda.ToString("0.##########") + "]" + Environment::NewLine;
			result += ConvertToString(this->variable.at(0).name) + " = [" + x.ToString("0.##########") + "]" + Environment::NewLine;
			result += ConvertToString(this->variable.at(1).name) + " = [" + y.ToString("0.##########") + "]" + Environment::NewLine + Environment::NewLine;
			//------
			i++;
			if (i > MAX_TIME) break;
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