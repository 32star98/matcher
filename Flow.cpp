#include "stdafx.h"
#include "Flow.h"


Flow::Flow()
{
}


Flow::~Flow()
{
}

Flow * Flow::setflow(Flow * sou)
{
	sou = new Flow();
	return sou->ph_next;
}
