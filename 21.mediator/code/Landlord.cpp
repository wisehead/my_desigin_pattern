#include "Colleague.h"
#include "Mediator.h"

Landlord::Landlord(){
	name = "none";
	price = 0;
	address = "none";
	phoneNumber = "none";
	setPersonType(NONE_PERSON);
}

Landlord::Landlord(string iName, int iPrice, 
	string iAddress, string iPhoneNum){
	name = iName;
	price = iPrice;
	address = iAddress;
	phoneNumber = iPhoneNum;
	setPersonType(LANDLORD);
}

void Landlord::answer(){
	/*
	printf("����������%s, ���⣺%d, ��ַ��%s, ��ϵ�绰��%s\n",
		*/
	printf("holder name:%s, prixce:%d, addr:%s, tel:%s\n",
		name.c_str(), price, address.c_str(), phoneNumber.c_str());
}

void Landlord::ask(){
	//printf("����%s�鿴�����Ϣ��\n",name.c_str());
	printf("holder:%s is looking up tenants' info.\n",name.c_str());
	(this->getMediator())->operation(this);
}
