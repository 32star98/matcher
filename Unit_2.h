#pragma once
#include "Unit.h"
//��Χѡ���ں�һ���ַ�������
class Unit_2
{
public:
	const Unit* father;
	Unit_2(const Unit* father);
	~Unit_2();
	void init();
	bool test();
};

