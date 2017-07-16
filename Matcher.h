#pragma once
//特殊字符集（候选）： -,^$()[]{}*+?|\
//先进行完全匹配(默认有^$选项)
class Matcher
{
//公有函数
public:
	Matcher(int state, char* sou, int pointer);
	Matcher(int state, char* sou, int pointer, Matcher* root, Matcher* father);
	~Matcher();

private:
	int state;//0,默认, 1圆括号， 2方括号， 3花括号

	//数量控制变量
	int num_gate = 0;		//掩码0，默认状态， 只匹配一次，1 激活状态
	int num_lim_down;
	int num_lim_up;			//定义上下界，up=0是表示不设上界
	int mode;				//数量匹配模式，默认0表示贪婪法，1表示懒惰法

	//连接管控
	int child_gate = 1;		//后续连接结构数量，默认1表示1个
	Matcher* childs = 0;	//后续量的指针

	//逻辑管控				//非逻辑控制,默认为1（真）
	int used = 1;

	//字符集
	int charlen;
	char* chars = 0;

	//选择字符
	char from, to;

	//数字边界
	int down;
	int up = 0;

public:
	int ans_static = 1;		//分析状态控制：0结束分析，1正常进行，2待定义（初始化和匹配时都需要使用）
	void drop();			//结构销毁
};

