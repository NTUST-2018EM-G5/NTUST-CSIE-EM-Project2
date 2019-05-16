#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include "MyEquation.h"
#include "Variable.h"
#include "Powell.h"
#include "Newton.h"
#include "Steep.h"
#include "QuasiNewton.h"
#include "Conjugate.h"


using namespace std;
//�w�q���޸��class
class DataManager
{
	public:
		DataManager();
		//�q�ɮ�Ū����{�����
		bool LoadEquationData();
		//���o��{�����
		std::vector<std::string> GetEquations();
		//�]�m�ɮ׸��|�W��
		void SetFileName(std::string fileName);
		//��s��{�����
		bool EditEquations(int index, std::string equation);
		//�M�Ÿ��
		void Clear();
		//��ܤ@��Equation����Powell��s Method�A�^�ǭ��N�L�{
		std::string Powells_Method(int index, vector<Variable> variable);
		//��ܤ@��Equation����Newton Method�A�^�ǭ��N�L�{
		std::string Newton_Method(int index, vector<Variable> variable);
		//��ܤ@��Equation����Steep Descent Algorithm�A�^�ǭ��N�L�{
		std::string Steep_Descent_Algorithm(int index, vector<Variable> variable);
		//��ܤ@��Equation����Quasi-Newton Method�A�^�ǭ��N�L�{
		std::string Quasi_Newton_Method(int index, vector<Variable> variable);
		//��ܤ@��Equation����Conjugate Gradient Methods�A�^�ǭ��N�L�{
		std::string Conjugate_Gradient_Methods(int index, vector<Variable> variable);

	//private:
		//�x�s��{�����
		std::vector<std::string> Equations;
		//������{��ID�A�Ω󱱺�
		int EquationIndex;
		//�����ɮ׸��|�W��
		std::string FileName;
};