#ifndef __DEMO_H__
#define __DEMO_H__

// �����ࣨ���ࣩ
class AbstractClass
{
public:
	// ģ�巽��������һ���㷨�Ŀ������
	void templateMethod(){
		// do something
		method1();
		method2();
		method3();
	}
	// ��������������������
	void mehtod1(){
		// do something
	}
	// ��������2
	virtual void method2() = 0;
	// ��������3����Ĭ��ʵ��
	void mehtod3(){
		// do something
	}
};

// �����ࣨ������)
class ConcreteClass :public AbstractClass
{
public:
	// ʵ�ֻ�������2
	void method2(){
		// do something
	}
	// �ض����������3�����ǻ���ķ���3
	void method3(){
		// do something
	}
};

#endif