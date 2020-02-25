#include <iostream>
#include "CompositePattern.h"

int main()
{
	Component *head, *sichuanBranch, *cdBranch, *myBranch, *office1, *office2, *office3,
		*office4, *office5, *office6, *office7, *office8;

	head = new SubComponent("�ܲ�");
	sichuanBranch = new SubComponent("�Ĵ��ֲ�");
	office1 = new AdminOffice("�����칫��");
	office2 = new DeanOffice("����칫��");
	

	cdBranch = new SubComponent("�ɶ��ֲ�");
	myBranch = new SubComponent("�����ֲ�");
	office3 = new AdminOffice("�����칫��");
	office4 = new DeanOffice("����칫��");
	

	office5 = new AdminOffice("�����칫��");
	office6 = new DeanOffice("����칫��");
	

	office7 = new AdminOffice("�����칫��");
	office8 = new DeanOffice("����칫��");
	
	cdBranch->add(office5);
	cdBranch->add(office6);

	myBranch->add(office7);
	myBranch->add(office8);

	sichuanBranch->add(office3);
	sichuanBranch->add(office4);
	sichuanBranch->add(cdBranch);
	sichuanBranch->add(myBranch);

	head->add(office1);
	head->add(office2);
	head->add(sichuanBranch);
	

	head->operation();

	system("pause");
	return 0;
}