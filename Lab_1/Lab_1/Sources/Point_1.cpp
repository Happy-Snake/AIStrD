#include <iostream>
#include "../Headers/Point_1.h"
#include "../Headers/Menu.h"

using namespace std;

CStack::CStack()		//Инициализация массива 
{
	bottom = new char[0];
	top = bottom;
	size = 0;
}

void CStack::push(char c)	//Добавление эл-та
{
	resize();				//Выделение пямяти под новый элемент
	*top = c;				//Запись нового эл-та в top и увеичение top
	top++;
}

void CStack::resize()	//Выделение памяти под новый эл-т
{
	char *newArray = new char[size + 1];		//Выделение памяти под новый масссив нового размера
	memcpy(newArray, bottom, size);				//Копирование существующего массива в новый
	top = newArray + size;
	delete[] bottom;
	bottom = newArray;
	size += 1;
}

bool CStack::pop()		//Удаление последнего символа 
{
	if (size > 0)
	{
		top--;		//Декрементирование указателя на последний элемент
		size--;
		return true;
	}
	return false;
}

char CStack::get_top_item()		//Посмотреть верхний элемент
{
	return *(top - 1);
}

void CStack::print()		//Вывод текущего состояния стека
{
	cout << "В стеке сейчас " << size << " элементов: ";
	for (char *element = bottom; element < top; element++)		//Проходит по всем указателям от первого до последнего
	{
		cout << " " << *element;
	}
	cout << "\n";
}

void CStack::print_top_item()		//Вывод верхнего элемента
{
	cout << " " << *(top - 1) << endl;
}

int CStack::get_size()		//Посмотреть size
{
	return size;
}

CStack::~CStack()		//Деструктор
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
		case 0:			//Вывести текущий стек
		{
			s.print();
			system("pause");
			break;
		}
		case 1:			//Добавить элемент
		{
			char new_item;
			std::cout << "Введите новый элемент стека: ";
			std::cin >> new_item;
			s.push(new_item);
			break;
		}
		case 2:			//Удалить элемент
		{
			std::cout << "Был удален элемент ";
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