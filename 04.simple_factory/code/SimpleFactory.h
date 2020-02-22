#ifndef __SIMPLE_FACTORY__
#define __SIMPLE_FACTORY__

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
		printf("Jungle play Basketball\n");
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
		printf("Jungle play Football\n");
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
		printf("Jungle play Volleyball\n");
	}
};

class Factory
{
public:
	AbstractSportProduct *getSportProduct(string productName)
	{
		AbstractSportProduct *pro = NULL;
		if (productName == "Basketball"){
			pro = new Basketball();
		}
		else if (productName == "Football"){
			pro = new Football();
		}
		else if (productName == "Volleyball"){
			pro = new Volleyball();
		}
		return pro;
	}
};


#endif //__SIMPLE_FACTORY__