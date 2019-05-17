#include "MyEquation.h"



MyEquation::MyEquation()
{

}

MyEquation::MyEquation(string equation)
{
	this->original_equ = equation;
	this->new_equ = equation;
	this->replaceAll(new_equ, "sin", "sin$");
	this->replaceAll(new_equ, "cos", "cos$");
	this->replaceAll(new_equ, "tan", "tan$");
	this->replaceAll(new_equ, "cot", "cot$");
	this->replaceAll(new_equ, "sec", "sec$");
	this->replaceAll(new_equ, "csc", "csc$");
	//把中序式轉後序式，沒問題會true
	if (!this->ExpressionToPostfix(new_equ))
	{
		throw string("Error: Bad equation");
	}
}

double MyEquation::calc(double x, double y)
{
	//TODO: 複數問題需要解決
	vector<string> tempStr;
	vector<double> tempNum;
	double temp;
	for (size_t i = 0; i < postfix.size(); ++i)
	{
		//判斷類型
		if (postfix[i][0] == FACTORIAL || postfix[i][0] == NEGA) //計算階乘或負號時，只須對一個數字做運算
		{
			if (tempNum.size() < 1) //無法運算(沒有足夠的數字可運算)
			{
				throw string("Error: Bad formula");
			}
			if (postfix[i][0] == FACTORIAL)
			{
				//TODO: FACTORIA
			}
			else if (postfix[i][0] == NEGA)
			{
				temp = -tempNum[tempNum.size() - 1];
				tempNum.pop_back();
				tempNum.push_back(temp);
			}
		}
		else if (postfix[i].size() == 1 && (postfix[i][0] == ADD || postfix[i][0] == SUB || postfix[i][0] == MULT || postfix[i][0] == DIV || postfix[i][0] == POWER || postfix[i][0] == TRI))
		{
			if (tempNum.size() + tempStr.size() < 2)  //無法運算(沒有足夠的數字可運算)
			{
				throw string("Error: Bad formula");
			}
			
			if (postfix[i][0] == ADD)
			{
				temp = tempNum[tempNum.size() - 2] + tempNum[tempNum.size() - 1];
				tempNum.pop_back();
				tempNum.pop_back();
				tempNum.push_back(temp);
			}
			else if (postfix[i][0] == SUB)
			{
				temp = tempNum[tempNum.size() - 2] - tempNum[tempNum.size() - 1];
				tempNum.pop_back();
				tempNum.pop_back();
				tempNum.push_back(temp);
			}
			else if (postfix[i][0] == MULT)
			{
				temp = tempNum[tempNum.size() - 2] * tempNum[tempNum.size() - 1];
				tempNum.pop_back();
				tempNum.pop_back();
				tempNum.push_back(temp);
			}
			else if (postfix[i][0] == DIV)
			{
				temp = tempNum[tempNum.size() - 2] / tempNum[tempNum.size() - 1];
				tempNum.pop_back();
				tempNum.pop_back();
				tempNum.push_back(temp);
			}
			else if (postfix[i][0] == POWER)
			{
				
				temp = pow(tempNum[tempNum.size() - 2], tempNum[tempNum.size() - 1]);
				tempNum.pop_back();
				tempNum.pop_back();
				tempNum.push_back(temp);
			}
			else if (postfix[i][0] == TRI)
			{
				if (tempStr[tempStr.size() - 1] == SIN)
				{
					temp = sin(tempNum[tempNum.size() - 1]);
					tempNum.pop_back();
					tempStr.pop_back();
					tempNum.push_back(temp);
				}
				else if (tempStr[tempStr.size() - 1] == COS)
				{
					temp = cos(tempNum[tempNum.size() - 1]);
					tempNum.pop_back();
					tempStr.pop_back();
					tempNum.push_back(temp);
				}
				else if (tempStr[tempStr.size() - 1] == TAN)
				{
					temp = tan(tempNum[tempNum.size() - 1]);
					tempNum.pop_back();
					tempStr.pop_back();
					tempNum.push_back(temp);
				}
				else if (tempStr[tempStr.size() - 1] == COT)
				{
					temp = 1 / tan(tempNum[tempNum.size() - 1]);
					tempNum.pop_back();
					tempStr.pop_back();
					tempNum.push_back(temp);
				}
				else if (tempStr[tempStr.size() - 1] == SEC)
				{
					temp = 1 / cos(tempNum[tempNum.size() - 1]);
					tempNum.pop_back();
					tempStr.pop_back();
					tempNum.push_back(temp);
				}
				else if (tempStr[tempStr.size() - 1] == CSC)
				{
					temp = 1 / sin(tempNum[tempNum.size() - 1]);
					tempNum.pop_back();
					tempStr.pop_back();
					tempNum.push_back(temp);
				}
			}
		}
		else //數字或變數
		{
			if (postfix[i] == "x") //變數x
			{
				tempNum.push_back(x);
			}
			else if (postfix[i] == "y") //變數y
			{
				tempNum.push_back(y);
			}
			else if (postfix[i] == SIN || postfix[i] == COS || postfix[i] == TAN || postfix[i] == COT || postfix[i] == SEC || postfix[i] == CSC)
			{
				tempStr.push_back(postfix[i]);
			}
			else //數字
			{
				tempNum.push_back(stod(postfix[i])); 
			}
		}
	}
	//最後計算結果在 tempNum[0]
	if (tempNum.size() == 0)
	{
		throw string("Error: Bad formula");
	}
	return tempNum.at(0);
}

