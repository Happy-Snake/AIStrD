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
	CStack operations;		//—тек со знаками операций
	for (int i = 0; i < input_str.length(); i++)		//÷икл по исходной строке
	{
		if (input_str[i] == '(')		//≈сли встречаем ')', добавл€ем в стек
			operations.push('(');
		else 
			if (input_str[i] == '+' or input_str[i] == '-')		//≈сли встречаем '+'/'-', выгружаем в выходну строку все знаки из стека с равным или большим приорететом, потом добавл€ем в стек этот знак
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
				if (input_str[i] == '*' or input_str[i] == '/')		//≈сли встречаем '*' или '/', выгружаем в выходну строку все знаки из стека с равным или большим приорететом, потом добавл€ем в стек этот знак
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
					if (input_str[i] == ')')		//≈сли встречаем ')', выгружаем из стека все знаки до первого '(', удал€ем из стека '('
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
	while (operations.get_size() > 0)		//¬ыгружаем остаточные знаки пераций из стека
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
