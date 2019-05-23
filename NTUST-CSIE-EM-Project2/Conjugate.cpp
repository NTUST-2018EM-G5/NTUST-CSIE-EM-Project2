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
	if (variable.size() == 1) //單變數
	{
		double gradient, direction, hessian, alpha, beta, x, y, temp;
		double next, next_gradient;
		x = this->variable.at(0).init;
		y = 0;
		//Step 1-------------------------------------------------
		int i = 0;

		while (1)
		{
			//Step 2-------------------------------------------------
			//gradient
			gradient = this->equation.df_dx(x);

			//direction
			direction = -gradient;

			if (abs(gradient) < ZERO) break;

			//hessian matrix
			hessian = this->equation.ddf_dxdx(x);

			temp = direction * hessian;

			//Step 3-------------------------------------------------
			alpha = -(gradient * direction) / (temp * direction);

			//Step 4-------------------------------------------------
			next = x + alpha * direction;

			//Step 5-------------------------------------------------
			if (next < this->variable.at(0).begin) next = this->variable.at(0).begin + ZERO;
			else if (next > this->variable.at(0).end) next = this->variable.at(0).end - ZERO;

			next_gradient = this->equation.df_dx(next);
			if (abs(next_gradient) < ZERO) break;

			//Step 6-------------------------------------------------
			//hessian matrix
			hessian = this->equation.ddf_dxdx(next);

			temp = direction * hessian;
			beta = -(next_gradient * direction) / (temp * direction);

			//Step 7-------------------------------------------------
			direction = -next_gradient + beta * direction;

			x = next;

			//OUTPUT
			result += "i = " + i + Environment::NewLine;
			result += "Beta = " + beta.ToString("0.##########") + Environment::NewLine;
			result += "Si = [" + direction.ToString("0.##########") + "]" + Environment::NewLine;
			result += "Alpha = " + alpha.ToString("0.##########") + Environment::NewLine;
			result += "Xi = [" + x.ToString("0.##########") + "]" + Environment::NewLine + Environment::NewLine;
			//------

			//Step 8-------------------------------------------------
			i++;

			if (i >= MAX_TIME) break;
		}
		//OUTPUT
		result += "[" + ConvertToString(this->variable.at(0).name) + "] = [" + x.ToString("0.##########") + "]" + Environment::NewLine;
		result += "min = [" + this->equation.calc(x, 0).ToString("0.##########") + "]" + Environment::NewLine;
		result += "-done-" + Environment::NewLine + Environment::NewLine;
		//------
	}
	else if (variable.size() == 2) //雙變數
	{
		double gradient[2], direction[2], hessian[2][2], alpha, beta, x, y, temp[2];
		double next[2], next_gradient[2];
		x = this->variable.at(0).init;
		y = this->variable.at(1).init;
		//Step 1-------------------------------------------------
		int i = 0;

		while (1)
		{
			//Step 2-------------------------------------------------
			//gradient
			gradient[0] = this->equation.f_x(x, y);
			gradient[1] = this->equation.f_y(x, y);

			//direction
			direction[0] = -gradient[0];
			direction[1] = -gradient[1];

			if (abs(gradient[0]) < ZERO && abs(gradient[1]) < ZERO) break;

			//hessian matrix
			hessian[0][0] = this->equation.f_xx(x, y);
			hessian[0][1] = this->equation.f_xy(x, y);
			hessian[1][0] = this->equation.f_xy(x, y);
			hessian[1][1] = this->equation.f_yy(x, y);

			temp[0] = direction[0] * hessian[0][0] + direction[1] * hessian[1][0];
			temp[1] = direction[0] * hessian[0][1] + direction[1] * hessian[1][1];

			//Step 3-------------------------------------------------
			alpha = -(gradient[0] * direction[0] + gradient[1] * direction[1]) / (temp[0] * direction[0] + temp[1] * direction[1]);

			//Step 4-------------------------------------------------
			next[0] = x + alpha * direction[0];
			next[1] = y + alpha * direction[1];

			//Step 5-------------------------------------------------
			next_gradient[0] = this->equation.f_x(next[0], next[1]);
			next_gradient[1] = this->equation.f_y(next[0], next[1]);
			if (abs(next_gradient[0]) < ZERO && abs(next_gradient[1]) < ZERO) break;

			//Step 6-------------------------------------------------
			//hessian matrix
			hessian[0][0] = this->equation.f_xx(next[0], next[1]);
			hessian[0][1] = this->equation.f_xy(next[0], next[1]);
			hessian[1][0] = this->equation.f_xy(next[0], next[1]);
			hessian[1][1] = this->equation.f_yy(next[0], next[1]);

			temp[0] = direction[0] * hessian[0][0] + direction[1] * hessian[1][0];
			temp[1] = direction[0] * hessian[0][1] + direction[1] * hessian[1][1];
			beta = -(next_gradient[0] * direction[0] + next_gradient[1] * direction[1]) / (temp[0] * direction[0] + temp[1] * direction[1]);

			//Step 7-------------------------------------------------
			direction[0] = -gradient[0] + beta * direction[0];
			direction[1] = -gradient[1] + beta * direction[1];

			x = next[0];
			y = next[1];

			//OUTPUT
			result += "i = " + i + Environment::NewLine;
			result += "Beta = " + beta.ToString("0.##########") + Environment::NewLine;
			result += "Si = [" + direction[0].ToString("0.##########") + " , " + direction[1].ToString("0.##########") + "]" + Environment::NewLine;
			result += "Alpha = " + alpha.ToString("0.##########") + Environment::NewLine;
			result += "Xi = [" + x.ToString("0.##########") + " , " + y.ToString("0.##########") + "]" + Environment::NewLine + Environment::NewLine;
			//------

			//Step 8-------------------------------------------------
			i++;

			if (i >= MAX_TIME) break;
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
