#pragma once

class CStack
{
private:
	char *bottom;	//��������� �� 1� ������� � ����� (����� ��� ����������� ������� �����)
	char *top;		//��������� �� �������, ������� ����� ������ 
	int size;		//������ �����

	void resize();

public:
	CStack();

	void push(char c);		//���������� ��-��

	bool pop();				//�������� ��-��

	char get_top_item();	//������� ��������� ��-�

	void print();			//����� �������� ���������

	void print_top_item();	//����� �������� ��-��

	int get_size();			//������� size

	~CStack();
};

void what_to_do_in_point_1();