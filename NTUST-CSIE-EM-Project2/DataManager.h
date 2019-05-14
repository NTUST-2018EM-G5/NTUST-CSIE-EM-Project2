#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>


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
private:
	//儲存方程式資料
	std::vector<std::string> Equations;
	//紀錄方程式ID，用於控管
	int EquationIndex;
	//紀錄檔案路徑名稱
	std::string FileName;
};