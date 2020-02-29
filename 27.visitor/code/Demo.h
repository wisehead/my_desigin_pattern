#ifndef __DEMO_H__
#define __DEMO_H__

// ��������� Visitor
class Visitor
{
public:
	virtual void visit(ConcreteElementA*) = 0;
	virtual void visit(ConcreteElementB*) = 0;
};

// ��������� ConcreteVisitor
class ConcreteVisitor :public Visitor
{
public:
	// ʵ��һ������ض�Ԫ�صķ��ʲ���
	void visit(ConcreteElementA*){
		// Ԫ��A�ķ��ʲ�������
	}
	void visit(ConcreteElementB*){
		// Ԫ��B�ķ��ʲ�������
	}
};

// ����Ԫ��
class Element
{
public:
	// �������󷽷�����һ����������ߵ�ָ����Ϊ��������
	virtual void accept(Visitor*) = 0;
};

// ����Ԫ��
class ConcreteElement :public Element
{
public:
	void accept(Visitor* visitor){
		visitor->visit(this);
	}
};

// ����ṹ
class ObjectStructure
{
public:
	//  �ṩ�ӿڽ��ܷ����߷���
	void accept(Visitor* visitor){
		// �������ʶ���ṹ�е�Ԫ��
		for (){
			elementList[i]->accept(visitor);
		}
	}
	void addElement(){}
	void removeElement(){}
private:
	lsit<Element*>elementList;
};

#endif