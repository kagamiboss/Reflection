#include "Sakura.h"

IMPLEMENT_AST_CLASS(Sakura);
Sakura::Sakura()
		{
		name="间桐樱";
		}
Sakura::~Sakura(){}

std::string Sakura::getName()
	{
	return name;
	}

void Sakura::setName(std::string name)
	{
	this->name=name;
	}

void Sakura::info()
	{
	printf("[%s] 当前等级: %d, 装备宝具: %s\r\n", name.c_str(), *m_lv, m_item->c_str()); 
	}

void Sakura::say()
	{
	printf("[%s] “樱和前辈在一起的时刻,都是最幸福的时刻”\r\n", name.c_str());
	}

void Sakura::skill()
	{
	printf("[%s] “所以你能理解谁的地位更高了吧？”\r\n\r\n", name.c_str()); 
	}