#include "stdafx.h"
#include "Unit.h"



bool Unit::test()
{
	int t_point;
	int i;
	bool ends = true;
	if (prefer) {
		for (i = 0;i < min_nums;i++) {
			if (ends)
				ends = test_unit();
		}
		if (ends) {
			if (max_nums == 0) {
				t_point = point;
				while (test_unit())
					t_point = point;
				point = t_point;
			}
			else {
				for(;i<max_nums;i++)
					t_point = point;
				point = t_point;
			}
		}
	}
	else {
		for (i = 0;i < min_nums;i++) {
			if (ends)
				ends = test_unit();
		}
	}
	return ends;
}

bool Unit::test_unit()
{
	switch (kind) {
	case 0:
	case 1:
		return u1->test();
		break;
	case 2:
		return logic^u2->test();	//非逻辑处理完成，仅针对[]有效
		break;
	case 3:
		return u3->test();
		break;
	default:
		printf("在分类时出现错误，\n错误位点unit.cpp");

	}
	return false;
}

Unit::Unit(int kind, const char * sou)
{
	this->kind = kind;
	this->sou = (char*) sou;
	this->gate_nums = 1;
}

Unit::Unit(int kind, const char * sou, int gate, int prefer, int min, int max = 0)
{
	this->kind = kind;
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
		break;
	case 2:
		u2 = new Unit_2(this);
		break;
	case 3:
		u3 = new Unit_3(this);
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
