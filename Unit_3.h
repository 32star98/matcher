#pragma once
#include "Unit.h"
//重复度，上下限
//这个或许时多余的
class Unit_3
{
public:
	const Unit* father;
	Unit_3(const Unit* father);
	~Unit_3();
	void init();
	bool test();
};

