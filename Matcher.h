#pragma once
class Matcher
{
//公有函数
public:
	Matcher();
	Matcher(const char * init);
	~Matcher();
	char * initer(const char * init);					//失败返回错误信息，成功返回空指针
	bool match(char * target);						//成功返回真，（处理序列控制）

public:
	const char* error_message1 = "initer illegal";
	const int maxlength = 20;						//表达式最大长度
private:
	const int type_nums = 16;
	const char* types = ",-()[]{}^.|+?*$\\";		//不定2，括号3，左1中2右4，转义1
													//括号改变语法环境，^$改变匹配方式

													//表达式
	int length=0;										//输入长度
	char* sample = 0;								//输入存储
	char* ans = 0;									//解析存储

	int target_len;									//匹配目标的长度，内容
	char* target;

private:											//辅助函数
	int  strlength(const char* sample);				//字符串长度
	void strcp(char* tar,const char* sou, int length);//字符串拷贝
	void strcp(char*tar, const char*sou);

private:		
	void slip();									//第一阶段,分割，已通过
	bool check();									//合法性检查，假即非法表达式
	int breakts(const char* tar, int length,
		int pointer, int state);					//括号匹配性检查，为check工作,()一类,[]二类,{}三类 ，0无符号
};

