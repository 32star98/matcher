#pragma once
#include "Unit_1.h"
#include "Unit_2.h"
#include "Unit_3.h"
//最小控制模块
class Unit
{
public:
	int kind;			//类别
	int point;			//操作位点,返回到下一个操作不到的位置
	int logic = true;	//逻辑
	char* sou;
	char* target;
	int gate_nums = 1;	//次数控制掩码
	int min_nums;
	int max_nums;	//0表示不设上限
	int prefer;			//操作倾向，0表示尽可能少
	int state;			//操作状态（返回值）1,0,e
	bool test();
	Unit_1* u1 = nullptr;
	Unit_2* u2 = nullptr;
	Unit_3* u3 = nullptr;
public:
	Unit(int kind, int point, const char* sou);
	Unit(int kind, int point, const char* sou, int gate,
		int prefer, int min, int max);
	~Unit();
private:
	void switcher();
	void predestroy();
};

