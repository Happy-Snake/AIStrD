#include <windows.h>
#include <iostream>
#include "../Headers/Menu.h"
#include "../Headers/Tree.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	cout << "Введите 1й элемент дерева: ";
	int key;
	cin >> key;
	node r(key);
	node* root = &r;
	node* found;;
	int new_key, find;
	short answer;
	do
	{
		answer = main_menu(root);
		switch (answer)
		{
		case 0:
			cout << "Введите новое значение: ";
			cin >> new_key;
			root = insert(root, new_key);
			break;
		case 1:
			cout << "Введите искомый элемент: ";
			cin >> find;
			found = search(root, find);
			if (found == NULL)
				cout << "Такого элемента нет";
			else
				cout << found->key;
			break;
		case 2:
			cout << "Введите удаляемое значение: ";
			int remove_key;
			cin >> remove_key;
			remove(root, remove_key);
			cout << endl;
			break;
			}
		system("pause");
		system("cls");
	} while (answer != 3);
	return 0;
}