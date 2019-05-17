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

#define LEFT '('  //���A��
#define RIGHT ')' //�k�A��
#define POWER '^' //����
#define FACTORIAL '!' //����
#define MULT '*' //���k
#define DIV '/'  //���k
#define ADD '+'  //�[�k
#define SUB '-'  //��k
#define NEGA '#'   //�t��
#define TRI '$' //�T�����

#define SIN "sin" 
#define COS "cos" 
#define TAN "tan"
#define COT "cot"
#define SEC "sec"
#define CSC "csc"

#define H 0.00001 //�L���Ϊ��ܶq

using namespace std;
class MyEquation
{
	public:
		//MyEquation�غc��
		MyEquation();
		MyEquation(string);

		double calc(double x, double y);

		//�Ω���ܼ�
		double df_dx(double x); //�@���ɼ�
		double ddf_dxdx(double x); //�G���ɼ�
		double dddf_dxdx(double x); //�T���ɼ�

		//�Ω����ܼ�
		//TODO: ���ܼ�


		//��ȶ�J
		//void FillValue(double v1);
		//void FillValue(double v1, double v2);

		//���Ǧ������ܼƧ󴫦����w��
		void FillValuePostfix(double v1);
		void FillValuePostfix(double v1, double v2);
		
		// �P�_��ӹB��l���u�����ǡA�Ya���u���v���p�A�h�Ǧ^True�A�Ϥ���True
		bool isLow(const char &a, const char &b);
		// ��B�⦡���s��[���B��B�z(ex. 1-+-1 = 1+1)
		string signReduction(const string& expression);
		// ���o�B��l���u���[�v��
		int getPriorityValue(const char &c);
		// �N���Ǧ��ন��Ǧ��A�Y�ഫ���\�Ǧ^True�A�Ϥ���False�C(�`�N:�ഫ���\���N��i���\�p��)
		bool ExpressionToPostfix(string equation);
		// �����r��A���\�^��true
		void replaceAll(std::string& str, const std::string& from, const std::string& to);


	//private:
		string name;
		string original_equ;
		string new_equ;
		vector<string> postfix;
		//vector<Variable> variable;
};