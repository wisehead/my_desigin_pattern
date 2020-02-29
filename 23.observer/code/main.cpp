#include "Observer.h"
#include "AllyCenter.h"

int main()
{
	// ����һ��ս��
	AllyCenterController* controller = new AllyCenterController();

	// ����4����ң�������ս��
	Player* Jungle = new Player("Jungle");
	Player* Single = new Player("Single");
//	Player* Jianmengtu = new Player("������");
	Player* Jianmengtu = new Player("Jianpengtu");
	//Player* SillyDog = new Player("ɵ�ӹ�");
	Player* SillyDog = new Player("SHazigou");
	controller->join(Jungle);
	controller->join(Single);
	controller->join(Jianmengtu);
	controller->join(SillyDog);

	printf("\n\n");

	// Jungle�������ʣ����ж���
	Jungle->call(RESOURCE, controller);

	printf("\n\n");

	// ɵ�ӹ�����Σ�գ���ȶ���
	SillyDog->call(HELP, controller);

	printf("\n\n");
	system("pause");
	return 0;
}
