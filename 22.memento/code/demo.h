#ifndef __DEMO_H__
#define __DEMO_H__

#ifndef __DEMO_H__
// ǰ������
class Memento;

// ԭ����  ����ʵ��
class Originator
{
public:
	Originator(){
		state = "";
	}
	Originator(String iState){
		state = iState;
	}
	// ��������¼����
	Memento* createMemento(){
		return new Memento(this);
	}
	// ���ñ���¼����ָ�ԭ����״̬
	void restoreMemento(Memento* m){
		state = m->getState();
	}
	void setState(string iState){ 
		state = iState; 
	}
	string getState(){ 
		return state; 
	}
private:
	string state;
};

// ����¼  ����ʵ�֣�����ԭ��������ƣ�
class Memento
{
public:
	Memento(){
		state = "";
	}
	Memento(Originator* o){
		state = o->getState();
	}
	void setState(String iState){
		state = iState;
	}
	string getState(){
		return state;
	}
private:
	String state;
};

// ������  ����ʵ��
class Caretaker
{
public:
	Caretaker(){}
	Memento* getMemento(){
		return memento;
	}
	void setMemento(Memento *m){
		memento = m;
	}
private:
	Memento* memento;
};

// �ͻ��� ʾ������
int main()
{
	// ����ԭ��������
	Originator o = new Originator("state1");
	// ���������˶���
	Caretaker *c = new Caretaker();
	c->setMemento(o->createMemento());

	o->setState("state2");

	// �Ӹ����˶�����ȡ������¼����ʵ�ֳ���
	o->restoreMemento(c->getMemento());

	return 0;
}

#endif 

#endif // __DEMO_H__
