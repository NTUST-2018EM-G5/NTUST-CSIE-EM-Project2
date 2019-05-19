#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<sstream>
#include"MyEquation.h"
#include"Variable.h"
#include"DotNetUitilities.h"

using namespace std;
using namespace System;

class Powell
{
	public:
		Powell();
		Powell(MyEquation equation, vector<Variable> variable);
		System::String^ getResult();
		double golden_section(double a, double b, double c,double y);
		double golden_sectiony(double a, double b, double c, double x);
		double golden_section_ex(double xin, double yin, double s1, double s2, double abe, double a1, double aen);
	//private:
		MyEquation equation;
		vector<Variable> variable;
};