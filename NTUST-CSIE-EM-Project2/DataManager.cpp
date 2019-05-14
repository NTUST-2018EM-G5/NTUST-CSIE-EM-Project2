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

		//����Ū�ɰj��A�æbŪ���ɮ׵����ɵ���
		while (!fin.eof())
		{
			//�q�ɮ�Ū���r��
			fin >> tempSring;
			//�ѪR��V�q�аO"V"
			Equations.push_back(tempSring);
			//���WEquationIndex�A�аO����eŪ���V�qID
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