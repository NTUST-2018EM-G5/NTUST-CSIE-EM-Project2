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
	//�⤤�Ǧ����Ǧ��A�S���D�|true
	if (!this->ExpressionToPostfix(new_equ))
	{
		throw string("Error: Bad equation");
	}
}

double MyEquation::calc(double x, double y)
{
	//TODO: �Ƽư��D�ݭn�ѨM
	vector<string> tempStr;
	vector<double> tempNum;
	double temp;
	for (size_t i = 0; i < postfix.size(); ++i)
	{
		//�P�_����
		if (postfix[i][0] == FACTORIAL || postfix[i][0] == NEGA) //�p�ⶥ���έt���ɡA�u����@�ӼƦr���B��
		{
			if (tempNum.size() < 1) //�L�k�B��(�S���������Ʀr�i�B��)
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
			if (tempNum.size() + tempStr.size() < 2)  //�L�k�B��(�S���������Ʀr�i�B��)
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
		else //�Ʀr���ܼ�
		{
			if (postfix[i] == "x") //�ܼ�x
			{
				tempNum.push_back(x);
			}
			else if (postfix[i] == "y") //�ܼ�y
			{
				tempNum.push_back(y);
			}
			else if (postfix[i] == SIN || postfix[i] == COS || postfix[i] == TAN || postfix[i] == COT || postfix[i] == SEC || postfix[i] == CSC)
			{
				tempStr.push_back(postfix[i]);
			}
			else //�Ʀr
			{
				tempNum.push_back(stod(postfix[i])); 
			}
		}
	}
	//�̫�p�⵲�G�b tempNum[0]
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
		// ����ѥk�����B��
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
		case LEFT: //���A��
		case RIGHT://�k�A��
			return 0;
		case ADD:  //�[
		case SUB:  //��
			return 1;
		case MULT: //��
		case DIV:  //��
			return 2;
		case NEGA:    //�t
			return 3;
		case POWER: //����
			return 4;
		case FACTORIAL: //����
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
		// ��e�r��
		char ch = equation[i];

		//�P�_�O�_���Ʀr�Τp���I���ܼ�(�^�ƲզX)
		if ((ch >= '0' && ch <= '9') ||
			(ch >= 'a' && ch <= 'z') ||
			(ch >= 'A' && ch <= 'Z') ||
			ch == '.' || ch == '_')
		{
			temp_str.push_back(ch);
		}
		//�P�_���A��
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
		//�P�_�k�A��
		else if (ch == RIGHT)
		{
			//��Ʀr��i��Ǧ�
			if (temp_str != "")
			{
				postfix.push_back(temp_str);
				temp_str = "";
			}
			//POP�X�A���̭����B���
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

				//POP�X���A��
				temp.pop_back();
			}
		}
		else if (ch == POWER || ch == FACTORIAL || ch == MULT || ch == DIV || ch == ADD || ch == SUB || ch == NEGA || ch == TRI)
		{
			//��Ʀr��i��Ǧ�
			if (temp_str != "")
			{
				postfix.push_back(temp_str);
				temp_str = "";
			}
			//��t�ƯS�O�B�z
			if (ch == SUB)
			{
				if (i == 0 || equation[i - 1] == LEFT || equation[i - 1] == ADD || equation[i - 1] == SUB || equation[i - 1] == MULT || equation[i - 1] == DIV || equation[i - 1] == POWER || equation[i - 1] == FACTORIAL || equation[i - 1] == NEGA || equation[i - 1] == TRI)
				{
					//#�N��t��(���O"��")
					ch = NEGA;
				}
			}
			//�P�_�u���v �p�G��e�����C �hPOP�X�e���@��
			if (temp.size() > 0)
			{
				string symbol = temp.at(temp.size() - 1); //�e���@��
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
			//���J�B���
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
	//��Ʀr��i��Ǧ��A�Φb�̫�
	if (temp_str != "")
	{
		postfix.push_back(temp_str);
		temp_str = "";
	}
	//�N�B��ť������X
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
	//�T�{�O�_�ഫ���\(���N���ǯॿ�`����)
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