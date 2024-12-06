//---------------------------------------------------------------------------
/* TohsakaRin (角色3) Version 0.14.0620
 * Copyright (c) 2014, Kagami 
 * All rights reserved.
 * 根据反射机制模拟创建角色3;
 * 11:44 2024-12-06
 */
//---------------------------------------------------------------------------
#pragma once
#include "../ReflectionLib/MyGirlFriend.h"
#pragma comment (lib, "../Debug/ReflectionLib.lib")

class Sakura: public MyGirlFriend
{
  public:
	Sakura();
	~Sakura();
    static void* createInstance(){return new Sakura();}

  private:	
    DECLARE_AST_CLASS(Sakura)

  protected:
    int* m_lv ;
	std::string* m_item ;

  public:
	//绑定自定义属性变量;
    BIND_MY_LINK(Sakura, int*, m_lv);
	BIND_MY_LINK(Sakura, std::string*, m_item);

	//注册角色的属性方法;
    void registProperty()
		{
		m_propertyMap.insert(std::pair<std::string, setValue>("set_lv", &setm_lv)); //角色等级;
		m_propertyMap.insert(std::pair<std::string, setValue>("set_item", &setm_item)); //角色装备;
		}

  public:
	std::string name;	
	void setName(std::string name);
	std::string getName();

	void info();  //状态;
	void say();   //台词;
	void skill(); //技能;
};


