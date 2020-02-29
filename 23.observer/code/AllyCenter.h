#ifndef __ALLYCENTER_H__
#define __ALLYCENTER_H__

#include "common.h"
#include <vector>
#include <string>

// ǰ������
class Observer;
class Player;

// ����Ŀ�꣺��������
class AllyCenter
{
public:
	AllyCenter();
	// ����֪ͨ����
	virtual void notify(INFO_TYPE infoType, std::string name) = 0;
	// �������
	void join(Observer* player);
	// �Ƴ����
	void remove(Observer* player);
protected:
	// ����б�
	std::vector<Observer*>playerList;
};

// ����Ŀ��
class AllyCenterController :public AllyCenter
{
public:
	AllyCenterController();
	// ʵ��֪ͨ����
	void notify(INFO_TYPE infoType, std::string name);
};

#endif //__ALLYCENTER_H__
