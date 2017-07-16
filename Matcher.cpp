#include "stdafx.h"
#include "Matcher.h"

Matcher::Matcher(const char * sou)
{
	this->sou = (char*)sou;
	this->state = 0;
	this->pointer = 0;
	this->root = 0;
	this->father = 0;
	init();
}

Matcher::Matcher(int state, char * sou, int pointer, Matcher * root, Matcher * father)
{
	this->state = state;
	this->sou = sou;
	this->pointer = pointer;
	this->root = root;
	this->father = father;
	init();
}

Matcher::~Matcher()
{
	if (!childs) delete(childs);
	if (!chars) delete(chars);
}

void Matcher::init()
{
	if (state == 0) {
		for (;pointer;pointer++) {

		}
	}
	else if (state == 1) {

	}
	/*else if (state == 2) {

	}
	else if (state == 3) {

	}*/
	else
		matcher_error();
}

void Matcher::match(char * ins)
{
}

void Matcher::matcher_ok(Matcher * child, int endpoint)
{
}

void Matcher::matcher_error()
{
}

int Matcher::getlength(char * ins)
{
	int i = 0;
	while (ins[i] != '\0') i++;
	return i < 100 ? i : 100;
}

int Matcher::belongs(char c)
{
	const char* S0 = "([{";	//初始化新序列
	const char* S1 = ".|^\\";
	const char* E0 = ")]}"; //终止序列
	const char* E1 = "+*?";
	const char* Ns = "0123456789";//数字类
	if (state == 0) {
	}
	else if (state == 1) {

	}
	else if (state == 2) {

	}
	else if (state == 3) {

	}
	else
	return -1;
}
