#include "MyMatrix.h"
#include "MyVector.h"


MyMatrix::MyMatrix()
{

}

MyMatrix::MyMatrix(int row, int col)
{
	this->Data.resize(row);
	for (int i = 0; i < row; ++i)
	{
		this->Data.at(i).resize(col);
	}
}

MyMatrix::MyMatrix(std::string name, int row, int col)
{
	this->Name = name;
	this->Data.resize(row);
	for (int i = 0; i < row; ++i)
	{
		this->Data.at(i).resize(col);
	}
}

MyMatrix::MyMatrix(std::vector<std::vector<long double>> vec)
{
	int row = vec.size();
	int col = vec.at(0).size();
	this->Data.resize(row);
	for (int i = 0; i < row; ++i)
	{
		if (vec.at(i).size() != col) throw std::string("Error: These vector are different size cannot be matrix");
		this->Data.at(i).resize(col);

		for (int j = 0; j < col; ++j)
		{
			this->at(i, j) = vec.at(i)[j];
		}
	}
}

MyMatrix::MyMatrix(std::string name, std::vector<std::vector<long double>> data)
{
	this->Name = name;
	this->Data = data;
}

int MyMatrix::rank() const
{
	if (!this->rows() || !this->cols())
	{
		return 0;
	}
	else
	{
		MyMatrix mat = *this;
		int r = 0, c = 0;
		while (r < mat.rows() && c < mat.cols()) 
		{
			//find pivot
			bool flag = true;
			while (c < mat.cols() && !mat.at(r, c))
			{
				for (int i = r + 1; i < mat.rows(); ++i) 
				{
					if (mat.at(i, c))
					{
						mat.Data.at(r).swap(mat.Data.at(i));
						flag = false;
						break;
					}
				}
				if (flag)++c;
				else break;
			}

			if (c >= mat.cols()) break;

			long double pivot = mat.at(r, c);
			for (int i = r + 1; i < mat.rows(); ++i) 
			{
				long double coef = mat.at(i, c);
				for (int j = 0; j < mat.cols(); ++j)
				{
					mat.at(i, j) -= mat.at(r, j) * coef / pivot;
					if (abs(mat.at(i, j)) < 0.000000001)
					{
						mat.at(i, j) = 0.0;
					}
				}
			}
			++r;
			++c;
		}
		
		int rank = this->rows();
		bool allZero;
		for (int j = 0; j < mat.rows(); ++j)
		{
			allZero = true;
			for (int k = 0; k < mat.cols(); ++k)
			{
				if (abs(mat.at(j, k)) > 0.000000001)
				{
					allZero = false;
					break;
				}
			}
			if (allZero)--rank;
		}
		return rank;
	}
}

MyMatrix MyMatrix::trans() const
{
	MyMatrix result(this->cols(), this->rows());
	for (int i = 0; i < this->rows(); ++i)
	{
		for (int j = 0; j < this->cols(); ++j)
		{
			result.InsertData(j, i, this->Data.at(i).at(j));
		}
	}
	return result;
}

MyMatrix MyMatrix::solve(const MyMatrix& b) const
{
	MyMatrix ans;
	ans = this->inverse() * b;
	return ans;
}

long double MyMatrix::det() const
{
	if (this->cols() != this->rows())
	{
		throw std::string("Error: the matrix is not square");
	}
	else if (this->cols() == 2) 
	{
		return  this->at(0, 0) * this->at(1, 1) - this->at(0, 1) * this->at(1, 0);
	}
	else
	{	
		MyMatrix mat = *this;
		long double scalar = 1.0;
		for (int i = 0; i < mat.rows(); ++i)
		{
			if (mat.at(i, i) == 0)
			{
				bool flag = false;
				for (int j = i + 1; j < mat.rows(); ++j)
				{
					if (mat.at(j, i) != 0)
					{
						mat.Data.at(i).swap(mat.Data.at(j));
						flag = true;
						scalar *= -1.0;
						break;
					}
				}
				if (!flag)return 0.0;
			}

			long double coef = mat.at(i, i);
			scalar *= coef;
			for (int j = i; j < mat.cols(); ++j)
			{
				mat.at(i, j) /= coef;
			}
			for (int j = i + 1; j < mat.rows(); ++j)
			{
				long double coef2 = mat.at(j, i);
				for (int k = i; k < mat.cols(); ++k)
				{
					mat.at(j, k) -= mat.at(i, k)*coef2;
				}
			}
		}
		long double ans = scalar;
		for (int j = 0; j < mat.rows(); ++j)
		{
			ans *= mat.at(j, j);
		}
		return ans;
	}
}

