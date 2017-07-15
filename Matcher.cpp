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

bool Matcher::check()					//У��������ת���ַ�ʹ�ã�����ƥ�䣬��βƥ���
{
	bool answer = true;
	char* ins = new char(length);
	int i;

	strcp(ins, ans, length);			//����ʵ�廯
	for (i = 0;i < length;i++) ins[i] == -1 ? -1 : types[i];

	//ת���ַ����
	for (i = 0;i < length;i++) {
		if (ins[i] == 15) {
			if (i < length - 1 && ins[i + 1] > 1) {		//[]{}�ڵ�,-����Ҳ������ת���ַ�
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
														//	����ƥ��ݹ�ʽ���-1:��ƥ��

														//�����ַ��﷨��飬���ԣ����Բ��뵽����0��1�ļ��������

	delete(ins);
	return answer;
}

int Matcher::breakts(const char * tar, int length, int pointer, int state)
{														//ע��ָ��λ��ת��
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
				return -1;								//������
			}
			if (pointer == -1) return -1;
		}
		return 0;										//ȫ�ݹ�������ֹ
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
				return pointer;							//�ݹ�������ֹ
			case ']':
			case '}':
				return -1;								//������
			}
			if (pointer == -1) return -1;
		}
		return -1;										//ĩβƥ��ʧ��
	}
	else if (state == 2) {								//�����ַ��ػ�������^-]��������Ϊ����ͨ�ַ�
		if (tar[pointer] == '-') {						//����ȷ��ǰ�����ַ������Է���Ҫ��
			return -1;
		}
		else if (tar[pointer] == '^') {
			if (tar[pointer + 1] == '^' || tar[pointer + 1] == '-')
				return -1;
		}
		bool lock = false;
		bool sublock = false;
		for (;pointer < length;pointer++) {				//һ���ѯ��������-�����ٸ������ַ��������ԡ�-����β
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
		return -1;										//ĩβƥ��ʧ��
	}
	else if (state == 3) {								//ֻƥ��"n,"����"a,b"(�涨ǰһ���߼��Ĵ���)
		if (tar[pointer] == '^') pointer++;				//���ǡ��߼����
		if (tar[pointer] != -1) return -1;				//�ǡ��ǡ����ַ����
		bool lock = false;
		for (;pointer < length;pointer++) {				//һ���ѯ

			if (tar[pointer] == ',') {
				lock = true;
			}
			else if (tar[pointer] == '}') {
				return lock ? -1 : pointer;
			}
			else if (tar[pointer] > 0) return -1;
		}
		return -1;										//ĩβƥ��ʧ��
	}
	else
	return false;
}

