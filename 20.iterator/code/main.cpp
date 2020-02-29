#include <iostream>
#include "Iterator.h"

int main()
{
	//vector<string> channelList = { "����Ƶ��", "�ƾ�Ƶ��", "����Ƶ��", "��ӰƵ��", "����Ƶ��", "ũҵƵ��", "�Ĵ�����", "�ɶ�����" };
	vector<string> channelList = { "News Channel", "Finace CH", "CCTV5", "CCTV6", "MTV", "Farmer CH", "SiChuan TV", "Chengdu TV" };
	// ��������
	Television *tv = new Television(channelList);
	// ����ң����
	Iterator *remoteControl = tv->createIterator();

	// ˳�����
	//printf("˳�����:\n");
	printf("visit in order:\n");
	remoteControl->first();
	// ������������Ƶ��
	while (remoteControl->hasNext()){
		remoteControl->currentChannel();
		remoteControl->next();
	}

	printf("\n\n");

	// �������
	//printf("�������:\n");
	printf("visit in reverse order:\n");
	remoteControl->last();
	// ������������Ƶ��
	while (remoteControl->hasPrevious()){
		remoteControl->currentChannel();
		remoteControl->previous();
	}

	printf("\n\n");
	system("pause");
	return 0;
}