MyMatrix MyMatrix::inverse() const
{
	if (this->cols() != this->rows())
	{
		throw std::string("Error: the matrix is not square");
	}
	else
	{
		MyMatrix result = this->adj();
		int row = this->rows();
		int col = this->cols();
		long double det = 1.0 / this->det();
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				result.at(i, j) = det * result.at(i, j);
			}
		}
		return result;
	}
}

MyMatrix MyMatrix::adj() const
{
	int row = this->rows();
	int col = this->cols();
	MyMatrix result(row, col);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			result.at(i, j) = pow(-1.0, i + j) * this->cofactor(j, i);
		}
	}
	return result;
}

void MyMatrix::eigen(MyMatrix& v, MyMatrix& Md) const
{
	//TODO: eigen
	MyMatrix thismatrix = *this;
	if (thismatrix.rows() == 2 && thismatrix.cols() == 2)
	{
		v = thismatrix;
		Md = thismatrix;
		long double a, b, c, d,lambda,lambda2;
		a = thismatrix.Data[0][0];
		b = thismatrix.Data[0][1];
		c = thismatrix.Data[1][0];
		d = thismatrix.Data[1][1];
		lambda = pow(a + d, 2) - (4 * ((a*d)-(c*b)));
		lambda = sqrt(lambda);
		lambda2 = (a + d) - lambda;
		lambda = (a + d) + lambda;
		lambda = lambda / 2;
		lambda2 = lambda2 / 2;
		Md.Data[0][0] = lambda;
		Md.Data[1][1] = lambda2;
		Md.Data[0][1] = 0;
		Md.Data[1][0] = 0;
		thismatrix.Data[0][0] -= lambda;
		MyVector temp;
		std::vector<long double> realtempvec;
		realtempvec.push_back(-thismatrix.Data[0][1]);
		realtempvec.push_back(thismatrix.Data[0][0]);
		temp.SetData(realtempvec);
		temp = temp.normal();
		realtempvec = temp.GetData();
		v.Data[0][0] = realtempvec[0];
		v.Data[1][0] = realtempvec[1];
		thismatrix = *this;
		thismatrix.Data[0][0] -= lambda2;
		realtempvec.clear();
		realtempvec.push_back(-thismatrix.Data[0][1]);
		realtempvec.push_back(thismatrix.Data[0][0]);
		temp.SetData(realtempvec);
		temp = temp.normal();
		realtempvec = temp.GetData();
		v.Data[0][1] = realtempvec[0];
		v.Data[1][1] = realtempvec[1];
	}
	else if (thismatrix.rows() == 3 && thismatrix.cols() == 3)
	{
		v = thismatrix;
		Md = thismatrix;
		long double a, b, c, d, ei, f, g, h, ii,BB,CC,DD, lambda, lambda2,lambda3;
		a = thismatrix.Data[0][0];
		b = thismatrix.Data[0][1];
		c = thismatrix.Data[0][2];
		d = thismatrix.Data[1][0];
		ei = thismatrix.Data[1][1];
		f = thismatrix.Data[1][2];
		g = thismatrix.Data[2][0];
		h = thismatrix.Data[2][1];
		ii = thismatrix.Data[2][2];
		BB = -ii - a - ei;
		CC = a * ii + ei * ii + a * ei - g * c - h * f - d * b;
		DD = h * f * a + d * b * ii - a * ei * ii - d * h * c - g * b * f + g * c * ei;
		long double b2 = BB * BB;
		long double b3 = b2 * BB;
		long double q = (3 * CC - b2) / 9;
		long double q2 = q * q;
		long double q3 = q2 * q;
		long double r = -27 * DD + BB * (9 * CC - 2 * b2);
		r /= 54;
		long double r2 = r * r;
		long double discriminant = q3 + r2;
		/*if (discriminant < 0)
		{
			throw std::string("Error:");
		}*/
		long double s = r + sqrt(abs(discriminant));
		long double t = r - sqrt(abs(discriminant));
		//long double term1 = pow((-t + s) / 2, 1 / 3.0);
		long double term1 = BB / 3;
		long double dum1 = acos(r / sqrt(abs(q3)));
		long double r13 = 2 * sqrt(abs(q));
		lambda = (-term1 + r13 * cos(dum1 / 3));
		lambda2 = (-term1 + r13 * cos((dum1 + 2 * M_PI) / 3));
		lambda3 = (-term1 + r13 * cos((dum1 + 4 * M_PI) / 3));
		Md.Data[0][0] = lambda;
		Md.Data[1][1] = lambda2;
		Md.Data[2][2] = lambda3;
		Md.Data[0][1] = 0;
		Md.Data[0][2] = 0;
		Md.Data[1][0] = 0;
		Md.Data[1][2] = 0;
		Md.Data[2][0] = 0;
		Md.Data[2][1] = 0;

		thismatrix.Data[0][0] -= lambda;
		thismatrix.Data[1][1] -= lambda;
		thismatrix.Data[2][2] -= lambda;
		long double scalar = 1.0;
		for (int i = 0; i < thismatrix.rows(); ++i)
		{
			if (thismatrix.at(i, i) == 0)
			{
				bool flag = false;
				for (int j = i + 1; j < thismatrix.rows(); ++j)
				{
					if (thismatrix.at(j, i) != 0)
					{
						thismatrix.Data.at(i).swap(thismatrix.Data.at(j));
						flag = true;
						scalar *= -1.0;
						break;
					}
				}
				if (!flag) continue;
			}

			long double coef = thismatrix.at(i, i);
			scalar *= coef;
			for (int j = i + 1; j < thismatrix.rows(); ++j)
			{
				if (thismatrix.Data[j][i] != 0)
				{
					long double coef2 = thismatrix.Data[j][i] / thismatrix.Data[i][i];
					for (int k = i; k < thismatrix.cols(); ++k)
					{
						thismatrix.at(j, k) -= thismatrix.at(i, k)*coef2;
						if (abs(thismatrix.at(j, k)) < 0.00000001)
							thismatrix.at(j, k) = 0;
					}
				}
			}
		}
		MyVector temp;
		std::vector<long double> realtempvec;
		if (thismatrix.Data[0][0] == 0)
		{
			realtempvec.push_back(1);
			realtempvec.push_back(0);
			realtempvec.push_back(0);
		}
		else if (thismatrix.Data[1][1] == 0)
		{
			realtempvec.push_back(-thismatrix.Data[0][1] / thismatrix.Data[0][0]);
			realtempvec.push_back(1);
			realtempvec.push_back(0);
		}
		else if (thismatrix.Data[2][2] == 0)
		{
			realtempvec.push_back(((thismatrix.Data[0][2] * -1) + (thismatrix.Data[0][1] * -1 * (-thismatrix.Data[1][2] / thismatrix.Data[1][1]))) / thismatrix.Data[0][0]);
			realtempvec.push_back(-thismatrix.Data[1][2] / thismatrix.Data[1][1]);
			realtempvec.push_back(1);
		}
		else
		{
			realtempvec.push_back((-thismatrix.Data[0][1] * ((-thismatrix.Data[1][2] * thismatrix.Data[2][2]) / thismatrix.Data[1][1]) - (thismatrix.Data[0][2] * thismatrix.Data[2][2])) / thismatrix.Data[0][0]);
			realtempvec.push_back((-thismatrix.Data[1][2] * thismatrix.Data[2][2]) / thismatrix.Data[1][1]);
			realtempvec.push_back(thismatrix.Data[2][2]);
		}
		temp.SetData(realtempvec);
		temp = temp.normal();
		realtempvec = temp.GetData();
		for (int i = 0; i < realtempvec.size(); i++)
		{
			v.Data[i][0] = realtempvec[i];
		}

		thismatrix = *this;
		thismatrix.Data[0][0] -= lambda2;
		thismatrix.Data[1][1] -= lambda2;
		thismatrix.Data[2][2] -= lambda2;
		scalar = 1.0;
		for (int i = 0; i < thismatrix.rows(); ++i)
		{
			if (thismatrix.at(i, i) == 0)
			{
				bool flag = false;
				for (int j = i + 1; j < thismatrix.rows(); ++j)
				{
					if (thismatrix.at(j, i) != 0)
					{
						thismatrix.Data.at(i).swap(thismatrix.Data.at(j));
						flag = true;
						scalar *= -1.0;
						break;
					}
				}
				if (!flag) continue;
			}

			long double coef = thismatrix.at(i, i);
			scalar *= coef;
			for (int j = i + 1; j < thismatrix.rows(); ++j)
			{
				if (thismatrix.Data[j][i] != 0)
				{
					long double coef2 = thismatrix.Data[j][i] / thismatrix.Data[i][i];
					for (int k = i; k < thismatrix.cols(); ++k)
					{
						thismatrix.at(j, k) -= thismatrix.at(i, k)*coef2;
						if (abs(thismatrix.at(j,k)) < 0.00000001)
							thismatrix.at(j, k) = 0;
					}
				}
			}
		}
		realtempvec.clear();
		if (thismatrix.Data[0][0] == 0)
		{
			realtempvec.push_back(1);
			realtempvec.push_back(0);
			realtempvec.push_back(0);
		}
		else if (thismatrix.Data[1][1] == 0)
		{
			realtempvec.push_back(-thismatrix.Data[0][1] / thismatrix.Data[0][0]);
			realtempvec.push_back(1);
			realtempvec.push_back(0);
		}
		else if (thismatrix.Data[2][2] == 0)
		{
			realtempvec.push_back(((thismatrix.Data[0][2] * -1) + (thismatrix.Data[0][1] * -1 * (-thismatrix.Data[1][2] / thismatrix.Data[1][1]))) / thismatrix.Data[0][0]);
			realtempvec.push_back(-thismatrix.Data[1][2] / thismatrix.Data[1][1]);
			realtempvec.push_back(1);
		}
		else
		{
			realtempvec.push_back((-thismatrix.Data[0][1] * ((-thismatrix.Data[1][2] * thismatrix.Data[2][2]) / thismatrix.Data[1][1]) - (thismatrix.Data[0][2] * thismatrix.Data[2][2])) / thismatrix.Data[0][0]);
			realtempvec.push_back((-thismatrix.Data[1][2] * thismatrix.Data[2][2]) / thismatrix.Data[1][1]);
			realtempvec.push_back(thismatrix.Data[2][2]);
		}
		temp.SetData(realtempvec);
		temp = temp.normal();
		realtempvec = temp.GetData();
		for (int i = 0; i < realtempvec.size(); i++)
		{
			v.Data[i][1] = realtempvec[i];
		}

		thismatrix = *this;
		thismatrix.Data[0][0] -= lambda3;
		thismatrix.Data[1][1] -= lambda3;
		thismatrix.Data[2][2] -= lambda3;
		scalar = 1.0;
		for (int i = 0; i < thismatrix.rows(); ++i)
		{
			if (thismatrix.at(i, i) == 0)
			{
				bool flag = false;
				for (int j = i + 1; j < thismatrix.rows(); ++j)
				{
					if (thismatrix.at(j, i) != 0)
					{
						thismatrix.Data.at(i).swap(thismatrix.Data.at(j));
						flag = true;
						scalar *= -1.0;
						break;
					}
				}
				if (!flag) continue;
			}

			long double coef = thismatrix.at(i, i);
			scalar *= coef;
			for (int j = i + 1; j < thismatrix.rows(); ++j)
			{
				if (thismatrix.Data[j][i] != 0)
				{
					long double coef2 = thismatrix.Data[j][i] / thismatrix.Data[i][i];
					for (int k = i; k < thismatrix.cols(); ++k)
					{
						thismatrix.at(j, k) -= thismatrix.at(i, k)*coef2;
						if (abs(thismatrix.at(j, k)) < 0.00000001)
							thismatrix.at(j, k) = 0;
					}
				}
			}
		}
		realtempvec.clear();
		if (thismatrix.Data[0][0] == 0)
		{
			realtempvec.push_back(1);
			realtempvec.push_back(0);
			realtempvec.push_back(0);
		}
		else if (thismatrix.Data[1][1] == 0)
		{
			realtempvec.push_back(-thismatrix.Data[0][1] / thismatrix.Data[0][0]);
			realtempvec.push_back(1);
			realtempvec.push_back(0);
		}
		else if (thismatrix.Data[2][2] == 0)
		{
			realtempvec.push_back(((thismatrix.Data[0][2] * -1) + (thismatrix.Data[0][1] * -1 * (-thismatrix.Data[1][2] / thismatrix.Data[1][1]))) / thismatrix.Data[0][0]);
			realtempvec.push_back(-thismatrix.Data[1][2] / thismatrix.Data[1][1]);
			realtempvec.push_back(1);
		}
		else
		{
			realtempvec.push_back((-thismatrix.Data[0][1] * ((-thismatrix.Data[1][2] * thismatrix.Data[2][2]) / thismatrix.Data[1][1]) - (thismatrix.Data[0][2] * thismatrix.Data[2][2])) / thismatrix.Data[0][0]);
			realtempvec.push_back((-thismatrix.Data[1][2] * thismatrix.Data[2][2]) / thismatrix.Data[1][1]);
			realtempvec.push_back(thismatrix.Data[2][2]);
		}
		temp.SetData(realtempvec);
		temp = temp.normal();
		realtempvec = temp.GetData();
		for (int i = 0; i < realtempvec.size(); i++)
		{
			v.Data[i][2] = realtempvec[i];
		}
	}
	else
	{
		throw std::string("Error: only support 2*2 and 3*3 matrix");
	}
}

