#include <iostream>
#include <windows.h>

#include "../ReflectionLib/MyGirlFriend.h"
#pragma comment (lib, "../Debug/ReflectionLib.lib")


//�Զ���һ������Ů���ǵ�����:��;
class MyHarem
{
  public:
	std::string equip; //Ů�ѵ�װ��;
	MyGirlFriend* pGirlFriend;
	void set_equip(std::string equip) {this->equip= equip;}	
	void set_room(MyGirlFriend* gf) {this->pGirlFriend=gf;}
	void play() 
		{
		printf("[ϵͳ] %s��Ϊ����Ķ���!\r\n", pGirlFriend->getName().c_str());
		printf("[%s] ���� %s\r\n", pGirlFriend->getName().c_str(), equip.c_str());
		pGirlFriend->info();
		pGirlFriend->say();
		}
};

//ÿ����ɫ���ò�ͬ����;
class MyGirl
  {
  public:
	MyGirl(const char* name, int lv, const char* item):lv(lv),name(name),item(item){}
	int lv; std::string name, item;
  };

//ͨ�������ٻ����Ů��, 1 ΪҪ�ٻ�������;
void play_game(int len, ...);
 
int main()
	{
	//����ĺ����ٻ���Ů������;
	MyGirl gf1("Saber", 5, "Excalibur"),  gf2("TohsakaRin", 4, "AZOTH"),  
		gf3("Sakura", 3, "Aroundight"), gf4("Asuka", 3, "Evangelion");
	play_game(4, &gf1, &gf2, &gf3, &gf4);

	system("pause");
	return 0;
	}



void play_game(int len, ...)
    {	
	MyGirlFriend *pGirlFriend;	
	MyHarem *pHarem=new MyHarem();
	MyGirl* pGF;
	va_list argptr;
	va_start(argptr, len);
	for(int i=0; i<len; i++)
		{		
		//ʹ�����ӵ��������ٻ���ͬ��Ů����;
		pGF = va_arg(argptr, MyGirl*);
		pGirlFriend = (MyGirlFriend*)CRFactory::sharedClassFactory().getClassByName(pGF->name.c_str()) ;
		if(NULL == pGirlFriend)
			printf("[ϵͳ] %s �ٻ�ʧ��, ���޴���\r\n\r\n", pGF->name.c_str());
		else
			{			
			pGirlFriend->registProperty();        //�ں󹬸��µ���ֽ�Ǽ���ס;
			pHarem->set_equip(pGF->item.c_str()); //�����ӷ�װ��;
			pHarem->set_room(pGirlFriend);        //�������䷿��;

			//�趨��ɫ������, ʹ�ô�����Զ���ֵ;
			pGirlFriend->m_propertyMap["set_lv"](pGirlFriend, &pGF->lv);
			pGirlFriend->m_propertyMap["set_item"](pGirlFriend, &pGF->item);

			//���Կ�ʼ���µ���ֽһ��������ˣ��;
			pHarem->play();			
			pGirlFriend->skill() ;

			if(NULL!=pGirlFriend)
				delete pGirlFriend;
			}	
		}

	va_end(argptr);	
	printf("GAME OVER\r\nThank You For Play~\r\n");	
	delete pHarem;
	}