double MyEquation::df_dx(double x)
{
	return (this->calc(x + H, 0) - this->calc(x, 0)) / H;
}

double MyEquation::ddf_dxdx(double x)
{
	return (this->df_dx(x + H) - this->df_dx(x)) / H;
}

double MyEquation::dddf_dxdx(double x)
{
	return (this->ddf_dxdx(x + H) - this->ddf_dxdx(x)) / H;
}

double MyEquation::f_x(double x, double y)
{
	return (this->calc(x + H, y) - this->calc(x, y)) / H;
}

double MyEquation::f_y(double x, double y)
{
	return (this->calc(x, y + H) - this->calc(x, y)) / H;
}

double MyEquation::f_xx(double x, double y)
{
	return (this->calc(x + H, y) - 2 * this->calc(x, y) + this->calc(x - H, y)) / (H*H);
}

double MyEquation::f_yy(double x, double y)
{
	return (this->calc(x, y + H) - 2 * this->calc(x, y) + this->calc(x, y - H)) / (H*H);
}

double MyEquation::f_xy(double x, double y)
{
	return (this->calc(x + H, y + H) - this->calc(x - H, y + H) + this->calc(x + H, y - H) + this->calc(x - H, y - H)) / (4 * H*H);
}


void MyEquation::FillValuePostfix(double v1)
{
	ostringstream strs;
	strs << v1;
	string v1Str = strs.str();

	for (size_t i = 0; i < postfix.size(); i++)
	{
		if (postfix.at(i) == "x")
		{
			postfix.at(i) = v1Str;
		}
	}
}

void MyEquation::FillValuePostfix(double v1, double v2)
{
	ostringstream strs;
	strs << v1;
	string v1Str = strs.str();
	strs << v2;
	string v2Str = strs.str();

	for (size_t i = 0; i < postfix.size(); i++)
	{
		if (postfix.at(i) == "x")
		{
			postfix.at(i) = v1Str;
		}
		else if (postfix.at(i) == "y")
		{
			postfix.at(i) = v2Str;
		}
	}
}

bool MyEquation::isLow(const char &a, const char &b)
{
	if (a == POWER && b == POWER)
	{
		// 次方由右往左運算
		return false;
	}
	return getPriorityValue(a) <= getPriorityValue(b);
}

string MyEquation::signReduction(const string& str)
{
	bool flag = false;
	string expression = str;
	for (int i = 0; i < expression.length() - 1; )
	{
		if (expression[i] == '+')
		{
			if (expression[i + 1] == '+')
			{
				expression.erase(expression.begin() + i + 1);
			}
			else if (expression[i + 1] == '-')
			{
				expression.erase(expression.begin() + i);
			}
			else
			{
				i++;
			}
		}
		else if (expression[i] == '-')
		{
			if (expression[i + 1] == '+')
			{
				expression.erase(expression.begin() + i + 1);
			}
			else if (expression[i + 1] == '-')
			{
				expression[i] = '+';
				expression.erase(expression.begin() + i + 1);
			}
			else
			{
				i++;
			}
		}
		else
		{
			i++;
		}

		if (expression[0] == '+')
		{
			expression.erase(expression.begin());
		}
	}
	regex naruto("\\(\\+");
	expression = regex_replace(expression, naruto, "(0+");
	return expression;
}

