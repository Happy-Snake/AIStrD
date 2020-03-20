#include <iostream>
#include <string>
#include "../Headers/Point_1.h"
#include "../Headers/Point_3.h"
#include "../Headers/Menu.h"

using namespace std;

string point_3_main_func(string input_str)
{
	string output_str;
	int j = 0;
	CStack operations;		//���� �� ������� ��������
	for (int i = 0; i < input_str.length(); i++)		//���� �� �������� ������
	{
		if (input_str[i] == '(')		//���� ��������� ')', ��������� � ����
			operations.push('(');
		else 
			if (input_str[i] == '+' or input_str[i] == '-')		//���� ��������� '+'/'-', ��������� � ������� ������ ��� ����� �� ����� � ������ ��� ������� �����������, ����� ��������� � ���� ���� ����
			{			
				while (operations.get_top_item() == '+' or operations.get_top_item() == '-' or operations.get_top_item() == '*' or operations.get_top_item() == '/')
				{
					output_str += operations.get_top_item();
					operations.pop();
					j++;
				}
				operations.push(input_str[i]);
			}
			else 
				if (input_str[i] == '*' or input_str[i] == '/')		//���� ��������� '*' ��� '/', ��������� � ������� ������ ��� ����� �� ����� � ������ ��� ������� �����������, ����� ��������� � ���� ���� ����
				{
					while (operations.get_top_item() == '*' or operations.get_top_item() == '/')
					{
						output_str += operations.get_top_item();
						operations.pop();
						j++;
					}
					operations.push(input_str[i]);
				}
				else 
					if (input_str[i] == ')')		//���� ��������� ')', ��������� �� ����� ��� ����� �� ������� '(', ������� �� ����� '('
					{
						while (operations.get_top_item() != '(')
						{
							output_str += operations.get_top_item();
							operations.pop();
							j++;
						}
						operations.pop();
					}
					else
						if (operations.get_size() == 0 and (input_str[i] >= 'a' and input_str[i] <= 'z' or input_str[i] >= 'A' and input_str[i] <= 'Z' or input_str[i] >= '1' and input_str[i] <= '2'))
						{
							output_str += input_str[i];
							j++;
						}
						else
							{
								output_str += input_str[i];
								j++;
							}
	
	}
	while (operations.get_size() > 0)		//��������� ���������� ����� ������� �� �����
	{
		if (operations.get_top_item() != '(')
		{
			output_str += operations.get_top_item();
			j++;
		}
		operations.pop();
	}
	return output_str;
}
