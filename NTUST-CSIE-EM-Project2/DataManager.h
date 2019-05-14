#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>


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
private:
	//�x�s��{�����
	std::vector<std::string> Equations;
	//������{��ID�A�Ω󱱺�
	int EquationIndex;
	//�����ɮ׸��|�W��
	std::string FileName;
};