#include "stdafx.h"
#include "Flow.h"


Flow::Flow()
{
}

Flow * Flow::add(Flow * sou)
{
	branches++;
	Flow* t = new Flow();
	sou->ph_next = t;
	t->pre = sou;
	t->tree_pre = this;
	return t;
}

Flow * Flow::end(Flow * sou)
{
	Flow* t = new Flow();
	sou->ph_next = t;
	t->pre = sou;
	t->tree_pre = tree_pre;
	return nullptr;
}


Flow::~Flow()
{
	if(pre)
	delete(pre);
}

Flow * Flow::setflow(Flow * sou)
{
	Flow* next;
	next = new Flow();
	sou->ph_next = next;
	next->tree_pre = sou->tree_pre;
	next->pre = sou;
	sou->tree_pre = 0;					//子支末端保留父节点信息
	return next;
}

Flow * Flow::addbranch(Flow * sou)
{
	return tree_pre->add(sou);
}

Flow * Flow::endbranches(Flow * sou)
{
	return tree_pre->end(sou);
}
