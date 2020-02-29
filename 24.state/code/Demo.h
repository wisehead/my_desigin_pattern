#ifndef __DEMO_H__
#define __DEMO_H__

// ����״̬��
class State
{
public:
	// �������󷽷�
	virtual void handle() = 0;
};

// ����״̬��
class ConcreteState :public State
{
public:
	// ʵ��
	void handle(){
		// ����
	}
};

// ��������
class Context
{
public:
	// set��������״̬����
	void setState(State* iState){
		this->state = iState;
	}
	// �����װ�ķ���
	void request(){
		// do something
		state->handle();
	}
private:
	// ����״̬����
	State *state;
};

// 1.�ɻ�����������ʵ����Ϊ��һ������״̬�����
class Context
{
public:
	void convertState(){
		if (condition1){
			this->state = new ConcreteStateA();
		}
		else if (condition2){
			this->state = new ConcreteStateB();
		}
		else{
			// do something
		}
	}
private:
	// ����״̬����
	State *state;
};
// 2.�о���״̬��������ת������һ������״̬�����
class ConcreteState :public State
{
public:
	void convertState(Context* ctx){
		if (condition1){
			ctx->setState(new ConcreteStateA());
		}
		else if (condition2){
			ctx->setState(new ConcreteStateB());
		}
		else{
			// do something
		}
	}
};

#endif //__DEMO_H__