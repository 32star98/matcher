#pragma once
#include "Unit.h"
//��ȫƥ�����ͣ��ں�һ���ַ�������
class Unit_1
{
public:
	const Unit* father;
	Unit_1(const Unit* father);
	~Unit_1();
	void init();
	bool test();
};

