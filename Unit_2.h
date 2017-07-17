#pragma once
//范围选择，内含一个字符（集），只有这里允许进行“非”逻辑
class Unit;
class Unit_2
{
public:
	const Unit* father;
	Unit_2(const Unit* father);
	~Unit_2();
	void init();
	bool test();
};

