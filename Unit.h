#pragma once
#include "Unit_1.h"
#include "Unit_2.h"
#include "Unit_3.h"
//��С����ģ��
//ֻ��ɾ��flow�����һ����
//����������Ҫ����unit_x�޸�(��С�ж���)
class Unit
{
public:
	int kind;			//���
	int point;			//����λ��,���ص���һ������������λ��
	int logic = true;	//�߼�
	int gate_nums = 1;	//������������
	int min_nums;
	int max_nums;	//0��ʾ��������
	int prefer;			//��������0��ʾ��������
	int state;			//����״̬������ֵ��1,0,e
	bool test();
	int test_unit();
	void settarget(char* tar);
	Unit_1* u1 = nullptr;
	Unit_2* u2 = nullptr;
	Unit_3* u3 = nullptr;
public:
	Unit(int kind);
	Unit(int kind, int gate,
		int prefer, int min, int max);
	~Unit();
private:
	void switcher();
	void predestroy();
};

