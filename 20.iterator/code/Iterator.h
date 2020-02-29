#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#pragma once
#include "Aggregate.h"

#include <vector>
using namespace std;

// ���������
class Iterator
{
public:
	Iterator(){}
	// ���������������
	virtual void first() = 0;
	virtual void last() = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool hasNext() = 0;
	virtual bool hasPrevious() = 0;
	virtual void currentChannel() = 0;
private:

};

// ң���������������
class RemoteControl :public Iterator
{
public:
	RemoteControl(){}
	void setTV(Television *iTv){
		this->tv = iTv;
		cursor = -1;
		totalNum = tv->getTotalChannelNum();
	}
	// ʵ�ָ�����������
	void first(){
		cursor = 0;
	}
	void last(){
		cursor = totalNum - 1;
	}
	void next(){
		cursor++;
	}
	void previous(){
		cursor--;
	}
	bool hasNext(){
		return !(cursor == totalNum);
	}
	bool hasPrevious(){
		return !(cursor == -1);
	}
	void currentChannel(){
		tv->play(cursor);
	}
private:
	// �α�
	int cursor;
	// �ܵ�Ƶ����Ŀ
	int totalNum;
	// ����
	Television* tv;
};


#endif