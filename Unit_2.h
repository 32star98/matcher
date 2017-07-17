#pragma once
#include "Unit.h"
//范围选择，内含一个字符（集）
class Unit_2
{
public:
	const Unit* father;
	Unit_2(const Unit* father);
	~Unit_2();
	void init();
	bool test();
};

