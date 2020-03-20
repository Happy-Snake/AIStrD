#pragma once
#include "Tree.h"

void Control_keys(int& code, int& key);

void draw_menu(const char** menuItems, int sz, int current);

int main_menu(node* p);