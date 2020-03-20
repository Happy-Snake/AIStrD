#pragma once

struct node // структура для представления узлов дерева
{
	int key;
	unsigned char height;
	node* left;
	node* right;
	node(int k)
	{
		key = k;
		left = right = 0;
		height = 1;
	}
};

void fixheight(node* p);

node* balance(node* p);

node* insert(node* p, int k);

node* findmin(node* p);

node* removemin(node* p);

node* remove(node* p, int k);

node* search(node* p, int k);

void print_tree(node* p, int level);

unsigned char height(node* p);

int bfactor(node* p);

node* rotateright(node* p);

node* rotateleft(node* q);