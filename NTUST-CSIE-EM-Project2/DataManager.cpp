#include "DataManager.h"

DataManager::DataManager()
{
	this->EquationIndex = 0;
}

bool DataManager::LoadEquationData()
{
	std::fstream fin;
	//�}���ɮסA�ǤJopen��ƪ��ѼƦ���ӡA���}�_���ɮצW�١A�}���ɮת��Ҧ��Ѽ�(�o��std::ios::in��Ū��(��J)���A)
	fin.open(FileName, std::ios::in);
	//Ū�����Ѧ^��false
	if (!fin)
	{
		return false;
	}
	else
	{
		//�w�qŪ���ɮצr��Ȧs�ܼ�
		std::string tempSring;
		Equations.clear();
		EquationIndex = 0;
		//����Ū�ɰj��A�æbŪ���ɮ׵����ɵ���
		while (!fin.eof())
		{
			//�q�ɮ�Ū���r��
			getline(fin, tempSring);

			
			//�N�r��push��vector�̭�
			Equations.push_back(tempSring);
			//���WEquationIndex�A�аO���eŪ���V�qID
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
	if (variable.size() == 1 || variable.size() == 2) //���@�өΨ���ܶq
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
	if (variable.size() == 1 || variable.size() == 2) //���@�өΨ���ܶq
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
	if (variable.size() == 1 || variable.size() == 2) //���@�өΨ���ܶq
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
	if (variable.size() == 1 || variable.size() == 2) //���@�өΨ���ܶq
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
	if (variable.size() == 1 || variable.size() == 2) //���@�өΨ���ܶq
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