//---------------------------------------------------------------------------
/* CReflection (反射类) Version 0.14.0620
 * Copyright (c) 2014, Kagami 
 * All rights reserved.
 *
 * 通过std哈希表来储存回调，以类名作为key值，实现反射所需的所有功能
 */
//---------------------------------------------------------------------------

#pragma once

#include <iostream>
#include <string>
#include <map>
//---------------------------------------------------------------------------
//宏定义

//动态声明静态函数指针
#define DECLARE_AST_CLASS(className)					\
	std::string className##Name ;						\
	static CDynamicClass* m_className##dc ;

//动态实例化未知类
#define IMPLEMENT_AST_CLASS(className)					\
	CDynamicClass* className::m_className##dc =			\
	new CDynamicClass(#className, className::createInstance) ;

//---------------------------------------------------------------------------
//类型定义

class MyGirlFriend ;
class CDynamicClass;
class CRFactory;

//声明函数指针CVideoCard
typedef void (*setValue)(MyGirlFriend *t, void* c);
//声明函数指针createClass
typedef void* (*createClass)(void); 

//---------------------------------------------------------------------------
//反射机制类

class CReflection
{
public:
	CReflection(void);
	~CReflection(void);
	void Test() {printf("Class is Okay\n");}
};


//---------------------------------------------------------------------------
//动态创建类

class CDynamicClass
{
  public:
	//注册未知类指针
	CDynamicClass(std::string name, createClass method);
};

//---------------------------------------------------------------------------
//反射类工厂

class CRFactory
{
  public:
	CRFactory() ;
	virtual ~CRFactory() ;

	//通过类名获取未知类函数指针
	void* getClassByName(std::string className);
	//注册类未知类、未知类函数指针 
	void registClass(std::string name, createClass method) ;
	//工厂类单例模式 
	static CRFactory& sharedClassFactory() ;
 
  private:
	std::map<std::string, createClass> m_classMap ;
} ;
