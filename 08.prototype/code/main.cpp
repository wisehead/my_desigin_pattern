#include "PrototypePattern.h"

int main()
{
#if 0
	ConcreteWork *singleWork = new ConcreteWork("Single",1001,"Single_Model");
	printf("\nSingle����ҵ��\n");
	singleWork->printWorkInfo();
	
	printf("\njungleֱ�ӳ���ҵ����\n");
	ConcreteWork *jungleWork = singleWork;
	printf("\nJungle����ҵ��\n");
	jungleWork->printWorkInfo();

	//��������ֺ�ѧ�ţ�����ᱻ��ʦ�����
	printf("\njungle��������ֺ�ѧ�ţ�����ᱻ��ʦ���������\n");
	jungleWork->setName("jungle");
	jungleWork->setIdNum(1002);
	WorkModel *jungleModel = new WorkModel();
	jungleModel->setWorkModelName("Jungle_Model");
	jungleWork->setModel(jungleModel);
	
	//������Ƿ�Ķ���
	printf("\nSingle����ҵ��\n");
	singleWork->printWorkInfo();
	printf("\nJungle����ҵ��\n");
	jungleWork->printWorkInfo();
#endif 

	ConcreteWork *singleWork = new ConcreteWork("Single", 1001, "Single_Model");
	printf("\nSingle����ҵ��\n");

	ConcreteWork *jungleWork = singleWork->clone();
	printf("\nJungle����ҵ��\n");

	//��������ֺ�ѧ�ţ�����ᱻ��ʦ�����
	printf("\njungle��������ֺ�ѧ�ţ�����ᱻ��ʦ���������\n");
	jungleWork->setName("jungle");
	jungleWork->setIdNum(1002);
	WorkModel *jungleModel = new WorkModel();
	jungleModel->setWorkModelName("Jungle_Model");
	jungleWork->setModel(jungleModel);

	//������Ƿ�Ķ���
	printf("\nSingle����ҵ��\n");
	singleWork->printWorkInfo();
	printf("\nJungle����ҵ��\n");
	jungleWork->printWorkInfo();

	system("pause");
	return 0;
}