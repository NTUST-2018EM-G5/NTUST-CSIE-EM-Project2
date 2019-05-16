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
//定義控管資料class
class DataManager
{
	public:
		DataManager();
		//從檔案讀取方程式資料
		bool LoadEquationData();
		//取得方程式資料
		std::vector<std::string> GetEquations();
		//設置檔案路徑名稱
		void SetFileName(std::string fileName);
		//更新方程式資料
		bool EditEquations(int index, std::string equation);
		//清空資料
		void Clear();
		//選擇一個Equation執行Powell’s Method，回傳迭代過程
		std::string Powells_Method(int index, vector<Variable> variable);
		//選擇一個Equation執行Newton Method，回傳迭代過程
		std::string Newton_Method(int index, vector<Variable> variable);
		//選擇一個Equation執行Steep Descent Algorithm，回傳迭代過程
		std::string Steep_Descent_Algorithm(int index, vector<Variable> variable);
		//選擇一個Equation執行Quasi-Newton Method，回傳迭代過程
		std::string Quasi_Newton_Method(int index, vector<Variable> variable);
		//選擇一個Equation執行Conjugate Gradient Methods，回傳迭代過程
		std::string Conjugate_Gradient_Methods(int index, vector<Variable> variable);

	//private:
		//儲存方程式資料
		std::vector<std::string> Equations;
		//紀錄方程式ID，用於控管
		int EquationIndex;
		//紀錄檔案路徑名稱
		std::string FileName;
};