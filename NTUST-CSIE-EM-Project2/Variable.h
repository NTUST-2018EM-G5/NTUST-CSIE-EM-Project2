#pragma once
#include<iostream>
#include<string>
using namespace std;
class Variable
{
public:
	Variable();
	Variable(string, double, double, double);
	std::string name;
	double init;
	double begin;
	double end;
};

