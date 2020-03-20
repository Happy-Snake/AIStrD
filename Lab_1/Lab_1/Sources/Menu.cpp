#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <string>
#include <iostream>

#include "../Headers/Menu.h"
#include "../Headers/Point_1.h"

using namespace std;

void Control_keys(int &code, int &key)		//���������� ����� ������ �� ����������� ���������, �������� ����
{
	code = _getch();
	if (code == 224)
	{
		code = _getch();
		if (code == 80) key++;
		if (code == 72) key--;
	}
};

void draw_menu(const char **menuItems, int sz, int current)		//����� ������� ����, -> ��������� � �������, �� ������� ��������� ���������� ����
{
	for (int i = 0; i < sz; ++i)
		cout << setw(3) << (current == i ? "->" : "") << menuItems[i] << endl;
};

int main_menu()
{
	SetConsoleOutputCP(1251);
	int key = 0;
	int code;
	const char *items[] = { "����� 1�: ����", "����� 2�: ���", "����� 3�", "�����" };		//������ ������� ����
	do
	{
		system("cls");
		cout << "��� ���������� �������?:" << endl;
		key = (key + 4) % 4;
		draw_menu(items, 4, key);			//�������� ������� ������� � �-�, ��������� ����
		Control_keys(code, key);			//���������� ���������� ������������ �������
	} while (code != 13);
	system("cls");
	return key;
};

int point_1_menu()		//���� ��� ������ �� ������
{
	SetConsoleOutputCP(1251);
	int key = 0;
	int code;
	const char *items[] = { "������� ������� ����", "�������� �������", "������� �������", "�����" };
	do
	{
		system("cls");
		cout << "��� ���������� �������?:" << endl;
		key = (key + 4) % 4;
		draw_menu(items, 4, key);
		Control_keys(code, key);
	} while (code != 13);
	system("cls");
	return key;
}

int point_2_menu()		//���� ��� ������ �� �����
{
	SetConsoleOutputCP(1251);
	int key = 0;
	int code;
	const char *items[] = { "������� ������� ���", "�������� ������� � �����", "�������� ������� � ������", "������� ������� � �����", "������� ������� �� ������", "�����" };
	do
	{
		system("cls");
		cout << "��� ���������� �������?:" << endl;
		key = (key + 6) % 6;
		draw_menu(items, 6, key);
		Control_keys(code, key);
	} while (code != 13);
	system("cls");
	return key;
}

string point_3_menu()		//���� ��� ������ � ������� �������
{
	string input_string;
	cout << "������� ��������� � ��������� �����: ";
	cin >> input_string;
	return input_string;
}