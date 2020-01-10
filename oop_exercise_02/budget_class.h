#ifndef BUDGET_CLASS_H
#define BUDGET_CLASS_H 1

class Budget
{
	double a, b;
public:
	Budget(double first, double second) : a(first), b(first) {};
	Budget() : a(0), b(0) {};
	Budget operator+(Budget const op2) const;
	Budget operator=(Budget const op2);
	Budget operator-(Budget const op2) const;
	Budget operator*(double const &num) const;
	Budget operator/(double const &num) const;
	bool operator==(Budget const &op2) const;
	bool operator!=(Budget const &op2) const;
	bool operator<(Budget const &op2) const;
	bool operator>(Budget const &op2) const;
	bool operator<=(Budget const &op2) const;
	bool operator>=(Budget const &op2) const;
	friend std::ostream &operator<<(std::ostream &out, Budget const &ob);
	friend std::istream &operator>>(std::istream &in, Budget &ob);
	friend double rounding(double num);
};

Budget operator"" _Budget(long double);


