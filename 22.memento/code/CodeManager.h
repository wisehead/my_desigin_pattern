#ifndef __CODEMANAGER_H__
#define __CODEMANAGER_H__

#include "Memento.h"
#include <vector>
using namespace std;

// ������
class CodeManager
{
public:
	CodeManager(){}
	void commit(Memento* m){
		printf("commit:version-%d, date-%s, label-%s\n", m->getVersion(), m->getDate().c_str(), m->getLabel().c_str());
		mementoList.push_back(m);
	}
	// �л���ָ���İ汾�������˵�ָ���汾
	Memento* switchToPointedVersion(int index){
		mementoList.erase(mementoList.begin() + mementoList.size() - index, mementoList.end());
		return mementoList[mementoList.size() - 1];
	}
	// ��ӡ��ʷ�汾
	void codeLog(){
		for (int i = 0; i < mementoList.size(); i++){
			printf("[%d]:version-%d, date-%s, label-%s\n", i, mementoList[i]->getVersion(),
				mementoList[i]->getDate().c_str(), mementoList[i]->getLabel().c_str());
		}
	}
private:
	vector<Memento*> mementoList;
};

#endif
