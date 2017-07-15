#include "stdafx.h"
#include "Matcher.h"

Matcher::Matcher()
{
}

Matcher::Matcher(const char * init)
{
	initer(init);
}

Matcher::~Matcher()
{
	if (sample != 0) {
		delete(sample);
	}
	if (ans != 0) {
		delete(ans);
	}
}

char * Matcher::initer(const char * init)
{
	sample = (char*)init;
	slip();
	return nullptr;
}

bool Matcher::match(char* target)
{
	return false;
}

void Matcher::strcp(char * tar, const char * sou, int length)
{
	for (int i = 0;i < length;i++) tar[i] = sou[i];
}

void Matcher::strcp(char * tar, const char * sou)
{
	strcp(tar, sou, strlength(sou));
}

int Matcher::strlength(const char* sample)
{
	int i = 0;
	while (sample[i] != '\0') i++;
	if (maxlength > 0 && i > maxlength) i = maxlength;
	return i;
}

void Matcher::slip()
{
	//printf("hello\n");
	length = strlength(sample);
	ans = new char(length);
	for (int i = 0;i < length;i++) {
		bool lock = false;
		for (int j = 0;j < type_nums;j++) {
			if (types[j] == sample[i]) {
				ans[i] = j;
				lock = true;
				break;
			}	
		}
		if (!lock) {
			ans[i] = -1;
		}
	}
	//for (int i = 0;i < length;i++)printf("%d ", ans[i]);
}

bool Matcher::check()					//校验条件：转义字符使用，括号匹配，行尾匹配符
{
	bool answer = true;
	char* ins = new char(length);
	int i;

	strcp(ins, ans, length);			//代号实体化
	for (i = 0;i < length;i++) ins[i] == -1 ? -1 : types[i];

	//转义字符检查
	for (i = 0;i < length;i++) {
		if (ins[i] == 15) {
			if (i < length - 1 && ins[i + 1] > 1) {		//[]{}内的,-无需也不允许转义字符
				ins[i] = -1;
				ins[i + 1] = -1;
			}
			else {
				answer = false;
				break;
			}
		}
	}

	if (answer) answer = breakts(ins, length, 0, 0) == -1 ? false : true;
														//	括号匹配递归式检查-1:不匹配

														//特殊字符语法检查，忽略，可以插入到环境0，1的检查条件中

	delete(ins);
	return answer;
}

int Matcher::breakts(const char * tar, int length, int pointer, int state)
{														//注意指向位置转移
	if (state == 0) {
		for (;pointer < length;pointer++) {
			switch (tar[pointer]) {
			case '(':
				pointer = breakts(tar, length, pointer + 1, 1);
				break;
			case '[':
				pointer = breakts(tar, length, pointer + 1, 2);
				break;
			case '{':
				pointer = breakts(tar, length, pointer + 1, 3);
				break;
			case ')':
			case ']':
			case '}':
				return -1;								//意外检测
			}
			if (pointer == -1) return -1;
		}
		return 0;										//全递归正常终止
	}
	else if (state == 1) {
		for (;pointer < length;pointer++) {
			switch (tar[pointer]) {
			case '(':
				pointer = breakts(tar, length, pointer + 1, 1);
				break;
			case '[':
				pointer = breakts(tar, length, pointer + 1, 2);
				break;
			case '{':
				pointer = breakts(tar, length, pointer + 1, 3);
				break;
			case ')':
				return pointer;							//递归正常终止
			case ']':
			case '}':
				return -1;								//意外检测
			}
			if (pointer == -1) return -1;
		}
		return -1;										//末尾匹配失败
	}
	else if (state == 2) {								//特殊字符特化，保留^-]，其余认为是普通字符
		if (tar[pointer] == '-') {						//首先确定前两个字符的特性符合要求
			return -1;
		}
		else if (tar[pointer] == '^') {
			if (tar[pointer + 1] == '^' || tar[pointer + 1] == '-')
				return -1;
		}
		bool lock = false;
		bool sublock = false;
		for (;pointer < length;pointer++) {				//一般查询，两个“-”最少隔两个字符，不能以“-”结尾
			if (tar[pointer] == '-') {
				lock = true;
				if (sublock)
					return -1;
			}
			else if (tar[pointer] == ']') {
				return lock ? -1 : pointer;
			}
			else {
				if (lock) {
					lock = false;
					sublock = true;
				}
				else {
					sublock = false;
				}
			}
		}
		return -1;										//末尾匹配失败
	}
	else if (state == 3) {								//只匹配"n,"或者"a,b"(规定前一个逻辑的次数)
		if (tar[pointer] == '^') pointer++;				//“非”逻辑检查
		if (tar[pointer] != -1) return -1;				//非“非”首字符检查
		bool lock = false;
		for (;pointer < length;pointer++) {				//一般查询

			if (tar[pointer] == ',') {
				lock = true;
			}
			else if (tar[pointer] == '}') {
				return lock ? -1 : pointer;
			}
			else if (tar[pointer] > 0) return -1;
		}
		return -1;										//末尾匹配失败
	}
	else
	return false;
}

