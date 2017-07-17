#pragma once
#include"Unit.h"
//流程控制器
//分支的下级处理：指向第一个引用，依次搜索所有引用者
class Flow
{
public:

	Flow();
	~Flow();
	Flow* setflow(Flow* sou);			//线性延伸
	Flow* addbranch(Flow* sou);			//分支建立
	Flow* endbranches(Flow* sou);		//分支结束（子块调用）
	Unit* inner = 0;
	bool test(const char* target, int point);
	//////////////////////////内部调用

	Flow* next = 0;		//线性结构，下级
	Flow* ph_pre = 0;			//物理上级
	Flow* tree_pre = 0;		//树形态上级
	//Flow* nex = 0;			//逻辑下级,若为树父节点则指向第一个子节点
private:
	int branches = 1;
	Flow* add(Flow* sou);				//父块实现
	Flow* end(Flow* sou);
};
