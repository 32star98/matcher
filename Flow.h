#pragma once
#include"Unit.h"
//流程控制器
class Flow
{
public:
	~Flow();
	Flow* setflow(Flow* sou);

	Flow* ph_next = 0;		//物理上的线性结构

private:
	Flow();
};
