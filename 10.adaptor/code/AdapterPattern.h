#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream>
#include <string.h>
#include <mutex>
using namespace std;

//Ŀ�������
class Controller
{
public:
	Controller(){}
	virtual void pathPlanning() = 0;
private:
};

//��������DxfParser
class DxfParser
{
public:
	DxfParser(){}
	void parseFile(){
		//printf("�����ļ���ȡ����\n");
		printf("parsing file and extracting data..\n");
	}
};

//��������PathPlanner
class PathPlanner
{
public:
	PathPlanner(){}
	void calculate(){
		//printf("����ӹ�·��\n");
		printf("computing the paths.\n");
	}
};

//��������Adapter
class Adapter:public Controller
{
public:
	Adapter(){
		dxfParser = new DxfParser();
		pathPlanner = new PathPlanner();
	}
	void pathPlanning(){
		//printf("·���滮��\n");
		printf("path management.\n");
		dxfParser->parseFile();
		pathPlanner->calculate();
	}
private:
	DxfParser   *dxfParser;
	PathPlanner *pathPlanner;
};

#endif //__SINGLETON_H__
