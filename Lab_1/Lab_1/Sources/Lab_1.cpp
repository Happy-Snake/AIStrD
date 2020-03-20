#include <iostream>
#include <string>
#include "../Headers/Point_1.h"
#include "../Headers/Point_2.h"
#include "../Headers/Point_3.h"
#include "../Headers/Menu.h"

using namespace std;

int main()
{
	int answer;
	do
	{
		answer = main_menu();		//Выбор режима работы
		switch (answer)
		{
		case 0:
		{
			what_to_do_in_point_1();		//Выбор режима работы стека
			break;
		}
		case 1:
		{
			what_to_do_in_point_2();		//Выбор режима работы деки
			break;
		}
		case 2:
		{
			string str = point_3_main_func(point_3_menu());		//Вызов рабочей функции
			cout << str << endl;
			system("pause");
			break;
		}
		}
	} while (answer != 3);
	system("pause");
	return 0;
}