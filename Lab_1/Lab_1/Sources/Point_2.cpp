#include <iostream>
#include "../Headers/Point_2.h"
#include "../Headers/Menu.h"

using namespace std;

CDeq::CDeq()		//������������� ������� 
{
	bottom = new char[0];
	top = bottom;
	size = 0;
}

void CDeq::push_to_top(char c)	//���������� ��-��
{
	resize_to_top();				//��������� ������ ��� ����� �������
	*top = c;				//������ ������ ��-�� � top � ��������� top
	top++;
}

void CDeq::push_to_bottom(char c)	//���������� ��-��
{
	resize_to_bottom();				//��������� ������ ��� ����� �������
	bottom--;
	*bottom = c;				//������ ������ ��-�� � top � ��������� top
}

void CDeq::resize_to_top()	//��������� ������ ��� ����� ��-� � �����
{
	char *newArray = new char[size + 1];
	memcpy(newArray, bottom, size);
	top = newArray + size;
	delete[] bottom;
	bottom = newArray;
	size += 1;
}

void CDeq::resize_to_bottom()	//��������� ������ ��� ����� ��-� � ������ 
{
	char *newArray = new char[size + 1];
	memcpy(newArray + 1, bottom , size);
	top = newArray + size + 1;
	delete[] bottom;
	bottom = newArray + 1;
	size += 1;
}

void CDeq::pop_from_top()		//�������� ���������� ��-�� � �����
{
	if (size > 0)
	{
		this->print_top_item();
		cout << endl;
		system("pause");
		this->print_top_item();
		top--;
		size--;
	}
}

void CDeq::pop_from_bottom()		//�������� ���������� ��-�� � ������
{
	if (size > 0)
	{
		this->print_bottom_item();
		cout << endl;
		system("pause");
		bottom++;
		size--;
	}
}

void CDeq::print()		//����� �������� ��������� �����
{
	cout << "Stack currently holds " << size << " items: ";
	for (char *element = bottom; element < top; element++)
	{
		cout << " " << *element;
	}
	cout << "\n";
}

void CDeq::print_top_item()		//����� �������� ��������
{
	cout << " " << *(top - 1);
}

void CDeq::print_bottom_item()		//����� ������� ��������
{
	cout << " " << *bottom;
}

CDeq::~CDeq()		//����������
{
	delete[] bottom;
}

void what_to_do_in_point_2()
{
	int answer;
	CDeq d;
	do
	{
		answer = point_2_menu();
		switch (answer)
		{
		case 0:			 //������� ������� ���
		{
			d.print();
			system("pause");
			break;
		}
		case 1:			//�������� ������� � �����
		{
			char new_item;
			std::cout << "������� ����� ������� �����: ";
			std::cin >> new_item;
			d.push_to_top(new_item);
			break;
		}
		case 2:			//�������� ������� � ������
		{
			char new_item;
			std::cout << "������� ����� ������� �����: ";
			std::cin >> new_item;
			d.push_to_bottom(new_item);
			break;
		}
		case 3:			//������� ������� � �����
		{
			std::cout << "��� ������ ������� ";
			d.pop_from_top();
			break;
		}
		case 4:			//������� ������� �� ������
		{
			std::cout << "��� ������ ������� ";
			d.pop_from_bottom();
			break;
		}
		}
	} while (answer != 5);
	system("pause");
}