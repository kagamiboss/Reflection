//---------------------------------------------------------------------------
/* CReflection (������) Version 0.14.0620
 * Copyright (c) 2014, Kagami 
 * All rights reserved.
 *
 * ͨ��std��ϣ��������ص�����������Ϊkeyֵ��ʵ�ַ�����������й���
 */
//---------------------------------------------------------------------------

#pragma once

#include <iostream>
#include <string>
#include <map>
//---------------------------------------------------------------------------
//�궨��

//��̬������̬����ָ��
#define DECLARE_AST_CLASS(className)					\
	std::string className##Name ;						\
	static CDynamicClass* m_className##dc ;

//��̬ʵ����δ֪��
#define IMPLEMENT_AST_CLASS(className)					\
	CDynamicClass* className::m_className##dc =			\
	new CDynamicClass(#className, className::createInstance) ;

//---------------------------------------------------------------------------
//���Ͷ���

class MyGirlFriend ;
class CDynamicClass;
class CRFactory;

//��������ָ��CVideoCard
typedef void (*setValue)(MyGirlFriend *t, void* c);
//��������ָ��createClass
typedef void* (*createClass)(void); 

//---------------------------------------------------------------------------
//���������

class CReflection
{
public:
	CReflection(void);
	~CReflection(void);
	void Test() {printf("Class is Okay\n");}
};


//---------------------------------------------------------------------------
//��̬������

class CDynamicClass
{
  public:
	//ע��δ֪��ָ��
	CDynamicClass(std::string name, createClass method);
};

//---------------------------------------------------------------------------
//�����๤��

class CRFactory
{
  public:
	CRFactory() ;
	virtual ~CRFactory() ;

	//ͨ��������ȡδ֪�ຯ��ָ��
	void* getClassByName(std::string className);
	//ע����δ֪�ࡢδ֪�ຯ��ָ�� 
	void registClass(std::string name, createClass method) ;
	//�����൥��ģʽ 
	static CRFactory& sharedClassFactory() ;
 
  private:
	std::map<std::string, createClass> m_classMap ;
} ;
