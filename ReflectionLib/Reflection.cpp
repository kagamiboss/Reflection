#include "Reflection.h"

//using namespace std;
//---------------------------------------------------------------------------
//���������
CReflection::CReflection(void)
{
}


CReflection::~CReflection(void)
{
}
//---------------------------------------------------------------------------
//��̬������

//ע��δ֪��ָ��
CDynamicClass::CDynamicClass(std::string name, createClass method) 
	{
	CRFactory::sharedClassFactory().registClass(name, method) ;
	}

//---------------------------------------------------------------------------
//�����๤��


CRFactory::CRFactory() {}
CRFactory::~CRFactory() {} 


//ͨ��������ȡδ֪�ຯ��ָ��
void* CRFactory::getClassByName(std::string className)
	{
	//ͨ���������ڹ�ϣ���в�ѯ��Ӧ�����������ظ����ָ��
	std::map<std::string, createClass>::const_iterator iter ;
 
	iter = m_classMap.find(className) ;
	if (m_classMap.end() == iter)
		return NULL ;
	else
		return iter->second() ;
	}

//ע����δ֪�ࡢδ֪�ຯ��ָ��
void CRFactory::registClass(std::string name, createClass method)
	{
	m_classMap.insert(std::pair<std::string, createClass>(name, method)) ;
	}

//�����൥��ģʽ
CRFactory& CRFactory::sharedClassFactory()
	{
	static CRFactory _sharedClassFactory;
	return _sharedClassFactory ;
	}

	