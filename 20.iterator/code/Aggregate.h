#ifndef __AGGREGATE_H__
#define __AGGREGATE_H__

#include <vector>
#include <string>
using namespace std;

// ǰ����������Ϊ�����໥������
class Iterator;
class RemoteControl;

// ����ۺ��� Aggregate
class Aggregate
{
public:
	Aggregate(){}
	virtual Iterator* createIterator() = 0;
};

// ����ۺ��� Television
class Television :public Aggregate
{
public:
	Television();
	Television(vector<string> iChannelList);
	// ʵ�ִ���������
	Iterator* createIterator();
	// ��ȡ�ܵ�Ƶ����Ŀ
	int getTotalChannelNum();
	void play(int i);
private:
	vector<string> channelList;
};

#endif //__AGGREGATE_H__
