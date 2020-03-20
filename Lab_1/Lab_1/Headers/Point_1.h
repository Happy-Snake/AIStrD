#pragma once

class CStack
{
private:
	char *bottom;	//Указатель на 1й элемент в стеке (нужен для определения размера стека)
	char *top;		//Указатель на элемент, который будет введен 
	int size;		//Размер стека

	void resize();

public:
	CStack();

	void push(char c);		//Добавление эл-та

	bool pop();				//Удаление эл-та

	char get_top_item();	//Достать последний эл-т

	void print();			//Вывод текущего состояния

	void print_top_item();	//Вывод верхнего эл-та

	int get_size();			//Достать size

	~CStack();
};

void what_to_do_in_point_1();