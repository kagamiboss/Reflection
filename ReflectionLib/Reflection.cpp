#include "Reflection.h"

//using namespace std;
//---------------------------------------------------------------------------
//反射机制类
CReflection::CReflection(void)
{
}


CReflection::~CReflection(void)
{
}
//---------------------------------------------------------------------------
//动态创建类

//注册未知类指针
CDynamicClass::CDynamicClass(std::string name, createClass method) 
	{
	CRFactory::sharedClassFactory().registClass(name, method) ;
	}

//---------------------------------------------------------------------------
//反射类工厂


CRFactory::CRFactory() {}
CRFactory::~CRFactory() {} 


//通过类名获取未知类函数指针
void* CRFactory::getClassByName(std::string className)
	{
	//通过迭代器在哈希表中查询对应的类名并返回该类的指针
	std::map<std::string, createClass>::const_iterator iter ;
 
	iter = m_classMap.find(className) ;
	if (m_classMap.end() == iter)
		return NULL ;
	else
		return iter->second() ;
	}

//注册类未知类、未知类函数指针
void CRFactory::registClass(std::string name, createClass method)
	{
	m_classMap.insert(std::pair<std::string, createClass>(name, method)) ;
	}

//工厂类单例模式
CRFactory& CRFactory::sharedClassFactory()
	{
	static CRFactory _sharedClassFactory;
	return _sharedClassFactory ;
	}

	