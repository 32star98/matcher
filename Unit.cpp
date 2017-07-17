#include "stdafx.h"
#include "Unit.h"



Unit::Unit(int kind, int point, const char * sou)
{
	this->kind = kind;
	this->point = point;
	this->sou = (char*) sou;
	this->gate_nums = 1;
}

Unit::Unit(int kind, int point, const char * sou, int gate, int prefer, int min, int max = 0)
{
	this->kind = kind;
	this->point = point;
	this->sou = (char*)sou;
	this->gate_nums = gate;
	this->prefer = prefer;
	this->min_nums = min;
	this->max_nums = max;
}

Unit::~Unit()
{
	predestroy();
}

void Unit::switcher()
{
	switch (kind){
	case 0:
	case 1:
		u1 = new Unit_1(this);
		init = u1->init;
		test = u1->test;
		break;
	case 2:
		u2 = new Unit_2(this);
		init = u2->init;
		test = u2->test;
		break;
	case 3:
		u3 = new Unit_3(this);
		init = u3->init;
		test = u3->test;
		break;
	default:
		printf("在分类时出现错误，\n错误位点unit.cpp");

	}
}

void Unit::predestroy()
{
	switch (kind) {
	case 0:
	case 1:if (u1)delete(u1);
		break;
	case 2:if (u2)delete(u2);
		break;
	case 3:if (u3)delete(u3);
		break;
	default:
		printf("在拆除时出错，\n错误位点unit.cpp");
	}
}
