#pragma once
#include "Unit.h"
//�ظ��ȣ�������
//�������ʱ�����
class Unit_3
{
public:
	const Unit* father;
	Unit_3(const Unit* father);
	~Unit_3();
	void init();
	bool test();
};

