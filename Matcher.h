#pragma once
//特殊字符集（候选）： -,^$()[]{}*+?|\
//先进行完全匹配(默认带有，不允许额外添加有^$选项)
//架构抽象化，将或逻辑封装为分支
class Matcher
{
//公有函数
public:
	Matcher(const char* sou);
	Matcher(int state, char* sou, int pointer, Matcher* root, Matcher* father);
	~Matcher();

private:
	int pointer;
	Matcher* root;
	Matcher* father;
	void init();

	//数量控制变量
	int num_gate = 0;		//掩码0，默认状态， 只匹配一次，1 激活状态
	int num_lim_down;
	int num_lim_up;			//定义上下界，up=0是表示不设上界
	int mode;				//数量匹配模式，默认0表示贪婪法，1表示懒惰法

	//连接管控
	int child_gate = 1;		//内部连接结构数量，默认1表示1个
	Matcher* childs = 0;	//内部量的指针

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

	void match(char* ins);

	int state;				//0,默认, 1圆括号， 2方括号， 3花括号
	int ans_static = 1;		//分析状态控制：0结束分析，1正常进行，2待定义（初始化和匹配时都需要使用）
	char* sou;
	void drop();			//结构销毁
	//void matcher_or(Matcher* child, int endpoint);	//申请或操作
	void matcher_ok(Matcher* child, int endpoint);	//分析终止申请
	void matcher_error();				//错误申请

private:
	//辅助函数
	int getlength(char* ins);	//最大长度100字符
	int belongs(char c);		//特殊字符初级判断
};

