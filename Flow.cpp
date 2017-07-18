#include "stdafx.h"
#include "Flow.h"


Flow::Flow()
{
}

Flow * Flow::add(Flow * sou)
{
	if (branches == 0) {
		return setflow(sou);
	}
	branches++;
	Flow* t = new Flow();
	sou->ph_nex = t;
	t->ph_pre = sou;
	t->tree_pre = this;
	return t;
}

Flow * Flow::end(Flow * sou)
{
	Flow* t = new Flow();
	Flow* p;
	int i;						//终结子树
	sou->ph_nex = t;
	t->ph_pre = sou;
	t->tree_pre = tree_pre;
	p = this;
	while (p != sou) {
		p = p->ph_nex;
		if (p->next == 0) {
			p->next = t;
		}
	}
	return t;
}


Flow::~Flow()
{
	if (inner)
		delete(inner);
	if (ph_pre)
		delete(ph_pre);
}

Flow * Flow::setflow(Flow * sou)
{
	branches++;
	Flow* next;
	next = new Flow();
	sou->next = next;
	next->ph_pre = sou;				//子支起点保留父节点信息
	sou->ph_nex = next;
	return next;
}

Flow * Flow::addbranch(Flow* sou)
{
	return add(sou);
}

Flow * Flow::endbranches(Flow* sou)
{
	return end(sou);
}

bool Flow::test(const char * target, int point = 0)	//从指定位开始
{
	if (branches == 0) {
		return true;
	}
	inner->point = point;
	inner->target = (char*)target;
	if (!inner->test()) {
		return false;
	}
	else {
		if (branches == 1) {
			return next->test(target, inner->point);
		}
		else {
			Flow* p = this;
			int i;
			bool ans = false;
			for (i = 0;i < branches;i++) {
				while (p!=0 && p->tree_pre != this) p = p->next;	//注意防止崩溃
				ans = ans || p->test(target, inner->point);
			}
			return ans;
		}
	}
}
