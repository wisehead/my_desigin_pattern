#include "AllyCenter.h"
#include "Observer.h"

/***********   AllyCenter    ****************/
AllyCenter::AllyCenter(){
	//printf("�󼪴���������Լ�!\n");
	printf("Da ji Da li, eat chicken tobight!\n");
}

// �������
void AllyCenter::join(Observer* player){
	if (playerList.size() == 4){
		//printf("�������\n");
		printf("players are enough.\n");
		return;
	}
	//printf("��� %s ����\n", player->getName().c_str());
	printf("player: %s joined.\n", player->getName().c_str());
	playerList.push_back(player);
	if (playerList.size() == 4){
		//printf("��ӳɹ�����Ҫ�ˣ�һ���ϣ�\n");
		printf("team is built up, gogogo!!!\n");
	}
}
// �Ƴ����
void AllyCenter::remove(Observer* player){
	//printf("��� %s �˳�\n", player->getName().c_str());
	printf("player:%s quit.\n", player->getName().c_str());
	//playerList.remove(player);
}
/***********   AllyCenter    ****************/


/**********   AllyCenterController    *******/
AllyCenterController::AllyCenterController(){

}

// ʵ��֪ͨ����
void AllyCenterController::notify(INFO_TYPE infoType, std::string name){
	switch (infoType){
	case RESOURCE:
		for(Observer* obs : playerList){
			if (obs->getName() != name){
				((Player*)obs)->come();
			}
		}
		break;
	case HELP:
		for (Observer* obs : playerList){
			if (obs->getName() != name){
				((Player*)obs)->help();
			}
		}
		break;
	default:
		printf("Nothing\n");
	}
}
/**********   AllyCenterController    *******/
