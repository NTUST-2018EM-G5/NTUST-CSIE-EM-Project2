#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<sstream>
#include"MyEquation.h"
#include"Variable.h"
using namespace std;

class Powell
{
	public:
		Powell();
		Powell(MyEquation equation, vector<Variable> variable);
		string getResult();
	//private:
		MyEquation equation;
		vector<Variable> variable;
};