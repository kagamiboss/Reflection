#include "Sakura.h"

IMPLEMENT_AST_CLASS(Sakura);
Sakura::Sakura()
		{
		name="��ͩӣ";
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
	printf("[%s] ��ǰ�ȼ�: %d, װ������: %s\r\n", name.c_str(), *m_lv, m_item->c_str()); 
	}

void Sakura::say()
	{
	printf("[%s] ��ӣ��ǰ����һ���ʱ��,�������Ҹ���ʱ�̡�\r\n", name.c_str());
	}

void Sakura::skill()
	{
	printf("[%s] �������������˭�ĵ�λ�����˰ɣ���\r\n\r\n", name.c_str()); 
	}