void MyMatrix::pm(MyMatrix& v, MyMatrix& d) const
{
	MyMatrix thismatrix = *this;
	int colsize = thismatrix.Data.size();
	MyMatrix result, temp(colsize,1);
	long double tempnum,difference = 1;
	long double thistime, lasttime;
	temp.Data[0][0] = 1;
	for (int i = 1; i < colsize; i++)
	{
		temp.Data[i][0] = 0;
	}
	bool flag = 0;
	while (abs(difference) > 0.0000001)
	{
		temp = thismatrix * temp;
		long double biggest = 0, comparebig = 0;
		for (int i = 0; i < colsize; i++)
		{
			if (abs(temp.Data[i][0]) > comparebig)
			{
				comparebig = abs(temp.Data[i][0]);
				biggest = temp.Data[i][0];
			}
		}
		for (int i = 0; i < colsize; i++)
		{
			temp.Data[i][0] = temp.Data[i][0] / biggest;
		}
		if (flag)
		{
			lasttime = thistime;
		}
		thistime = biggest;
		if (flag)
		{
			difference = thistime - lasttime;
		}
		flag = 1;
	}
	MyVector tempvec;
	std::vector<long double> realtempvec;
	for (int i = 0; i < colsize; i++)
	{
		realtempvec.push_back(temp.Data[i][0]);
	}
	tempvec.SetData(realtempvec);
	tempvec = tempvec.normal();
	realtempvec = tempvec.GetData();
	if (realtempvec[0] < 0)
	{
		for (int i = 0; i < colsize; i++)
		{
			realtempvec[i] *= -1;
		}
	}
	for (int i = 0; i < colsize; i++)
	{
		temp.Data.pop_back();
	}
	temp.Data.push_back(realtempvec);
	v = temp;
	realtempvec.clear();
	realtempvec.push_back(thistime);
	d.Data.push_back(realtempvec);
}

