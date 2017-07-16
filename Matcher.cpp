#include "stdafx.h"
#include "Matcher.h"

Matcher::Matcher(int state, char * sou, int pointer)
{
}

Matcher::Matcher(int state, char * sou, int pointer, Matcher * root, Matcher * father)
{
}

Matcher::~Matcher()
{
	if (!childs) delete(childs);
	if (!chars) delete(chars);
}
