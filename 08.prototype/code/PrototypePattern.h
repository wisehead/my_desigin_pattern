#ifndef __PROTOTYPE_PATTERN__
#define __PROTOTYPE_PATTERN__

#include <iostream>
#include <string.h>
using namespace std;

//work model��
class WorkModel
{
public:
	char *modelName;
	void setWorkModelName(char *iName){
		this->modelName = iName;
	}
};

//����ԭ����PrototypeWork
class PrototypeWork
{
public:
	PrototypeWork(){}
	virtual PrototypeWork *clone() = 0;

private:
	
};

//����ԭ����ConcreteWork
class ConcreteWork :public PrototypeWork
{
public:
	ConcreteWork(){}
	ConcreteWork(char* iName, int iIdNum, char* modelName){
		this->name = iName;
		this->idNum = iIdNum;
		this->workModel = new WorkModel();
		this->workModel->setWorkModelName(modelName);
	}
	
	ConcreteWork *clone(){
		ConcreteWork *work = new ConcreteWork();
		work->setName(this->name);
		work->setIdNum(this->idNum);
		work->workModel = this->workModel;
		return work;
	}

	void setName(char* iName){
		this->name = iName;
	}
	void setIdNum(int iIdNum){
		this->idNum = iIdNum;
	}
	void setModel(WorkModel *iWorkModel){
		this->workModel = iWorkModel;
	}
	//��ӡwork��Ϣ
	void printWorkInfo(){
		printf("name:%s\t\n", this->name);
		printf("idNum:%d\t\n", this->idNum);
		printf("modelName:%s\t\n", this->workModel->modelName);
	}
private:
	char* name;
	int idNum;
	WorkModel *workModel;
};

#endif //__PROTOTYPE_PATTERN__