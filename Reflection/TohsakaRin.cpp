#include "TohsakaRin.h"

IMPLEMENT_AST_CLASS(TohsakaRin);
TohsakaRin::TohsakaRin()
		{
		name="Զ����";
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
	printf("[%s] ��ǰ�ȼ�: %d, װ������: %s\r\n", name.c_str(), *m_lv, m_item->c_str()); 
	}

void TohsakaRin::say()
	{
	printf("[%s] ������ؿ�����������ҵ�Ұ�ġ�\r\n", name.c_str());
	}

void TohsakaRin::skill()
	{
	printf("[%s] ����Ҫ�Ĳ����㵽������������ܵ�������԰ɣ���\r\n\r\n", name.c_str()); 
	}