int MyEquation::getPriorityValue(const char &c)
{
	switch (c)
	{
		case LEFT: //左括號
		case RIGHT://右括號
			return 0;
		case ADD:  //加
		case SUB:  //減
			return 1;
		case MULT: //乘
		case DIV:  //除
			return 2;
		case NEGA:    //負
			return 3;
		case POWER: //次方
			return 4;
		case FACTORIAL: //階乘
			return 5;
		case TRI:
			return 6;
	}
	return 0;
}

bool MyEquation::ExpressionToPostfix(string equation)
{
	vector<string> temp;
	string temp_str = "";

	for (int i = 0; i < equation.size(); i++)
	{
		string temp_negative = "";
		// 當前字元
		char ch = equation[i];

		//判斷是否為數字或小數點或變數(英數組合)
		if ((ch >= '0' && ch <= '9') ||
			(ch >= 'a' && ch <= 'z') ||
			(ch >= 'A' && ch <= 'Z') ||
			ch == '.' || ch == '_')
		{
			temp_str.push_back(ch);
		}
		//判斷左括號
		else if (ch == LEFT)
		{
			if (i > 0 && equation[i - 1] != LEFT && equation[i - 1] != POWER && equation[i - 1] != FACTORIAL && equation[i - 1] != MULT && equation[i - 1] != DIV && equation[i - 1] != ADD && equation[i - 1] != SUB && equation[i - 1] != NEGA && equation[i - 1] != TRI)
			{
				if (temp_str != "")
				{
					postfix.push_back(temp_str);
					temp_str = "";
				}
				temp.push_back("*");
			}
			temp_negative = ch;
			temp.push_back(temp_negative);
		}
		//判斷右括號
		else if (ch == RIGHT)
		{
			//把數字放進後序式
			if (temp_str != "")
			{
				postfix.push_back(temp_str);
				temp_str = "";
			}
			//POP出括號裡面的運算符
			if (temp.size() > 0)
			{
				string symbol = temp.at(temp.size() - 1);
				while (symbol[0] != LEFT)
				{
					temp.pop_back();
					postfix.push_back(symbol);
					if (temp.size() <= 0)
						break;
					symbol = temp.at(temp.size() - 1);
				}

				//POP出左括號
				temp.pop_back();
			}
		}
		else if (ch == POWER || ch == FACTORIAL || ch == MULT || ch == DIV || ch == ADD || ch == SUB || ch == NEGA || ch == TRI)
		{
			//把數字放進後序式
			if (temp_str != "")
			{
				postfix.push_back(temp_str);
				temp_str = "";
			}
			//對負數特別處理
			if (ch == SUB)
			{
				if (i == 0 || equation[i - 1] == LEFT || equation[i - 1] == ADD || equation[i - 1] == SUB || equation[i - 1] == MULT || equation[i - 1] == DIV || equation[i - 1] == POWER || equation[i - 1] == FACTORIAL || equation[i - 1] == NEGA || equation[i - 1] == TRI)
				{
					//#代表負數(不是"減")
					ch = NEGA;
				}
			}
			//判斷優先權 如果比前面的低 則POP出前面一個
			if (temp.size() > 0)
			{
				string symbol = temp.at(temp.size() - 1); //前面一個
				while (this->isLow(ch, symbol[0]))
				{
					temp.pop_back();
					if (symbol[0] == SUB && postfix.at(postfix.size() - 1)[0] == SUB)
					{
						postfix.at(postfix.size() - 1)[0] = '+';
					}
					postfix.push_back(symbol);
					if (temp.size() <= 0)
						break;
					symbol = temp.at(temp.size() - 1);
				}
			}
			//插入運算符
			temp_negative = ch;
			temp.push_back(temp_negative);
		}
		else
		{
			string character;
			character += ch;
			throw string("Error: Bad formula at character '" + character + "'.");
		}
	}
	//把數字放進後序式，用在最後
	if (temp_str != "")
	{
		postfix.push_back(temp_str);
		temp_str = "";
	}
	//將運算符全部取出
	for (; temp.size() > 0;)
	{
		string symbol = temp.at(temp.size() - 1);
		temp.pop_back();
		if (symbol[0] == SUB && postfix.at(postfix.size() - 1)[0] == SUB)
		{
			postfix.at(postfix.size() - 1)[0] = '+';
		}
		postfix.push_back(symbol);
		if (temp.size() <= 0)
			break;
		symbol = temp.at(temp.size() - 1);
	}
	//確認是否轉換成功(不代表後序能正常執行)
	if (postfix.size() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MyEquation::replaceAll(string& str, const string& from, const string& to)
{
	if (from.empty())
		return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
}