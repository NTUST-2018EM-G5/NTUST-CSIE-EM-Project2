#include "DataManager.h"

DataManager::DataManager()
{
	this->EquationIndex = 0;
}

bool DataManager::LoadEquationData()
{
	std::fstream fin;
	//開啟檔案，傳入open函數的參數有兩個，欲開起的檔案名稱，開啟檔案的模式參數(這邊std::ios::in為讀取(輸入)狀態)
	fin.open(FileName, std::ios::in);
	//讀取失敗回傳false
	if (!fin)
	{
		return false;
	}
	else
	{
		//定義讀取檔案字串暫存變數
		std::string tempSring;
		Equations.clear();
		EquationIndex = 0;
		//執行讀檔迴圈，並在讀到檔案結尾時結束
		while (!fin.eof())
		{
			//從檔案讀取字串
			getline(fin, tempSring);

			
			//將字串push到vector裡面
			Equations.push_back(tempSring);
			//遞增EquationIndex，標記到當前讀取向量ID
			EquationIndex++;

		}
		return true;
	}
}

std::vector<std::string> DataManager::GetEquations()
{
	return Equations;
}

void DataManager::SetFileName(std::string fileName)
{
	this->FileName = fileName;
}

bool DataManager::EditEquations(int index, std::string equation)
{
	this->Equations.at(index) = equation;
	return true;
}

void DataManager::Clear()
{
	this->Equations.clear();
	this->EquationIndex = -1;
	this->FileName.clear();
}

System::String^ DataManager::Powells_Method(int index, vector<Variable> variable)
{
	System::String^ result = "-Powell's Method-\r\n";
	if (variable.size() == 1 || variable.size() == 2) //有一個或兩個變量
	{
		MyEquation equation(this->Equations.at(index));
		Powell powell(equation, variable);
		result += powell.getResult() + "\r\n";
	}
	else
	{
		throw string("Error: wrong variable amount");
	}
	return result;
}

System::String^ DataManager::Newton_Method(int index, vector<Variable> variable)
{
	System::String^ result = "-Newton Method-\r\n";
	if (variable.size() == 1 || variable.size() == 2) //有一個或兩個變量
	{
		MyEquation equation(this->Equations.at(index));
		Newton newton(equation, variable);
		result += newton.getResult();
	}
	else
	{
		throw string("Error: wrong variable amount");
	}
	return result;

}

System::String^ DataManager::Steep_Descent_Algorithm(int index, vector<Variable> variable)
{
	System::String^ result = "-Steep Descent Algorithm -\r\n";
	if (variable.size() == 1 || variable.size() == 2) //有一個或兩個變量
	{
		MyEquation equation(this->Equations.at(index));
		Steep steep(equation, variable);
		result += steep.getResult();
	}
	else
	{
		throw string("Error: wrong variable amount");
	}
	return result;
}

System::String^ DataManager::Quasi_Newton_Method(int index, vector<Variable> variable)
{
	System::String^ result = "-Quasi-Newton Method-\r\n";
	if (variable.size() == 1 || variable.size() == 2) //有一個或兩個變量
	{
		MyEquation equation(this->Equations.at(index));
		QuasiNewton quasinewton(equation, variable);
		result += quasinewton.getResult();
	}
	else
	{
		throw string("Error: wrong variable amount");
	}
	return result;
}

System::String^ DataManager::Conjugate_Gradient_Methods(int index, vector<Variable> variable)
{
	System::String^ result = "-Conjugate Gradient Methods-\r\n";
	if (variable.size() == 1 || variable.size() == 2) //有一個或兩個變量
	{
		MyEquation equation(this->Equations.at(index));
		Conjugate conjugate(equation, variable);
		result += conjugate.getResult();
	}
	else
	{
		throw string("Error: wrong variable amount");
	}
	return result;
}