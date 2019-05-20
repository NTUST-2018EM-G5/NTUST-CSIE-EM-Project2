#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<sstream>
#include"MyEquation.h"
#include"Variable.h"
#include"DotNetUitilities.h"

#define ZERO 0.0000001
#define MAX_TIME 100

using namespace std;
using namespace System;

class Newton
{
	public:
		Newton();
		Newton(MyEquation equation, vector<Variable> variable);
		System::String^ getResult();
	//private:
		MyEquation equation;
		vector<Variable> variable;
};