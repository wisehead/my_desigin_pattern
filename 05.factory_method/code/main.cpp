#include <iostream>
#include "FactoryMethod.h"

int main()
{
	printf("��������ģʽ\n");
	
	//���幤�������Ͳ�Ʒ�����
	AbstractFactory *fac = NULL;
	AbstractSportProduct *product = NULL;

	fac = new BasketballFactory();
	product = fac->getSportProduct();

	fac = new FootballFactory();
	product = fac->getSportProduct();

	fac = new VolleyballFactory();
	product = fac->getSportProduct();	

	system("pause");
	return 0;
}