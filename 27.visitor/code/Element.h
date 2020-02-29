#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include "Visitor.h"
#include <iostream>
using namespace std;

// ����Ԫ��
class Element
{
public:
	Element(){};
	virtual void accept(Visitor*) = 0;
	void setPrice(int iPrice){
		this->price = iPrice;
	}
	int getPrice(){
		return this->price;
	}
	void setNum(int iNum){
		this->num = iNum;
	}
	int getNum(){
		return num;
	}
	void setName(string iName){
		this->name = iName;
	}
	string getName(){
		return this->name;
	}
private:
	int price;
	int num;
	string name;
};

// ����Ԫ�أ�Apple
class Apple :public Element
{
public:
	Apple();
	Apple(string name, int price);
	void accept(Visitor*);
};

// ����Ԫ�أ�Book
class Book :public Element
{
public:
	Book();
	Book(string name, int price);
	void accept(Visitor*);
};

#endif