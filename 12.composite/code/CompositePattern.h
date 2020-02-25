#ifndef __COMPOSITE_PATTERN_H__
#define __COMPOSITE_PATTERN_H__

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

//���󹹼�
class Component
{
public:
	Component(){}
	Component(string iName){
		this->name = iName;
	}
	//����һ�����Ż�칫��
	virtual void add(Component*) = 0;
	//����һ�����Ż�칫��
	virtual void remove(Component*) = 0;
	//
	virtual Component* getChild(int) = 0;
	//�����Ų���
	virtual void operation() = 0;
	string getName(){
		return name;
	}
private:
	string name;
};

//Ҷ�ӹ������칫��
class Office :public Component
{
public:
	Office(string iName){
		this->name = iName;
	}
	Office(){}
	void add(Component* c){
		printf("not support!\n");
	}
	void remove(Component* c){
		printf("not support!\n");
	}
	Component* getChild(int i){
		printf("not support!\n");
		return NULL;
	}
private:
	string name;
};

//Ҷ�ӹ����������칫��
class AdminOffice :public Office
{
public:
	AdminOffice(string iName){
		this->name = iName;
	}
	void operation(){
		printf("-----Administration Office:%s\n", name.c_str());
	}
private:
	string name;
};

//Ҷ�ӹ���������칫��
class DeanOffice :public Office
{
public:
	DeanOffice(string iName){
		this->name = iName;
	}
	void operation(){
		printf("-----Dean Office:%s\n", name.c_str());
	}
private:
	string name;
};

//��������SubComponent
class SubComponent :public Component
{
public:
	SubComponent(string iName){
		this->name = iName;
	}
	void add(Component *c){
		componentList.push_back(c);
	}
	void remove(Component *c){
		for (int i = 0; i < componentList.size(); i++){
			if (componentList[i]->getName() == c->getName()){
				componentList.erase(componentList.begin() + i);
				break;
			}
		}
	}
	Component* getChild(int i){
		return (Component*)componentList[i];
	}
	void operation(){
		printf("%s\n", this->name.c_str());
		for (int i = 0; i < componentList.size(); i++){
			((Component*)componentList[i])->operation();
		}
	}
private:
	string name;

	//�����б�
	vector<Component*>componentList;
};

#endif //__COMPOSITE_PATTERN_H__