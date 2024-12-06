#include "Saber.h"

IMPLEMENT_AST_CLASS(Saber);
Saber::Saber()
		{
		name="阿尔托莉雅"; //潘德拉贡;
		}
Saber::~Saber(){}

std::string Saber::getName()
	{
	return name;
	}

void Saber::setName(std::string name)
	{
	this->name=name;
	}

void Saber::info()
	{
	printf("[%s] 当前等级: %d, 装备宝具: %s\r\n", name.c_str(), *m_lv, m_item->c_str()); 
	}

void Saber::say()
	{
	printf("[%s] “你就是我的 Master 吗?”\r\n", name.c_str());
	}

void Saber::skill()
	{
	printf("[%s] “汇聚的星之吐息，闪耀的生命奔流，接下吧，Excalibur~!”\r\n\r\n", name.c_str()); 
	}