#include <iostream>
#include "SimpleFactory.h"

int main()
{
	//printf("�򵥹���ģʽ\n");
	//cout<<"�򵥹���ģʽ"<<endl;
	cout<<"simple factory pattern"<<endl;
	
	//���幤�������
	Factory *fac = new Factory();
	AbstractSportProduct *product = NULL;

	product = fac->getSportProduct("Basketball");

	product = fac->getSportProduct("Football");

	product = fac->getSportProduct("Volleyball");	

	system("pause");
	return 0;
}
