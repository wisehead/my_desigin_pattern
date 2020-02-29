#ifndef __VISITOR_H__
#define __VISITOR_H__

#include <iostream>
using namespace std;

// ǰ������
class Element;
class Apple;
class Book;

// ���������
class Visitor
{
public:
	Visitor(){};
	// ����һ����ʷ���
	virtual void visit(Apple*) = 0;
	virtual void visit(Book*) = 0;
};

// ��������ߣ��˿�
class Customer :public Visitor
{
public:
	Customer();
	Customer(string iName);
	void setNum(Apple*, int);
	void setNum(Book*, int);
	void visit(Apple* apple);
	void visit(Book* book);
private:
	string name;
};

// ��������ߣ�����Ա
class Cashier :public Visitor
{
public:
	Cashier();
	void visit(Apple* apple);
	void visit(Book* book);
};

#endif