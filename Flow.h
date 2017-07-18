#pragma once
#include"Unit.h"
//���̿�����
//��֧���¼�����ָ���һ�����ã�������������������
//
class Flow
{
public:

	Flow();
	~Flow();
	Flow* setflow(Flow* sou);			//��������
	Flow* addbranch(Flow* sou);			//��֧����
	Flow* endbranches(Flow* sou);		//��֧������������ã�
	Unit* inner = 0;
	bool test(const char* target, int point);
	//////////////////////////�ڲ�����

	Flow* ph_nex = 0;		//����ṹ���¼�
	Flow* ph_pre = 0;			//�����ϼ�
	Flow* tree_pre = 0;		//����̬�ϼ�
	Flow* next = 0;		//���ṹ���¼�
private:
	int branches = 0;
	Flow* add(Flow* sou);				//����ʵ��
	Flow* end(Flow* sou);
};
