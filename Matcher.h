#pragma once
class Matcher
{
//���к���
public:
	Matcher();
	Matcher(const char * init);
	~Matcher();
	char * initer(const char * init);					//ʧ�ܷ��ش�����Ϣ���ɹ����ؿ�ָ��
	bool match(char * target);						//�ɹ������棬���������п��ƣ�

public:
	const char* error_message1 = "initer illegal";
	const int maxlength = 20;						//���ʽ��󳤶�
private:
	const int type_nums = 16;
	const char* types = ",-()[]{}^.|+?*$\\";		//����2������3����1��2��4��ת��1
													//���Ÿı��﷨������^$�ı�ƥ�䷽ʽ

													//���ʽ
	int length=0;										//���볤��
	char* sample = 0;								//����洢
	char* ans = 0;									//�����洢

	int target_len;									//ƥ��Ŀ��ĳ��ȣ�����
	char* target;

private:											//��������
	int  strlength(const char* sample);				//�ַ�������
	void strcp(char* tar,const char* sou, int length);//�ַ�������
	void strcp(char*tar, const char*sou);

private:		
	void slip();									//��һ�׶�,�ָ��ͨ��
	bool check();									//�Ϸ��Լ�飬�ټ��Ƿ����ʽ
	int breakts(const char* tar, int length,
		int pointer, int state);					//����ƥ���Լ�飬Ϊcheck����,()һ��,[]����,{}���� ��0�޷���
};

