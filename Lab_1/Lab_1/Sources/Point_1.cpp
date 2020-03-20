#include <iostream>
#include "../Headers/Point_1.h"
#include "../Headers/Menu.h"

using namespace std;

CStack::CStack()		//������������� ������� 
{
	bottom = new char[0];
	top = bottom;
	size = 0;
}

void CStack::push(char c)	//���������� ��-��
{
	resize();				//��������� ������ ��� ����� �������
	*top = c;				//������ ������ ��-�� � top � ��������� top
	top++;
}

void CStack::resize()	//��������� ������ ��� ����� ��-�
{
	char *newArray = new char[size + 1];		//��������� ������ ��� ����� ������� ������ �������
	memcpy(newArray, bottom, size);				//����������� ������������� ������� � �����
	top = newArray + size;
	delete[] bottom;
	bottom = newArray;
	size += 1;
}

bool CStack::pop()		//�������� ���������� ������� 
{
	if (size > 0)
	{
		top--;		//����������������� ��������� �� ��������� �������
		size--;
		return true;
	}
	return false;
}

char CStack::get_top_item()		//���������� ������� �������
{
	return *(top - 1);
}

void CStack::print()		//����� �������� ��������� �����
{
	cout << "� ����� ������ " << size << " ���������: ";
	for (char *element = bottom; element < top; element++)		//�������� �� ���� ���������� �� ������� �� ����������
	{
		cout << " " << *element;
	}
	cout << "\n";
}

void CStack::print_top_item()		//����� �������� ��������
{
	cout << " " << *(top - 1) << endl;
}

int CStack::get_size()		//���������� size
{
	return size;
}

CStack::~CStack()		//����������
{
	delete[] bottom;
}

void what_to_do_in_point_1()
{
	int answer;
	CStack s;
	do
	{
		answer = point_1_menu();
		switch (answer)
		{
		case 0:			//������� ������� ����
		{
			s.print();
			system("pause");
			break;
		}
		case 1:			//�������� �������
		{
			char new_item;
			std::cout << "������� ����� ������� �����: ";
			std::cin >> new_item;
			s.push(new_item);
			break;
		}
		case 2:			//������� �������
		{
			std::cout << "��� ������ ������� ";
			s.print_top_item();
			if (s.pop())
			{
				system("pause");
			}
			break;
		}
		}
	} while (answer != 3);
	system("pause");
}