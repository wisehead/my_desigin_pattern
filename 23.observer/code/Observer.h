#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <iostream>
using namespace std;
#include "common.h"
#include "AllyCenter.h"

// ����۲��� Observer
class Observer
{
public:
	Observer(){}
	// �������󷽷�
	virtual void call(INFO_TYPE infoType, AllyCenter* ac) = 0;
	string getName(){
		return name;
	}
	void setName(string iName){
		this->name = iName;
	}
private:
	string name;
};

// ����۲��� 
class Player :public Observer
{
public:
	Player(){
		setName("none");
	}
	Player(string iName){
		setName(iName);
	}
	// ʵ��
	void call(INFO_TYPE infoType, AllyCenter* ac){
		switch (infoType){
		case RESOURCE:
			//printf("%s :������������\n", getName().c_str());
			printf("%s :I have resource here!!!!!! come on baby!!!!\n", getName().c_str());
			break;
		case HELP:
			//printf("%s :�Ⱦ���\n", getName().c_str());
			printf("%s :HELP!!!!SOS!!!!\n", getName().c_str());
			break;
		default:
			printf("Nothing\n");
		}
		ac->notify(infoType, getName());
	}
	// ʵ�־��巽��
	void help(){
		//printf("%s:���ס���������㣡\n", getName().c_str());
		printf("%s:Hold on! I'm comming.......\n", getName().c_str());
	}
	void come(){
		//printf("%s:�õģ�����ȡ����\n", getName().c_str());
		printf("%s:ok, I'm comming for the lunch.\n", getName().c_str());
	}
};

#endif
