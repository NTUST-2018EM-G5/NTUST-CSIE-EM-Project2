#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<regex>
#include<map>
#include<stack>
#include<sstream>
#include<cmath>
#include"Variable.h"

#define LEFT '('  //左括號
#define RIGHT ')' //右括號
#define POWER '^' //次方
#define FACTORIAL '!' //階乘
#define MULT '*' //乘法
#define DIV '/'  //除法
#define ADD '+'  //加法
#define SUB '-'  //減法
#define NEGA '#'   //負號
#define TRI '$' //三角函數

#define SIN "sin" 
#define COS "cos" 
#define TAN "tan"
#define COT "cot"
#define SEC "sec"
#define CSC "csc"

#define H 0.00001 //微分用的變量

using namespace std;
class MyEquation
{
	public:
		//MyEquation建構式
		MyEquation();
		MyEquation(string);

		double calc(double x, double y);

		//用於單變數
		double df_dx(double x); //一階導數
		double ddf_dxdx(double x); //二階導數
		double dddf_dxdx(double x); //三階導數

		//用於雙變數
		//TODO: 雙變數


		//把值填入
		//void FillValue(double v1);
		//void FillValue(double v1, double v2);

		//把後序式內的變數更換成指定值
		void FillValuePostfix(double v1);
		void FillValuePostfix(double v1, double v2);
		
		// 判斷兩個運算子的優先順序，若a的優先權較小，則傳回True，反之為True
		bool isLow(const char &a, const char &b);
		// 對運算式中連續加號、減號處理(ex. 1-+-1 = 1+1)
		string signReduction(const string& expression);
		// 取得運算子的優先加權值
		int getPriorityValue(const char &c);
		// 將中序式轉成後序式，若轉換成功傳回True，反之為False。(注意:轉換成功不代表可成功計算)
		bool ExpressionToPostfix(string equation);
		// 替換字串，成功回傳true
		void replaceAll(std::string& str, const std::string& from, const std::string& to);


	//private:
		string name;
		string original_equ;
		string new_equ;
		vector<string> postfix;
		//vector<Variable> variable;
};