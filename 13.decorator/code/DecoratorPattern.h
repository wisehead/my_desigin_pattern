#ifndef __DECORATOR_PATTERN_H__
#define __DECORATOR_PATTERN_H__

//���󹹼�
class Component
{
public:
	Component(){}
	virtual void operation() = 0;
};

//���幹����
class Phone :public Component
{
public:
	Phone(){}
	void operation(){
		//printf("�ֻ�\n");
		printf("Cell Phone.\n");
	}
};

//����װ����
class Decorator :public Component
{
public:
	Decorator(){}
	Decorator(Component *c){
		this->component = c;
	}
	void operation(){
		this->component->operation();
	}
	Component *getComponent(){
		return this->component;
	}
	void setComponent(Component *c){
		this->component = c;
	}
private:
	Component *component;
};

//����װ���ࣺ�ֻ���
class DecoratorShell:public Decorator
{
public:
	DecoratorShell(){}
	DecoratorShell(Component *c){
		this->setComponent(c);
	}
	void operation(){
		this->getComponent()->operation();
		this->newBehavior();
	}
	void newBehavior(){
		//printf("װ�ֻ���\n");
		printf("shell....\n");
	}
};

//����װ���ࣺ�ֻ���ֽ
class DecoratorSticker :public Decorator
{
public:
	DecoratorSticker(){}
	DecoratorSticker(Component *c){
		this->setComponent(c);
	}
	void operation(){
		this->getComponent()->operation();
		this->newBehavior();
	}
	void newBehavior(){
		//printf("����ͨ��ֽ\n");
		printf("sticker....\n");
	}
};

//����װ���ࣺ�ֻ�����
class DecoratorRope :public Decorator
{
public:
	DecoratorRope(){}
	DecoratorRope(Component *c){
		this->setComponent(c);
	}
	void operation(){
		this->getComponent()->operation();
		this->newBehavior();
	}
	void newBehavior(){
		//printf("ϵ�ֻ�����\n");
		printf("rope....\n");
	}
};
#endif //__DECORATOR_PATTERN_H__
