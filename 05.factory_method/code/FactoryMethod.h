#ifndef __FACTORY_METHOD__
#define __FACTORY_METHOD__

#include <iostream>
#include <string.h>
using namespace std;

//�����Ʒ��AbstractProduct
class AbstractSportProduct
{
public:
	AbstractSportProduct(){

	}
	//���󷽷���
	void printName(){};
	void play(){};
};

//�����Ʒ��Basketball
class Basketball :public AbstractSportProduct
{
public:
	Basketball(){
		printName();
		play();
	}
	//����ʵ�ַ���
	void printName(){
		printf("Jungle get Basketball\n");
	}
	void play(){
		printf("Jungle play Basketball\n\n");
	}
};

//�����Ʒ��Football
class Football :public AbstractSportProduct
{
public:
	Football(){
		printName();
		play();
	}
	//����ʵ�ַ���
	void printName(){
		printf("Jungle get Football\n");
	}
	void play(){
		printf("Jungle play Football\n\n");
	}
};

//�����Ʒ��Volleyball
class Volleyball :public AbstractSportProduct
{
public:
	Volleyball(){
		printName();
		play();
	}
	//����ʵ�ַ���
	void printName(){
		printf("Jungle get Volleyball\n");
	}
	void play(){
		printf("Jungle play Volleyball\n\n");
	}
};

//���󹤳���
class AbstractFactory
{
public:
	virtual AbstractSportProduct *getSportProduct() = 0;
};

//���幤����BasketballFactory
class BasketballFactory :public AbstractFactory
{
public:
	BasketballFactory(){
		printf("BasketballFactory\n");
	}
	AbstractSportProduct *getSportProduct(){
		printf("basketball");
		return new Basketball();
	}
};

//���幤����FootballFactory
class FootballFactory :public AbstractFactory
{
public:
	FootballFactory(){
		printf("FootballFactory\n");
	}
	AbstractSportProduct *getSportProduct(){
		return new Football();
	}
};

//���幤����VolleyballFactory
class VolleyballFactory :public AbstractFactory
{
public:
	VolleyballFactory(){
		printf("VolleyballFactory\n");
	}
	AbstractSportProduct *getSportProduct(){
		return new Volleyball();
	}
};


#endif //__FACTORY_METHOD__