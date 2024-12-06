#include "TohsakaRin.h"

IMPLEMENT_AST_CLASS(TohsakaRin);
TohsakaRin::TohsakaRin()
		{
		name="远坂凛";
		}
TohsakaRin::~TohsakaRin(){}

std::string TohsakaRin::getName()
	{
	return name;
	}

void TohsakaRin::setName(std::string name)
	{
	this->name=name;
	}

void TohsakaRin::info()
	{
	printf("[%s] 当前等级: %d, 装备宝具: %s\r\n", name.c_str(), *m_lv, m_item->c_str()); 
	}

void TohsakaRin::say()
	{
	printf("[%s] “尽情地快乐生活才是我的野心”\r\n", name.c_str());
	}

void TohsakaRin::skill()
	{
	printf("[%s] “重要的不是你到了哪里，而是你能到达哪里，对吧？”\r\n\r\n", name.c_str()); 
	}