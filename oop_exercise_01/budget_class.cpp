#include <iostream>
#include "budget_class.h"

Budget::Budget(double first, double second)
{
	a = rounding(first);
	b = rounding(second);
}

Budget::Budget()
{
	a = 0.0;
	b = 0.0;
}

double Budget::rounding(double num) const
{
	if (num >= 0)
		num = (int) (num * 100 + 0.5) / 100.0;
	else
		num = (int) (num * 100 - 0.5) / 100.0;

	return num;
}

Budget Budget::plus(Budget const op2) const
{
	Budget temp;

	temp.a = a + op2.a;
	temp.b = b + op2.b;

	return temp;
}

Budget Budget::assign(Budget const op2)
{
	a = op2.a;
	b = op2.b;

	return *this;
}

Budget Budget::minus(Budget const op2) const
{
	Budget temp;

	temp.a = a - op2.a;
	temp.b = b - op2.b;

	return temp;
}

Budget Budget::multiply(Budget const &op2) const
{
	Budget temp;

	temp.a = rounding(a * op2.a);
	temp.b = rounding(b * op2.b);

	return temp;
}

Budget Budget::devide(Budget const &op2) const
{
	Budget temp;

	temp.a = rounding(a / op2.a);
	temp.b = rounding(b / op2.b);

	return temp;
}

bool Budget::eq(Budget const &op2) const
{
	return ((a == op2.a) && (b == op2.b));
}

bool Budget::ne(Budget const &op2) const
{
	return ((a != op2.a) || (b != op2.b)); 
}

bool Budget::lt(Budget const &op2) const
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

bool Budget::gt(Budget const &op2) const
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

bool Budget::le(Budget const &op2) const
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

bool Budget::ge(Budget const &op2) const
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

void Budget::write(std::ostream &out)
{
	out.precision(2);
	out.setf(std::ios::fixed);
	out << a << " " << b << "\n";
	out.unsetf(std::ios::fixed);
}

void Budget::read(std::istream &in)
{
	in >> a >> b;
	a = rounding(a);
	b = rounding(b);
}
