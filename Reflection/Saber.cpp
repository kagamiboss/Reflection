#include "Saber.h"

IMPLEMENT_AST_CLASS(Saber);
Saber::Saber()
		{
		name="����������"; //�˵�����;
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
	printf("[%s] ��ǰ�ȼ�: %d, װ������: %s\r\n", name.c_str(), *m_lv, m_item->c_str()); 
	}

void Saber::say()
	{
	printf("[%s] ��������ҵ� Master ��?��\r\n", name.c_str());
	}

void Saber::skill()
	{
	printf("[%s] ����۵���֮��Ϣ����ҫ���������������°ɣ�Excalibur~!��\r\n\r\n", name.c_str()); 
	}