#pragma once
#include"Unit.h"
//���̿�����
class Flow
{
public:
	~Flow();
	Flow* setflow(Flow* sou);

	Flow* ph_next = 0;		//�����ϵ����Խṹ

private:
	Flow();
};
