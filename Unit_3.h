#pragma once
//�ظ��ȣ�������
//�������ʱ�����
class Unit;
class Unit_3
{
public:
	const Unit* father;
	char* sou;
	char* target;
	Unit_3(const Unit* father);
	~Unit_3();
	void init();
	bool test(int point);
};

