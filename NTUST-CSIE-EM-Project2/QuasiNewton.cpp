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
	if (variable.size() == 1) //單變數
	{
		double gradient, hessian, hessian_inverse, deltaX, preX,newhessian_inverse,newgradient,deltagradient,newhessian,alpha;
		double x = variable.at(0).init;
		int k = 1;
		gradient = this->equation.df_dx(x);
		hessian = this->equation.ddf_dxdx(x);
		hessian += 0.1;
		hessian_inverse = 1 / hessian;
		while (1)
		{
			if (abs(gradient) < 0.0001) break;
			deltaX = -gradient * hessian_inverse;
			preX = x;
			alpha = 0;
			double step = 0.01;
			while (1)
			{
				double num1 = x + alpha * deltaX;
				double num1ans = this->equation.calc(num1, 0);
				alpha += step;
				double num2 = x + alpha * deltaX;
				double num2ans = this->equation.calc(num2, 0);
				if (num2ans > num1ans)
				{
					step = step * -0.1;
				}
				if (abs(num1ans - num2ans) < 0.00000001)
				{
					break;
				}
			}
			x = x + alpha * deltaX;
			deltaX *= alpha;
			newgradient = this->equation.df_dx(x);
			deltagradient = newgradient - gradient;
			newhessian_inverse = hessian_inverse + (deltaX * deltaX) / (deltaX * deltagradient) - ((hessian_inverse * deltagradient) * ((hessian_inverse * deltagradient))) / (((deltagradient)) * hessian_inverse * deltagradient);
			newhessian = 1 / newhessian_inverse;
			//OUTPUT
			result += "i=" + k + Environment::NewLine;
			result += "Hessian = [" + hessian.ToString("0.##########") + "]" + Environment::NewLine;
			result += "HessianInverse = [" + hessian_inverse.ToString("0.##########") + "]" + Environment::NewLine;
			result += ConvertToString(this->variable.at(0).name) + " = [" + x.ToString("0.##########") + "]" + Environment::NewLine + Environment::NewLine;
			//------
			k++;
			if (k > MAX_TIME || (this->equation.calc(x, 0) < this->equation.calc(preX, 0) && abs(gradient) < ZERO)) break;
			if (abs(hessian - newhessian) < 0.001) break;
			hessian = newhessian;
			hessian_inverse = newhessian_inverse;
			gradient = newgradient;
		}
		//OUTPUT
		result += "[" + ConvertToString(this->variable.at(0).name) + "] = [" + x.ToString("0.##########") + "]" + Environment::NewLine;
		result += "min = [" + this->equation.calc(x, 0).ToString("0.##########") + "]" + Environment::NewLine;
		result += "-done-" + Environment::NewLine + Environment::NewLine;
		//------
	}
	else if (variable.size() == 2) //雙變數
	{
		double gradient[2], pre[2], delta[2], hessian[2][2], hessian_inverse[2][2],newhessian_inverse[2][2],newgradient[2], deltagradient[2],alpha,fgk[2];
		double initX = variable.at(0).init;
		double initY = variable.at(1).init;
		double x = initX;
		double y = initY;
		double A;
		int k = 1;
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
		while (1)
		{
			if (abs(gradient[0]) < 0.0001 || abs(gradient[1]) < 0.0001) break;
			//x0
			pre[0] = x;
			pre[1] = y;
			//delta
			delta[0] = (-hessian_inverse[0][0]) * gradient[0] + (-hessian_inverse[0][1]) * gradient[1];
			delta[1] = (-hessian_inverse[1][0]) * gradient[0] + (-hessian_inverse[1][1]) * gradient[1];

			alpha = 0;
			double step = 0.01;
			while (1)
			{
				double num1[2];
				num1[0] = x + alpha * delta[0];
				num1[1] = y + alpha * delta[1];
				double num1ans = this->equation.calc(num1[0], num1[1]);
				alpha += step;
				double num2[2];
				num2[0] = x + alpha * delta[0];
				num2[1] = y + alpha * delta[1];
				double num2ans = this->equation.calc(num2[0], num2[1]);
				if (num2ans > num1ans)
				{
					step = step * -0.1;
				}
				if (abs(num1ans - num2ans) < 0.00000001)
				{
					break;
				}
			}
			delta[0] = alpha * delta[0];
			delta[1] = alpha * delta[1];
			//x1
			x = x + delta[0];
			y = y + delta[1];
			if (abs(x) < ZERO) x = 0;
			if (abs(y) < ZERO) y = 0;

			//newgradient
			newgradient[0] = this->equation.f_x(x, y);
			newgradient[1] = this->equation.f_y(x, y);

			deltagradient[0] = newgradient[0] - gradient[0];
			deltagradient[1] = newgradient[1] - gradient[1];

			fgk[0] = hessian_inverse[0][0] * gradient[0] + hessian_inverse[0][1] * gradient[1];
			fgk[1] = hessian_inverse[1][0] * gradient[0] + hessian_inverse[1][1] * gradient[1];

			//newhessian_inverse
			newhessian_inverse[0][0] = hessian_inverse[0][0] + ((delta[0] * delta[0]) / (delta[0] * gradient[0] + delta[1] * gradient[1])) - ((fgk[0] * fgk[0]) / (gradient[0] * fgk[0] + gradient[1] * fgk[1]));
			newhessian_inverse[0][1] = hessian_inverse[0][1] + ((delta[0] * delta[1]) / (delta[0] * gradient[0] + delta[1] * gradient[1])) - ((fgk[0] * fgk[1]) / (gradient[0] * fgk[0] + gradient[1] * fgk[1]));
			newhessian_inverse[1][0] = hessian_inverse[1][0] + ((delta[1] * delta[0]) / (delta[0] * gradient[0] + delta[1] * gradient[1])) - ((fgk[1] * fgk[0]) / (gradient[0] * fgk[0] + gradient[1] * fgk[1]));
			newhessian_inverse[1][1] = hessian_inverse[1][1] + ((delta[1] * delta[1]) / (delta[0] * gradient[0] + delta[1] * gradient[1])) - ((fgk[1] * fgk[1]) / (gradient[0] * fgk[0] + gradient[1] * fgk[1]));

			//OUTPUT
			//result += "i=" + k + Environment::NewLine;
			if (k == 1)
			{
				result += "Initial Hessian = [" + hessian[0][0].ToString("0.##########") + " , " + hessian[0][1].ToString("0.##########") + "]" + Environment::NewLine;
				result += "                  [" + hessian[1][0].ToString("0.##########") + " , " + hessian[1][1].ToString("0.##########") + "]" + Environment::NewLine;
				result += "Initial HessianInverse = [" + hessian_inverse[0][0].ToString("0.##########") + " , " + hessian_inverse[0][1].ToString("0.##########") + "]" + Environment::NewLine;
				result += "                         [" + hessian_inverse[1][0].ToString("0.##########") + " , " + hessian_inverse[1][1].ToString("0.##########") + "]" + Environment::NewLine;
				result += ConvertToString(this->variable.at(0).name) + " = [" + x.ToString("0.##########") + "]" + Environment::NewLine;
				result += ConvertToString(this->variable.at(1).name) + " = [" + y.ToString("0.##########") + "]" + Environment::NewLine + Environment::NewLine;
			}
			else
			{
				result += "HessianInverse = [" + hessian_inverse[0][0].ToString("0.##########") + " , " + hessian_inverse[0][1].ToString("0.##########") + "]" + Environment::NewLine;
				result += "                 [" + hessian_inverse[1][0].ToString("0.##########") + " , " + hessian_inverse[1][1].ToString("0.##########") + "]" + Environment::NewLine;
				result += ConvertToString(this->variable.at(0).name) + " = [" + x.ToString("0.##########") + "]" + Environment::NewLine;
				result += ConvertToString(this->variable.at(1).name) + " = [" + y.ToString("0.##########") + "]" + Environment::NewLine + Environment::NewLine;
			}
			//------
			k++;
			if (k > MAX_TIME || (this->equation.calc(x, y) < this->equation.calc(pre[0], pre[1]) && abs(gradient[0]) < ZERO && abs(gradient[1]) < ZERO)) break;
			if (abs(hessian_inverse[0][0] - newhessian_inverse[0][0]) < 0.001 || abs(hessian_inverse[0][1] - newhessian_inverse[0][1]) < 0.001 || abs(hessian_inverse[1][0] - newhessian_inverse[1][0]) < 0.001 || abs(hessian_inverse[1][1] - newhessian_inverse[1][1]) < 0.001) break;
			hessian_inverse[0][0] = newhessian_inverse[0][0];
			hessian_inverse[0][1] = newhessian_inverse[0][1];
			hessian_inverse[1][0] = newhessian_inverse[1][0];
			hessian_inverse[1][1] = newhessian_inverse[1][1];
			gradient[0] = newgradient[0];
			gradient[1] = newgradient[1];
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