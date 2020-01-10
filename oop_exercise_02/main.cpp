#include <iostream>
#include "budget_class.h"

#define UNUSED(x) (void)x

int main(int argc, char *argv[])
{
	Budget ob1{}, ob2{};

	std::cin >> ob1 >> ob2;

	std::cout << "ob1:\n" << ob1 << "ob2:\n" << ob2;

	std::cout << "ob1 + ob2:\n" << ob1 + ob2;

	std::cout << "ob1 - ob2\n" << ob1 - ob2;

	double n;
	std::cin >> n;
	std::cout << "ob1 * " << std::fixed << n << ":\n" << ob1 * n;
	std::cin >> n;
	std::cout << "ob2 * " << std::fixed << n << ":\n" << ob2 * n;

	std::cin >> n;
	std::cout << "ob1 / " << std::fixed << n << ":\n" << ob1 / n;
	std::cin >> n;
	std::cout << "ob2 / " << std::fixed << n << ":\n" << ob2 / n;

	std::cout << "ob1 = ob2 ? ";
	if (ob1 == ob2) std::cout << "YES\n";
	else std::cout << "NO\n";

	std::cout << "ob1 != ob2 ? ";
	if (ob1 != ob2) std::cout << "YES\n";
	else std::cout << "NO\n";

	std::cout << "ob1 < ob2 ? ";
	if (ob1 < ob2) std::cout << "YES\n";
	else std::cout << "NO\n";

	std::cout << "ob1 > ob2 ? ";
	if (ob1 > ob2) std::cout << "YES\n";
	else std::cout << "NO\n";

	std::cout << "ob1 <= ob2 ? ";
	if (ob1 <= ob2)	std::cout << "YES\n";
	else std::cout << "NO\n";

	std::cout << "ob1 >= ob2 ? ";
	if (ob1 >= ob2)	std::cout << "YES\n";
	else std::cout << "NO\n";

	Budget ob3 = 4.5_Budget;
	std::cout << "ob3:\n" << ob3;

	UNUSED(argc);
	UNUSED(argv);

	return 0;
}
