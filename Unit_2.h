#pragma once
//��Χѡ���ں�һ���ַ���������ֻ������������С��ǡ��߼�
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

