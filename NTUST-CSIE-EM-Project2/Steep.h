#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<sstream>
#include"MyEquation.h"
#include"Variable.h"
#include"DotNetUitilities.h"
#include"MyVector.h"
#include"MyMatrix.h"

#define MAX_TIME 100
#define ZERO 0.0000001

using namespace std;
using namespace System;

class Steep
{
	public:
		Steep();
		Steep(MyEquation equation, vector<Variable> variable);
		System::String^ getResult();
	//private:
		MyEquation equation;
		vector<Variable> variable;
};