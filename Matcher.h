#pragma once
//�����ַ�������ѡ���� -,^$()[]{}*+?|\
//�Ƚ�����ȫƥ��(Ĭ����^$ѡ��)
class Matcher
{
//���к���
public:
	Matcher(int state, char* sou, int pointer);
	Matcher(int state, char* sou, int pointer, Matcher* root, Matcher* father);
	~Matcher();

private:
	int state;//0,Ĭ��, 1Բ���ţ� 2�����ţ� 3������

	//�������Ʊ���
	int num_gate = 0;		//����0��Ĭ��״̬�� ֻƥ��һ�Σ�1 ����״̬
	int num_lim_down;
	int num_lim_up;			//�������½磬up=0�Ǳ�ʾ�����Ͻ�
	int mode;				//����ƥ��ģʽ��Ĭ��0��ʾ̰������1��ʾ���跨

	//���ӹܿ�
	int child_gate = 1;		//�������ӽṹ������Ĭ��1��ʾ1��
	Matcher* childs = 0;	//��������ָ��

	//�߼��ܿ�				//���߼�����,Ĭ��Ϊ1���棩
	int used = 1;

	//�ַ���
	int charlen;
	char* chars = 0;

	//ѡ���ַ�
	char from, to;

	//���ֱ߽�
	int down;
	int up = 0;

public:
	int ans_static = 1;		//����״̬���ƣ�0����������1�������У�2�����壨��ʼ����ƥ��ʱ����Ҫʹ�ã�
	void drop();			//�ṹ����
};

