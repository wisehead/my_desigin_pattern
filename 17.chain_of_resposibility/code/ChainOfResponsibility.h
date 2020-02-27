#ifndef __CHAIN_OF_RESPONSIBILITY_PATTERN_H__
#define __CHAIN_OF_RESPONSIBILITY_PATTERN_H__

#include <mutex>
#include <time.h>
using namespace std;

// ����Ʊ��
class Bill
{
public:
	Bill(){}
	Bill(int iId, string iName, double iAccount){
		id = iId;
		name = iName;
		account = iAccount;
	}
	double getAccount(){
		return this->account;
	}
	void print(){
		printf("\nID:\t%d\n", id);
		printf("Name:\t%s\n", name.c_str());
		printf("Account:\t%f\n", account);
	}
private:
	int id;
	string name;
	double account;
};
// ��������
class Approver
{
public:
	Approver(){}
	Approver(string iName){
		setName(iName);
	}
	// ����ϼ�
	void setSuperior(Approver *iSuperior){
		this->superior = iSuperior;
	}
	// ��������
	virtual void handleRequest(Bill*) = 0;
	string getName(){
		return name;
	}
	void setName(string iName){
		name = iName;
	}
protected:
	Approver *superior;
private:
	string name;
};

// ���崦���ߣ��鳤
class GroupLeader :public Approver
{
public:
	GroupLeader(){}
	GroupLeader(string iName){
		setName(iName);
	}
	// ��������
	void handleRequest(Bill *bill){
		if (bill->getAccount() < 10){
			//printf("�鳤 %s �����˸�Ʊ�ݣ�Ʊ����Ϣ��",this->getName().c_str());
			printf("Team Leader %s handled the bill, details info:��",this->getName().c_str());
			bill->print();
		}
		else{
			//printf("�鳤��Ȩ����ת���ϼ�����\n");
			printf("team leader can't handle, pass to supervisor.\n");
			this->superior->handleRequest(bill);
		}
	}
};

// ���崦���ߣ�����
class Head :public Approver
{
public:
	Head(){}
	Head(string iName){
		setName(iName);
	}
	// ��������
	void handleRequest(Bill *bill){
		if (bill->getAccount() >= 10 && bill->getAccount()<30){
			printf("Head %s handled the bill, details:", this->getName().c_str());
			bill->print();
		}
		else{
			//printf("������Ȩ����ת���ϼ�����\n");
			printf("Head can't handle, pass to the supervisor.\n");
			this->superior->handleRequest(bill);
		}
	}
};

// ���崦���ߣ�����
class Manager :public Approver
{
public:
	Manager(){}
	Manager(string iName){
		setName(iName);
	}
	// ��������
	void handleRequest(Bill *bill){
		if (bill->getAccount() >= 30 && bill->getAccount()<60){
			//printf("���� %s �����˸�Ʊ�ݣ�Ʊ����Ϣ��", this->getName().c_str());
			printf("Manager %s handled the bill, details.", this->getName().c_str());
			bill->print();
		}
		else{
			//printf("������Ȩ����ת���ϼ�����\n");
			printf("manager can't handle, pass to supervisor.\n");
			this->superior->handleRequest(bill);
		}
	}
};

// ���崦���ߣ��ϰ�
class Boss :public Approver
{
public:
	Boss(){}
	Boss(string iName){
		setName(iName);
	}
	// ��������
	void handleRequest(Bill *bill){
		//printf("�ϰ� %s �����˸�Ʊ�ݣ�Ʊ����Ϣ��", this->getName().c_str());
		printf("BOSS %s handled the bill, details.", this->getName().c_str());
		bill->print();
	}
};

#endif //__CHAIN_OF_RESPONSIBILITY_PATTERN_H__
