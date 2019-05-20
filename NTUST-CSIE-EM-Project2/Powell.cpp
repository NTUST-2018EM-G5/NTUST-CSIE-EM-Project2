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

double Powell::golden_section(double a, double b, double c, double y)
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
	if (this->equation.calc(x,y) < this->equation.calc(b,y))
	{
		if (c - b > b - a)
		{
			return golden_section(b, x, c,y);
		}
		else
		{
			return golden_section(a, x, b, y);
		}
	}
	else
	{
		if (c - b > b - a)
		{
			return golden_section(a, b, x, y);
		}
		else
		{
			return golden_section(x, b, c, y);
		}
	}
}
double Powell::golden_sectiony(double a, double b, double c, double x)
{
	double tau = 0.00000001;
	double y;
	if (c - b > b - a)
	{
		y = b + resphi * (c - b);
	}
	else
	{
		y = b - resphi * (b - a);
	}
	if (abs(c - a) < tau * (abs(b) + abs(y)))
	{
		return (c + a) / 2;
	}
	if (this->equation.calc(x, y) < this->equation.calc(x, b))
	{
		if (c - b > b - a)
		{
			return golden_sectiony(b, y, c, x);
		}
		else
		{
			return golden_sectiony(a, y, b, x);
		}
	}
	else
	{
		if (c - b > b - a)
		{
			return golden_sectiony(a, b, y, x);
		}
		else
		{
			return golden_sectiony(y, b, c, x);
		}
	}
}
double f(double x, double y)
{
	return 0.001 * pow(x,3) - 0.07 * pow(x, 2) + 0.06*x + 0.0002 * pow(y , 3)- 0.004 * pow(y,2) + 0.02 * y;
}
double Powell::golden_section_ex(double xin, double yin, double s1, double s2,double abe,double a1, double aen)
{
	double tau = 0.00000001;
	double a2;
	if (aen - a1 > a1 - abe)
	{
		a2 = a1 + resphi * (aen - a1);
	}
	else
	{
		a2 = a1 - resphi * (a1 - abe);
	}
	if (abs(aen - abe) < tau * (abs(a1) + abs(a2)))
	{
		return (aen + abe) / 2;
	}
	double x1, x2, y1, y2;
	x1 = xin + (a1 * s1);
	y1 = yin + (a1 * s2);
	x2 = xin + (a2 * s1);
	y2 = yin + (a2 * s2);
	if (this->equation.calc(x1, y1) < this->equation.calc(x2, y2)) //帶a1會比較小
	//if(f(xin + (a1 * s1), yin + (a1 * s2)) < f(xin + (a2 * s1), yin + (a2 * s2)))
	{
		if (aen - a1 > a1 - abe) //a2在a1右邊
		{
			return golden_section_ex(xin, yin, s1, s2, abe, a1, a2);
		}
		else //a2在a1左邊
		{
			return golden_section_ex(xin, yin, s1, s2, a2,a1, aen);
		}
	}
	else // 帶入a2會比較小
	{
		if (aen - a1 > a1 - abe) //a2在a1右邊
		{
			return golden_section_ex(xin, yin, s1, s2, a1, a2, aen);
		}
		else //a2在a1左邊
		{
			return golden_section_ex(xin, yin, s1, s2, abe, a2, a1);
		}
	}
}
System::String^ Powell::getResult()
{
	System::String^ result = "";
	string temp;
	double r = 0;
	double r2 = 0;
	if (variable.size() == 1)
	{
		r = golden_section(this->variable[0].begin, this->variable[0].init, this->variable[0].end, 0);
		r2 = this->equation.calc(r, 0);
		result += "[" + ConvertToString(this->variable[0].name) + "] = [" + r.ToString("0.##########") + "]" + Environment::NewLine;
		result += "min = " + r2.ToString("0.##########") + Environment::NewLine;
	}
	else if (variable.size() == 2)
	{
		double xbegin, xinit, xend, ybegin, yinit, yend;
		xbegin = this->variable[0].begin;
		xinit = this->variable[0].init;
		xend = this->variable[0].end;
		ybegin = this->variable[1].begin;
		yinit = this->variable[1].init;
		yend = this->variable[1].end;
		int jn = 1;
		double s1 = 1, s2 = 0;
		double s3 = 0, s4 = 1;
		double s5, s6;
		double ainit;
		double limits[4];
		while (1)
		{
			int in = 1;
			result += "j = " + jn.ToString() + Environment::NewLine + "i = " + in.ToString() + Environment::NewLine;
			result += "X1[" + xinit.ToString("0.##########") + " " + yinit.ToString("0.##########") + "]" + Environment::NewLine;
			if (abs(s1) < 0.0001)
			{
				limits[0] = (xbegin - xinit);
				limits[1] = (xend - xinit);
			}
			else
			{
				limits[0] = (xbegin - xinit) / s1;
				limits[1] = (xend - xinit) / s1;
			}
			if (abs(s2) < 0.0001)
			{
				limits[2] = (ybegin - yinit);
				limits[3] = (yend - yinit);
			}
			else
			{
				limits[2] = (ybegin - yinit) / s2;
				limits[3] = (yend - yinit) / s2;
			}
			sort(limits, limits + 4);
			ainit = golden_section_ex(xinit, yinit, s1, s2, limits[1], (limits[1] + limits[2]) / 2, limits[2]);
			xinit = xinit + ainit * s1;
			yinit = yinit + ainit * s2;
			s5 = ainit * s1;
			s6 = ainit * s2;
			result += "X2[" + xinit.ToString("0.##########") + " " + yinit.ToString("0.##########") + "]" + Environment::NewLine + Environment::NewLine;
			in++;
			result += "i = " + in.ToString() + Environment::NewLine;
			result += "X2[" + xinit.ToString("0.##########") + " " + yinit.ToString("0.##########") + "]" + Environment::NewLine;
			if (abs(s3) < 0.0001)
			{
				limits[0] = (xbegin - xinit);
				limits[1] = (xend - xinit);
			}
			else
			{
				limits[0] = (xbegin - xinit) / s3;
				limits[1] = (xend - xinit) / s3;
			}
			if (abs(s4) < 0.0001)
			{
				limits[2] = (ybegin - yinit);
				limits[3] = (yend - yinit);
			}
			else
			{
				limits[2] = (ybegin - yinit) / s4;
				limits[3] = (yend - yinit) / s4;
			}
			sort(limits, limits + 4);
			ainit = golden_section_ex(xinit, yinit, s3, s4, limits[1], (limits[1] + limits[2]) / 2, limits[2]);
			xinit = xinit + ainit * s3;
			yinit = yinit + ainit * s4;
			s5 += ainit * s3;
			s6 += ainit * s4;
			result += "X3[" + xinit.ToString("0.##########") + " " + yinit.ToString("0.##########") + "]" + Environment::NewLine + Environment::NewLine;
			if (abs(s5) < 0.0001)
			{
				limits[0] = (xbegin - xinit);
				limits[1] = (xend - xinit);
			}
			else
			{
				limits[0] = (xbegin - xinit) / s5;
				limits[1] = (xend - xinit) / s5;
			}
			if (abs(s6) < 0.0001)
			{
				limits[2] = (ybegin - yinit);
				limits[3] = (yend - yinit);
			}
			else
			{
				limits[2] = (ybegin - yinit) / s6;
				limits[3] = (yend - yinit) / s6;
			}
			sort(limits, limits + 4);
			ainit = golden_section_ex(xinit, yinit, s5, s6, limits[1], (limits[1] + limits[2]) / 2, limits[2]);
			xinit = xinit + ainit * s5;
			yinit = yinit + ainit * s6;
			result += "alpha = " + ainit.ToString("0.##########") + Environment::NewLine;
			result += "S3[" + s5.ToString("0.##########") + " " + s6.ToString("0.##########") + "]" + Environment::NewLine;
			result += "X4[" + xinit.ToString("0.##########") + " " + yinit.ToString("0.##########") + "]" + Environment::NewLine + Environment::NewLine;
			if ((abs(xinit - (xinit - ainit * s5)) < 0.00000001) && (abs(yinit - (yinit - ainit * s6)) < 0.00000001))
			{
				result += "[x,y] = " + xinit.ToString("0.##########") + ", " + yinit.ToString("0.##########") + "]" + Environment::NewLine;
				double temp = this->equation.calc(xinit, yinit);
				result += "min = " + temp.ToString("0.##########") + Environment::NewLine;
				break;
			}
			jn++;
			s1 = s3;
			s2 = s4;
			s3 = s5;
			s4 = s6;
			s5 = 0;
			s6 = 0;
		}
	}
	
	return result;
}