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
		double golden_section(double a, double b, double c);
	//private:
		MyEquation equation;
		vector<Variable> variable;
};