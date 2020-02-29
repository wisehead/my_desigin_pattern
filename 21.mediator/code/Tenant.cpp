#include "Colleague.h"
#include "Mediator.h"

Tenant::Tenant(){
	name = "none";
	setPersonType(NONE_PERSON);
}

Tenant::Tenant(string iName){
	name = iName;
	setPersonType(TENANT);
}

void Tenant::ask(){
	//printf("���%sѯ�ʷ�����Ϣ\n", name.c_str()); 
	printf("tenant:%s is asking for holders' info.\n", name.c_str()); 
	(this->getMediator())->operation(this);
}

void Tenant::answer(){
	//printf("���������%s\n", name.c_str());
	printf("tenant's name:%s\n", name.c_str());
}
