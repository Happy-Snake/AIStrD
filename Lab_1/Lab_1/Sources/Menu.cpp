#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <string>
#include <iostream>

#include "../Headers/Menu.h"
#include "../Headers/Point_1.h"

using namespace std;

void Control_keys(int &code, int &key)		//Дожидается ввода одного из управляющих симвволов, изменяет ключ
{
	code = _getch();
	if (code == 224)
	{
		code = _getch();
		if (code == 80) key++;
		if (code == 72) key--;
	}
};

void draw_menu(const char **menuItems, int sz, int current)		//Вывод позиций меню, -> выводится у позиции, на которую указывает актуальный ключ
{
	for (int i = 0; i < sz; ++i)
		cout << setw(3) << (current == i ? "->" : "") << menuItems[i] << endl;
};

int main_menu()
{
	SetConsoleOutputCP(1251);
	int key = 0;
	int code;
	const char *items[] = { "Пункт 1й: стек", "Пункт 2й: дек", "Пункт 3й", "Выход" };		//Массив позиций меню
	do
	{
		system("cls");
		cout << "Что необходимо сделать?:" << endl;
		key = (key + 4) % 4;
		draw_menu(items, 4, key);			//Передача массива позиций в ф-ю, выводящую меню
		Control_keys(code, key);			//Считывание следующего управляющего символа
	} while (code != 13);
	system("cls");
	return key;
};

int point_1_menu()		//Меню для работы со стеком
{
	SetConsoleOutputCP(1251);
	int key = 0;
	int code;
	const char *items[] = { "Вывести текущий стек", "Добавить элемент", "Удалить элемент", "Выход" };
	do
	{
		system("cls");
		cout << "Что необходимо сделать?:" << endl;
		key = (key + 4) % 4;
		draw_menu(items, 4, key);
		Control_keys(code, key);
	} while (code != 13);
	system("cls");
	return key;
}

int point_2_menu()		//Меню для работы со декой
{
	SetConsoleOutputCP(1251);
	int key = 0;
	int code;
	const char *items[] = { "Вывести текущий дек", "Добавить элемент в конец", "Добавить элемент в начало", "Удалить элемент с конца", "Удалить элемент из начала", "Выход" };
	do
	{
		system("cls");
		cout << "Что необходимо сделать?:" << endl;
		key = (key + 6) % 6;
		draw_menu(items, 6, key);
		Control_keys(code, key);
	} while (code != 13);
	system("cls");
	return key;
}

string point_3_menu()		//Меню для работы с третьим пунктом
{
	string input_string;
	cout << "Введите выражение в инфиксной форме: ";
	cin >> input_string;
	return input_string;
}