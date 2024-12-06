//---------------------------------------------------------------------------
/* MyGirlFriend (�ҵ�Ů�ѽӿ�) Version 0.14.0620
 * Copyright (c) 2014, Kagami 
 * All rights reserved.
 *
 * ʵ���˷�����Ƶ������ӿ�
 */
//---------------------------------------------------------------------------

#pragma once

//���뷴�����
#include "Reflection.h"

//ͬ��δ֪��ĳ�Ա����ָ�뵽���࣬��ͬ�������Ķ�д���Է�����set/get��
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
	//��̬������̬����ָ�룬������Ӧ�ĺ������뵽��ϣ���С�
	DECLARE_AST_CLASS(MyGirlFriend);

  public:
	static void* createInstance();  //����ģʽ;
	virtual void registProperty();	//ע�ắ��;
	std::map<std::string, setValue> m_propertyMap ;

  public:
	//�����ýӿڣ�ʵ�ʷ������������ؼ���
	virtual void info();     //��ɫ״̬;
	virtual void say();		 //̨��;
	virtual void skill();    //����;
	virtual std::string getName();
};


