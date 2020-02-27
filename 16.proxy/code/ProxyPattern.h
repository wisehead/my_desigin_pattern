#ifndef __FLYPATTERN_PATTERN_H__
#define __FLYPATTERN_PATTERN_H__

#include <mutex>
#include <time.h>
using namespace std;

// ���������ɫ
class Subject
{
public:
	Subject(){}
	virtual void method() = 0;
};

// ��ʵ�����ɫ
class RealSubject :public Subject
{
public:
	RealSubject(){}
	void method(){
		//printf("����ҵ�񷽷�\n");
		printf("call method.\n");
	}
};

// Log��
class Log
{
public:
	Log(){}
	string getTime(){
		time_t t = time(NULL);
		char ch[64] = { 0 };
		//��-��-�� ʱ:��:��
		strftime(ch, sizeof(ch)-1, "%Y-%m-%d %H:%M:%S", localtime(&t));     
		return ch;
	}
};

// ������
class Proxy:public Subject
{
public:
	Proxy(){
		realSubject = new RealSubject();
		log = new Log();
	}
	void preCallMethod(){
		//printf("����method()�����ã�����ʱ��Ϊ%s\n",log->getTime().c_str());
		printf("method()is called, time is:%s\n",log->getTime().c_str());
	}
	void method(){
		preCallMethod();
		realSubject->method();
		postCallMethod();
	}
	void postCallMethod(){
		//printf("����method()���õ��óɹ�!\n");
		printf("method() called completed.!\n");
	}
private:
	RealSubject *realSubject;
	Log* log;
};

#endif //__FLYPATTERN_PATTERN_H__
