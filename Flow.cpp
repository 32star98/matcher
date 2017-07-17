#include "stdafx.h"
#include "Flow.h"


Flow::Flow()
{
}

Flow * Flow::add(Flow * sou)
{
	branches++;
	Flow* t = new Flow();
	sou->next = t;
	t->ph_pre = sou;
	t->tree_pre = this;
	return t;
}

Flow * Flow::end(Flow * sou)
{
	Flow* t = new Flow();
	Flow* p;
	int i;						//�ս�����
	sou->next = t;
	t->ph_pre = sou;
	t->tree_pre = tree_pre;
	p = this->next;					//p����ʱ����
	for (i = 2;i < branches;i++) {				//��ȥ��β
		while (p->next->tree_pre != this) p = p->next;
		p->next = t;
	}
	return nullptr;
}


Flow::~Flow()
{
	if(ph_pre)
	delete(ph_pre);
}

Flow * Flow::setflow(Flow * sou)
{
	Flow* next;
	next = new Flow();
	sou->next = next;
	next->ph_pre = sou;				//��֧��㱣�����ڵ���Ϣ
	return next;
}

Flow * Flow::addbranch(Flow * sou)
{
	Flow* tem = sou;
	while (tem->ph_pre->tree_pre == 0) {
		tem = tem->ph_pre;
	}
	return tem->tree_pre->add(sou);
}

Flow * Flow::endbranches(Flow * sou)
{
	Flow* tem = sou;
	while (tem->ph_pre->tree_pre == 0) {
		tem = tem->ph_pre;
	}
	return tem->tree_pre->end(sou);
}

bool Flow::test(const char * target, int point = 0)	//��ָ��λ��ʼ
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
				while (p->tree_pre != this) p = p->next;
				ans = ans || p->test(target, inner->point);
			}
			return ans;
		}
	}
}
