#ifndef __FLYPATTERN_PATTERN_H__
#define __FLYPATTERN_PATTERN_H__

#include <mutex>
#include <vector>
using namespace std;

// ������Ԫ��
class NetDevice
{
public:
	NetDevice(){}
	virtual string getName() = 0;

	/*void print(){
		printf("NetDevice :%s\n",getName().c_str());
	}*/
	void print(int portNum){
		printf("NetDevice :%s  port: %d\n", getName().c_str(), portNum);
	}
};

// ������Ԫ��:������
class Hub :public NetDevice
{
public:
	Hub(){}
	string getName(){
		//return "������";
		return "Hub";
	}
};

// ������Ԫ��:������
class Switch :public NetDevice
{
public:
	Switch(){}
	string getName(){
		return "Switch";
	}
};

// ��Ԫ������
class NetDeviceFactory
{
public:
	NetDevice* getNetDevice(char ch){
		if (ch == 'S'){
			return devicePool[1];
		}
		else if (ch == 'H'){
			return devicePool[0];
		}
		else{
			printf("wrong input!\n");
		}
		return NULL;
	}

	// ����ģʽ��������Ԫ�������Ψһʵ��
	static NetDeviceFactory* getFactory(){
		if (instance == NULL){
			m_mutex.lock();
			if (instance == NULL){
				instance = new NetDeviceFactory();
			}
			m_mutex.unlock();
		}
		return instance;
	}

private:
	NetDeviceFactory(){
		Hub *hub = new Hub();
		Switch *switcher = new Switch();
		devicePool.push_back(hub);
		devicePool.push_back(switcher);
	}
	static NetDeviceFactory* instance;
	static std::mutex m_mutex;

	// ����أ���һ��vector����ʾ
	vector<NetDevice*> devicePool;
};

NetDeviceFactory* NetDeviceFactory::instance = NULL;
std::mutex NetDeviceFactory::m_mutex;

#endif //__FLYPATTERN_PATTERN_H__
