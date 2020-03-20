#include <iostream>
#include "../Headers/Point_2.h"
#include "../Headers/Menu.h"

using namespace std;

CDeq::CDeq()		//Инициализация массива 
{
	bottom = new char[0];
	top = bottom;
	size = 0;
}

void CDeq::push_to_top(char c)	//Добавление эл-та
{
	resize_to_top();				//Выделение пямяти под новый элемент
	*top = c;				//Запись нового эл-та в top и увеичение top
	top++;
}

void CDeq::push_to_bottom(char c)	//Добавление эл-та
{
	resize_to_bottom();				//Выделение пямяти под новый элемент
	bottom--;
	*bottom = c;				//Запись нового эл-та в top и увеичение top
}

void CDeq::resize_to_top()	//Выделение памяти под новый эл-т в конце
{
	char *newArray = new char[size + 1];
	memcpy(newArray, bottom, size);
	top = newArray + size;
	delete[] bottom;
	bottom = newArray;
	size += 1;
}

void CDeq::resize_to_bottom()	//Выделение памяти под новый эл-т в начале 
{
	char *newArray = new char[size + 1];
	memcpy(newArray + 1, bottom , size);
	top = newArray + size + 1;
	delete[] bottom;
	bottom = newArray + 1;
	size += 1;
}

void CDeq::pop_from_top()		//Удаление последнего эл-та с конца
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

void CDeq::pop_from_bottom()		//Удаление последнего эл-та с начала
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

void CDeq::print()		//Вывод текущего состояния стека
{
	cout << "Stack currently holds " << size << " items: ";
	for (char *element = bottom; element < top; element++)
	{
		cout << " " << *element;
	}
	cout << "\n";
}

void CDeq::print_top_item()		//Вывод верхнего элемента
{
	cout << " " << *(top - 1);
}

void CDeq::print_bottom_item()		//Вывод нижнего элемента
{
	cout << " " << *bottom;
}

CDeq::~CDeq()		//Деструктор
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
		case 0:			 //Вывести текущий дек
		{
			d.print();
			system("pause");
			break;
		}
		case 1:			//Добавить элемент в конец
		{
			char new_item;
			std::cout << "Введите новый элемент стека: ";
			std::cin >> new_item;
			d.push_to_top(new_item);
			break;
		}
		case 2:			//Добавить элемент в начало
		{
			char new_item;
			std::cout << "Введите новый элемент стека: ";
			std::cin >> new_item;
			d.push_to_bottom(new_item);
			break;
		}
		case 3:			//Удалить элемент с конца
		{
			std::cout << "Был удален элемент ";
			d.pop_from_top();
			break;
		}
		case 4:			//Удалить элемент из начала
		{
			std::cout << "Был удален элемент ";
			d.pop_from_bottom();
			break;
		}
		}
	} while (answer != 5);
	system("pause");
}