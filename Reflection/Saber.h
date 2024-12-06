//---------------------------------------------------------------------------
/* Saber (��ɫ1) Version 0.14.0620
 * Copyright (c) 2014, Kagami 
 * All rights reserved.
 * ���ݷ������ģ�ⴴ����ɫ1;
 * 10:26 2014-06-20
 */
//---------------------------------------------------------------------------
#pragma once
#include "../ReflectionLib/MyGirlFriend.h"
#pragma comment (lib, "../Debug/ReflectionLib.lib")

class Saber: public MyGirlFriend
{
  public:
	Saber();
	~Saber();
    static void* createInstance(){return new Saber();}

  private:	
    DECLARE_AST_CLASS(Saber)

  protected:
    int* m_lv ;
	std::string* m_item ;

  public:
	//���Զ������Ա���;
    BIND_MY_LINK(Saber, int*, m_lv);
	BIND_MY_LINK(Saber, std::string*, m_item);

	//ע���ɫ�����Է���;
    void registProperty()
		{
		m_propertyMap.insert(std::pair<std::string, setValue>("set_lv", setm_lv)); //��ɫ�ȼ�;
		m_propertyMap.insert(std::pair<std::string, setValue>("set_item", setm_item)); //��ɫװ��;
		}

  public:
	std::string name;	
	void setName(std::string name);
	std::string getName();
	
	void info();   //״̬;
	void say();   //̨��;
	void skill(); //����;
};