MyMatrix MyMatrix::leastSquare(const MyMatrix& b) const
{
	MyMatrix result;
	result = (this->trans() * *this).inverse() * this->trans() * b;
	return result;
}

void MyMatrix::rref(MyMatrix& L, MyMatrix& U) const
{
	//TODO: rref
}

long double MyMatrix::cofactor(int row, int col) const
{
	MyMatrix mat(this->rows() - 1, this->cols() - 1);
	int r = 0, c = 0;
	for (int i = 0; i < this->rows(); ++i)
	{
		if (i != row)
		{
			c = 0;
			for (int j = 0; j < this->cols(); ++j)
			{
				if (j != col)
				{
					mat.at(r, c++) = this->at(i, j);
				}
			}
			r++;
		}
	}
	return mat.det();
}


MyMatrix MyMatrix::operator+(const MyMatrix& b)
{
	if (this->rows() == b.rows() && this->cols() == b.cols())
	{
		int r = this->rows(), c = this->cols();
		MyMatrix result(r, c);
		
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				result.Data.at(i).at(j) = this->Data.at(i).at(j) + b.Data.at(i).at(j);
			}
		}

		return result;
	}
	else
	{
		throw std::string("Error: size different");
	}
}

MyMatrix MyMatrix::operator-(const MyMatrix& b)
{
	if (this->rows() == b.rows() && this->cols() == b.cols())
	{
		int r = this->rows(), c = this->cols();
		MyMatrix result(r, c);

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				result.Data.at(i).at(j) = this->Data.at(i).at(j) - b.Data.at(i).at(j);
			}
		}

		return result;
	}
	else
	{
		throw std::string("Error: size different");
	}
}

