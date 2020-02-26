#include <iostream>
#include "FlyweightPattern.h"

int main()
{
	NetDeviceFactory *factory = NetDeviceFactory::getFactory();

	NetDevice *device1, *device2, *device3, *device4;

	// �ͻ���2��ȡһ��hub
	device1 = factory->getNetDevice('H');
	device1->print(1);
	// �ͻ���2��ȡһ��hub
	device2 = factory->getNetDevice('H');
	device2->print(2);
	// �ж�����hub�Ƿ���ͬһ��
	//printf("�ж�����hub�Ƿ���ͬһ��:\n");
	printf("check wether the two hubs are the same.\n");
	printf("device1:%p\ndevice2:%p\n", device1, device2);

	printf("\n\n\n\n");
	// �ͻ���3��ȡһ��switch
	device3 = factory->getNetDevice('S');
	device3->print(1);
	// �ͻ���4��ȡһ��hub
	device4 = factory->getNetDevice('S');
	device4->print(2);
	// �ж�����hub�Ƿ���ͬһ��
	//printf("�ж�����switch�Ƿ���ͬһ��:\n");
	printf("check wether the two switches are the same.\n");
	printf("device3:%p\ndevice4:%p\n", device3, device4);

	printf("\n\n");

	system("pause");
	return 0;
}
