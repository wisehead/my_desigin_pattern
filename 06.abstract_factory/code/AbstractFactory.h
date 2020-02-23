#ifndef __ABSTRACT_FACTORY__
#define __ABSTRACT_FACTORY__

#include <iostream>
#include <string.h>
using namespace std;

//�����Ʒ��AbstractBall
class AbstractBall
{
public:
	AbstractBall(){

	}
	//���󷽷���
	void play(){};
};

//�����Ʒ��Basketball
class Basketball :public AbstractBall
{
public:
	Basketball(){
		play();
	}
	//����ʵ�ַ���
	void play(){
		printf("Jungle play Basketball\n\n");
	}
};

//�����Ʒ��Football
class Football :public AbstractBall
{
public:
	Football(){
		play();
	}
	//����ʵ�ַ���
	void play(){
		printf("Jungle play Football\n\n");
	}
};

//�����Ʒ��AbstractShirt
class AbstractShirt
{
public:
	AbstractShirt(){}
	//���󷽷���
	void wearShirt(){};
};

//�����Ʒ��BasketballShirt
class BasketballShirt :public AbstractShirt
{
public:
	BasketballShirt(){
		wearShirt();
	}
	//����ʵ�ַ���
	void wearShirt(){
		printf("Jungle wear Basketball Shirt\n\n");
	}
};

//�����Ʒ��FootballShirt
class FootballShirt :public AbstractShirt
{
public:
	FootballShirt(){
		wearShirt();
	}
	//����ʵ�ַ���
	void wearShirt(){
		printf("Jungle wear Football Shirt\n\n");
	}
};

//���󹤳���
class AbstractFactory
{
public:
	virtual AbstractBall *getBall() = 0;
	virtual AbstractShirt *getShirt() = 0;
};

//���幤����BasketballFactory
class BasketballFactory :public AbstractFactory
{
public:
	BasketballFactory(){
		printf("BasketballFactory\n");
	}
	AbstractBall *getBall(){
		printf("Jungle get basketball\n");
		return new Basketball();
	}
	AbstractShirt *getShirt(){
		printf("Jungle get basketball shirt\n");
		return new BasketballShirt();
	}
};

//���幤����BasketballFactory
class FootballFactory :public AbstractFactory
{
public:
	FootballFactory(){
		printf("FootballFactory\n");
	}
	AbstractBall *getBall(){
		printf("Jungle get football\n");
		return new Football();
	}
	AbstractShirt *getShirt(){
		printf("Jungle get football shirt\n");
		return new FootballShirt();
	}
};

#endif //__ABSTRACT_FACTORY__