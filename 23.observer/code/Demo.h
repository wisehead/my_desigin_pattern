#define __DEMO_H__
#ifdef __DEMO_H__

using namespace std;
#include <list>

// ����۲���
class Observer
{
public:
	// ������Ӧ���·���
	virtual void update() = 0;
};

// ����۲���
class ConcreteObserver:public Observer
{
public:
	// ʵ����Ӧ���·���
	void update(){
		// �������
	}
};

// ����Ŀ��
class Subject
{
public:
	// ��ӹ۲���
	void attach(Observer* obs){
		obsList.push_back(obs);
	}
	// �Ƴ��۲���
	void detach(Observer* obs){
		obsList.remove(obs);
	}
	// ����֪ͨ����
	virtual void notify() = 0;
protected:
	// �۲����б�
	list<Observer*>obsList;
};

// ����Ŀ��
class ConcreteSubject :public Subject
{
public:
	// ʵ��֪ͨ����
	void notify(){
		// �������
		// ����֪ͨ�۲��߶���
		for (int i = 0; i < obsList.size(); i++){
			obsList[i]->update();
		}
	}
};

// �ͻ��˴���ʾ��
int main()
{
	Subject  *sub = new ConcreteSubject();
	Observer *obs = new ConcreteObserver();
	sub->attach(obs);
	sub->notify();
	return 0;
}
#endif