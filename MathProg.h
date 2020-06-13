#pragma once
#include<iostream>
using namespace std;
class MathProg 
{
	int A0;
	int step;
public:
	MathProg() :MathProg(0, 0) {};
	MathProg(int A0, int step);
	void print(int n=10);
	MathProg operator+(MathProg b);
	MathProg operator-(MathProg b);
	int operator[](int n);
	friend istream& operator>>(istream& in, MathProg& f);
	int summa(int n=10);

~MathProg();
};



inline MathProg::MathProg(int A0, int step)
{
	this->A0=A0;
	this->step = step;
}

inline void MathProg::print(int n)
{
	if (n < 0)
	{
		int res = this->A0;
		n = n * -1;
		for (size_t i = 0; i < n; i++)
		{
			cout << res << " ";
			res = res - step;
		}
	
	}
	else{

				int res = this->A0;
			for (size_t i = 0; i < n; i++)
			{
				cout << res << " ";
				res = res + step;
			}
		}
}
istream& operator>>(istream& in, MathProg& f)
{
	cout << "Enter: A0,Step" << endl;
	in >> f.A0 >> f.step;
	return in;
}


inline MathProg MathProg::operator+(MathProg b)
{
	MathProg c;
	c.A0 = this->A0 + b.A0;
	c.step = this->step + b.step;
	return c;
}

inline MathProg MathProg::operator-(MathProg b)
{
	MathProg c;
	c.A0 = this->A0 - b.A0;
	c.step = this->step - b.step;
	return c;
}

inline int MathProg::operator[](int n)
{
	if (n<0)
	{
		cout << "Error" << endl;
	}
	else
	{

		int res = this->A0;
		for (size_t i = 0; i < n; i++)// мы ищем индекс по этому
		{
			res = res + step;
		}
		return res;
	}
}

inline int MathProg::summa(int n)
{
	if (n < 0)
	{
		cout << "Error" << endl;
	}
	else
	{
		int res = this->A0;
		int sum = res;
		for (size_t i = 0; i < n - 1; i++)
		{

			res = res + step;
			sum = sum + res;
		}

		return sum;
	}
}

MathProg ::~MathProg ()
{
}
