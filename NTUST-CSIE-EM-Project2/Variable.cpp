#include "Variable.h"



Variable::Variable()
{
}

Variable::Variable(string name, double init, double begin, double end)
{
	this->name = name;
	this->init = init;
	this->begin = begin;
	this->end = end;
}
