#pragma once

class CDeq
{
private:
	char *bottom;	//Указатель на 1й элемент в стеке (нужен для определения размера стека)
	char *top;		//Указатель на элемент, который будет введен 
	int size;		//Размер стека

	void resize_to_top();

	void print_top_item();

	void print_bottom_item();

public:
	CDeq();

	void push_to_top(char c);

	void push_to_bottom(char c);

	void resize_to_bottom();

	void pop_from_top();

	void pop_from_bottom();

	void print();

	~CDeq();
};

void what_to_do_in_point_2();