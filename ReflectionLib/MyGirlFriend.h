//---------------------------------------------------------------------------
/* MyGirlFriend (我的女友接口) Version 0.14.0620
 * Copyright (c) 2014, Kagami 
 * All rights reserved.
 *
 * 实现了反射机制的样例接口
 */
//---------------------------------------------------------------------------

#pragma once

//引入反射机制
#include "Reflection.h"

//同步未知类的成员变量指针到基类，并同步基础的读写属性方法（set/get）
#define BIND_MY_LINK(classType, varType, varName)				 \
  public:													     \
	inline static void set##varName(MyGirlFriend* vc, void* value)	 \
		{														 \
		classType* tp = (classType*)vc;		                     \
		tp->varName = (varType)value;                            \
		}                                                        \
	  inline varType get##varName(void) const					 \
		{										                 \
		return varName;                                         \
		}

class MyGirlFriend
{
public:
	MyGirlFriend(){}
	virtual ~MyGirlFriend();

  private:
	//动态声明静态函数指针，并将对应的函数插入到哈希表中《
	DECLARE_AST_CLASS(MyGirlFriend);

  public:
	static void* createInstance();  //单例模式;
	virtual void registProperty();	//注册函数;
	std::map<std::string, setValue> m_propertyMap ;

  public:
	//测试用接口，实际方法在子类重载即可
	virtual void info();     //角色状态;
	virtual void say();		 //台词;
	virtual void skill();    //技能;
	virtual std::string getName();
};


