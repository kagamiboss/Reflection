
#include "MyGirlFriend.h"

IMPLEMENT_AST_CLASS(MyGirlFriend);

MyGirlFriend::~MyGirlFriend(){}
void MyGirlFriend::registProperty(){}
void MyGirlFriend::info(){}
void MyGirlFriend::say(){}
void MyGirlFriend::skill(){}

std::string MyGirlFriend::getName()
	{
	return NULL;
	}

void* MyGirlFriend::createInstance()
	{
	return new MyGirlFriend() ;
	}