MyMatrix MyMatrix::operator*(const MyMatrix& b)
{
	int r = this->rows(), c = b.cols();
	MyMatrix result(r, c);
	long double sum = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			for (int k = 0; k < r; ++k)
			{
				sum += this->Data.at(i).at(k) * b.Data.at(k).at(j);
			}
			result.Data.at(i).at(j) = sum;
			sum = 0;
		}
	}

	return result;
}

int MyMatrix::rows() const
{
	return (int)this->Data.size();
}

int MyMatrix::cols() const
{
	return (int)this->Data.at(0).size();
}

std::vector<std::vector<long double>> MyMatrix::GetData() const
{
	return this->Data;
}

void MyMatrix::SetData(std::vector<std::vector<long double>> data)
{
	this->Data = data;
}

void MyMatrix::InsertData(int row, int col, long double value)
{
	this->Data.at(row).at(col) = value;
}

long double MyMatrix::at(int row, int col) const
{
	return this->Data.at(row).at(col);
}

long double& MyMatrix::at(int row, int col)
{
	return this->Data.at(row).at(col);
}

std::string MyMatrix::GetName() const
{
	return this->Name;
}

void MyMatrix::SetName(std::string name)
{
	this->Name = name;
}

System::String^ MyMatrix::PrintData() const
{
	System::String^ result = "";
	int i, j;
	for (i = 0; i < this->rows(); ++i)
	{
		for (j = 0; j < this->cols(); ++j)
		{
			double val = this->Data.at(i).at(j);
			if (!isfinite(val))
			{
				result += "INF";
			}
			else
			{
				result += val.ToString();
			}
			if (j != this->cols() - 1)
			{
				result += ", ";
			}
			
		}
		result += "\r\n";
	}

	return result;
}

System::String^ MyMatrix::PrintData(std::string format) const
{
	System::String^ result = "";
	System::String^ formatStr = gcnew System::String(format.c_str());
	int i, j;
	for (i = 0; i < this->rows(); ++i)
	{
		for (j = 0; j < this->cols(); ++j)
		{
			double val = this->Data.at(i).at(j);
			if (!isfinite(val))
			{
				result += "INF";
			}
			else
			{
				result += val.ToString(formatStr);
			}
			if (j != this->cols() - 1)
			{
				result += ", ";
			}

		}
		result += "\r\n";
	}
	return result;
}