#pragma once
#include"Unit.h"
//���̿�����
//��֧���¼�����ָ���һ�����ã�������������������
class Flow
{
public:

	Flow();
	~Flow();
	Flow* setflow(Flow* sou);			//��������
	Flow* addbranch(Flow* sou);			//��֧����
	Flow* endbranches(Flow* sou);		//��֧�������ӿ���ã�
	Unit* inner = 0;
	bool test(const char* target, int point);
	//////////////////////////�ڲ�����

	Flow* next = 0;		//���Խṹ���¼�
	Flow* ph_pre = 0;			//�����ϼ�
	Flow* tree_pre = 0;		//����̬�ϼ�
	//Flow* nex = 0;			//�߼��¼�,��Ϊ�����ڵ���ָ���һ���ӽڵ�
private:
	int branches = 1;
	Flow* add(Flow* sou);				//����ʵ��
	Flow* end(Flow* sou);
};
