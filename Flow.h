#pragma once
#include"Unit.h"
//���̿�����
class Flow
{
public:

	Flow();
	~Flow();
	Flow* setflow(Flow* sou);			//��������
	Flow* addbranch(Flow* sou);			//��֧����
	Flow* endbranches(Flow* sou);		//��֧�������ӿ���ã�
	//////////////////////////�ڲ�����

	Flow* ph_next = 0;		//�����ϵ����Խṹ
	Flow* pre = 0;			//�߼��ϼ�
	Flow* tree_pre = 0;		//����̬�ϼ�
	Flow* nex = 0;			//�߼��¼�,��Ϊ�����ڵ���ָ���һ���ӽڵ�
private:
	int branches = 1;
	Flow* add(Flow* sou);				//����ʵ��
	Flow* end(Flow* sou);
};
