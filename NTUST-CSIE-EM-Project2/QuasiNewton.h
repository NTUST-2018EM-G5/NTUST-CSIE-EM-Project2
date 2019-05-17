#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<sstream>
#include"MyEquation.h"
#include"Variable.h"

using namespace std;
using namespace System;

class QuasiNewton
{
	public:
		QuasiNewton();
		QuasiNewton(MyEquation equation, vector<Variable> variable);
		System::String^ getResult();
	//private:
		MyEquation equation;
		vector<Variable> variable;
};