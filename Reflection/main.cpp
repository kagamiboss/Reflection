#include <iostream>
#include <windows.h>

#include "../ReflectionLib/MyGirlFriend.h"
#pragma comment (lib, "../Debug/ReflectionLib.lib")


//自定义一个安置女友们的容器:后宫;
class MyHarem
{
  public:
	std::string equip; //女友的装备;
	MyGirlFriend* pGirlFriend;
	void set_equip(std::string equip) {this->equip= equip;}	
	void set_room(MyGirlFriend* gf) {this->pGirlFriend=gf;}
	void play() 
		{
		printf("[系统] %s成为了你的队友!\r\n", pGirlFriend->getName().c_str());
		printf("[%s] 持有 %s\r\n", pGirlFriend->getName().c_str(), equip.c_str());
		pGirlFriend->info();
		pGirlFriend->say();
		}
};

//每个角色配置不同属性;
class MyGirl
  {
  public:
	MyGirl(const char* name, int lv, const char* item):lv(lv),name(name),item(item){}
	int lv; std::string name, item;
  };

//通过名字召唤多个女友, 1 为要召唤的数量;
void play_game(int len, ...);
 
int main()
	{
	//在你的后宫中召唤你女朋友们;
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
		//使用妹子的名字来召唤不同的女友类;
		pGF = va_arg(argptr, MyGirl*);
		pGirlFriend = (MyGirlFriend*)CRFactory::sharedClassFactory().getClassByName(pGF->name.c_str()) ;
		if(NULL == pGirlFriend)
			printf("[系统] %s 召唤失败, 查无此人\r\n\r\n", pGF->name.c_str());
		else
			{			
			pGirlFriend->registProperty();        //在后宫给新的妹纸登记入住;
			pHarem->set_equip(pGF->item.c_str()); //给妹子发装备;
			pHarem->set_room(pGirlFriend);        //给她分配房间;

			//设定角色的属性, 使用传入的自定义值;
			pGirlFriend->m_propertyMap["set_lv"](pGirlFriend, &pGF->lv);
			pGirlFriend->m_propertyMap["set_item"](pGirlFriend, &pGF->item);

			//可以开始和新的妹纸一起愉快的玩耍了;
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




