#pragma once
//完全匹配类型，内含一个字符（串）
class Unit;
class Unit_1
{
public:
	const Unit* father;
	char* sou;
	char* target;
	Unit_1(const Unit* father);
	~Unit_1();
	void init();
	bool test(int point);
};

