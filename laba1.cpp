/*
Петрин Сергей, М8О-207Б 
Вариант 17
Создать класс Budget для работы с бюджетом. Класс состоит из двух
вещественных чисел (a,b). Где a – собственная часть средств бюджета 
в рублях, b – заемная часть средств бюджета рублях. Оба числа должны 
округляться до второго знака после запятой. Реализовать 
арифметические операции сложения, вычитания, умножения и деления, 
а также операции сравнения.
*/

#include <iostream>
#include <cmath>
#include <exception>
using namespace std;

class Budget {
public: double prop, loan;
		void sum(Budget B, Budget &C);  //функции принимают на вход 2 аргумента
		void sub(Budget B, Budget &C);  //первый - объект, с которым применяется метод
		void mult(Budget B, Budget &C); //второй - вспомогательный объект нужный для 
		void div(Budget B, Budget &C);  //сохранения результата работы функции,
		void comp(Budget B);		   //чтобы не изменялись исходные объекты
};

void Budget::sum(Budget B, Budget &C) {
	C.prop = prop + B.prop;
	C.loan = loan + B.loan;
}
void Budget::sub(Budget B, Budget &C) {
	C.prop = prop - B.prop;
	C.loan = loan - B.loan;
}
void Budget::mult(Budget B, Budget &C) {
	C.prop = prop * B.prop;
	C.loan = loan * B.loan;
}
void Budget::div(Budget B, Budget &C) {
	try {
		cout << "Отношение собственных: ";
		if (B.prop == 0) throw "деление на ноль";
		C.prop = prop / B.prop;
		cout << C.prop << endl;
	}
	catch (char* str) {
		cout << "Ошибка: " << str << endl;
	}
	try {
		cout << "Отношение заемных: ";
		if (B.loan == 0) throw "деление на ноль";
		C.loan = loan / B.loan;
		cout << C.loan << endl;
	}
	catch (char* str) {
		cout << "Ошибка: " << str << endl;
	}
}
void Budget::comp(Budget B) {
	cout << "Собственные бюджеты: ";
	if (prop > B.prop) cout << "первый больше\n";
	else if (prop < B.prop) cout << "первый меньше\n";
	else cout << "равны\n";
	cout << "Заемные бюджеты: ";
	if (loan > B.loan) cout << "первый больше\n";
	else if (loan < B.loan) cout << "первый меньше\n";
	else cout << "равны\n";
}

void printmenu() {
	cout << "Меню команд:\n";
	cout << "1 - Ввести значения бюджетов\n";
	cout << "2 - Сумма частей бюджетов\n";
	cout << "3 - Модуль разности бюджетов\n";
	cout << "4 - Произведение частей бюджетов\n";
	cout << "5 - Отношение частей бюджетов\n";
	cout << "6 - Сравнение частей бюджетов\n";
	cout << "7 - Напечатать меню\n";
	cout << "0 - Выход\n";
}

void isok(double &num) {
	while (num < 0) {
		cout << "Введите значение >= 0" << endl;
		cin >> num;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	Budget X, Y, R; //объект R создается для подсчета операций между X и Y, чтобы их самих не изменять
	int command = 7;
	printmenu();
	cout.precision(16);
	cout << fixed;
	cout.precision(2);
	while (command != 0) {
		cout << "Введите номер команды -> ";
		cin >> command;
		switch (command) {
		case 1:
			cout << "Введите значения для первого бюджета:\n";
			cout << "Собственный: ";
			cin >> X.prop;
			isok(X.prop);
			cout << "Заемный: ";
			cin >> X.loan;
			isok(X.loan);
			cout << "Введите значения для второго бюджета:\n";
			cout << "Собственный: ";
			cin >> Y.prop;
			isok(Y.prop);
			cout << "Заемный: ";
			cin >> Y.loan;
			isok(Y.loan);
			cout << "Округленные: " << endl;
			cout << X.prop << "   " << X.loan << endl;
			cout << Y.prop << "   " << Y.loan << endl;
			break;
		case 2:
			X.sum(Y, R);
			cout << "Сумма частей собственного бюджета: " << R.prop << endl;
			cout << "Сумма частей заемного бюджета: " << R.loan << endl;
			break;
		case 3:
			X.sub(Y, R);
			if (R.prop < 0)cout << "Внимание! Получено отрицательное значение!" << endl;
			cout << "Разность собственных частей бюджета: " << R.prop << endl;
			if (R.loan < 0)cout << "Внимание! Получено отрицательное значение!" << endl;
			cout << "Разность заемных частей бюджета: " << R.loan << endl;
			break;
		case 4:
			X.mult(Y, R);
			cout << "Произведение собственных частей бюджета: " << R.prop << endl;
			cout << "Произведение заемных частей бюджета: " << R.loan << endl;
			break;
		case 5:
			X.div(Y, R);
			break;
		case 6:
			X.comp(Y);
			break;
		case 7:
			printmenu();
			break;
		case 0:
			break;
		default:
			cout << "Нет такой команды. Введите номер команды еще раз.\n";
		}
	}
}
