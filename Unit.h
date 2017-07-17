#pragma once
#include "Unit_1.h"
#include "Unit_2.h"
#include "Unit_3.h"
//��С����ģ��
class Unit
{
public:
	int kind;			//���
	int point;			//����λ��,���ص���һ������������λ��
	int logic = true;	//�߼�
	char* sou;
	int gate_nums = 1;	//������������
	int min_nums;
	int max_nums;	//0��ʾ��������
	int prefer;			//��������0��ʾ��������
	int state;			//����״̬������ֵ��1,0,e
	void(*init)(...);
	bool(*test)();
public:
	Unit(int kind, int point, const char* sou);
	Unit(int kind, int point, const char* sou, int gate,
		int prefer, int min, int max = 0);
	~Unit();
	void match() {}
private:
	Unit_1* u1 = 0;
	Unit_2* u2 = 0;
	Unit_3* u3 = 0;
	void switcher();
	void predestroy();
};

