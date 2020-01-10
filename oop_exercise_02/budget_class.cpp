#include <iostream>
#include "budget_class.h"

double rounding(double num)
{
	if (num >= 0) num = (int) (num * 100 + 0.5) / 100.0;
    else num = (int) (num * 100 - 0.5) / 100.0;

    return num;
}

Budget Budget::operator+(Budget const op2) const
{
	Budget temp;

	temp.a = a + op2.a;
	temp.b = b + op2.b;

	return temp;
}

Budget Budget::operator=(Budget const op2)
{
	a = op2.a;
	b = op2.b;

	return *this;
}

Budget Budget::operator-(Budget const op2) const
{
	Budget temp;

	temp.a = a - op2.a;
	temp.b = b - op2.b;

	return temp;
}

Budget Budget::operator*(double const &num) const
{
	Budget temp;

	temp.a = rounding(a * num);
	temp.b = rounding(b * num);

	return temp;
}

Budget Budget::operator/(double const &num) const
{
	Budget temp;

	temp.a = rounding(a / num);
	temp.b = rounding(b / num);

	return temp;
}

bool Budget::operator==(Budget const &op2) const
{
	return ((a == op2.a) && (b == op2.b));
}

bool Budget::operator!=(Budget const &op2) const
{
	return ((a != op2.a) || (b != op2.b)); 
}

bool Budget::operator<(Budget const &op2) const
{
	if (a < op2.a)
	{
		return true;
	} 
	else if (a == op2.a)
	{
		return b < op2.b;
	}
	else
	{
		return false;
	}
}

bool Budget::operator>(Budget const &op2) const
{
	if (a > op2.a)
	{
		return true;
	} 
	else if (a == op2.a)
	{
		return b > op2.b;
	}
	else
	{
		return false;
	}
}

bool Budget::operator<=(Budget const &op2) const
{
	if (a < op2.a)
	{
		return true;
	}
	else if (a == op2.a)
	{
		return b <= op2.b;
	}
	else
	{
		return false;
	}
}

bool Budget::operator>=(Budget const &op2) const
{
	if (a > op2.a)
	{
		return true;
	}
	else if (a == op2.a)
	{
		return b >= op2.b;
	}
	else
	{
		return false;
	}
}

Budget operator"" _Budget(long double op)
{
	Budget temp{(double) op, (double) op};

	return temp;
}

std::ostream &operator<<(std::ostream &out, Budget const &ob)
{
	out.precision(2);
	out.setf(std::ios::fixed);
	out << ob.a << " " << ob.b << "\n";
	out.unsetf(std::ios::fixed);

	return out;
}

std::istream &operator>>(std::istream &in, Budget &ob)
{
	in >> ob.a >> ob.b;
	ob.a = rounding(ob.a);
	ob.b = rounding(ob.b);

	return in;
}
