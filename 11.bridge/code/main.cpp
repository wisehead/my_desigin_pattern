#include <iostream>
#include "BridgePattern.h"

int main()
{
	Game *game;
	Phone *phone;

	//Jungle����PhoneAƷ�Ƶ��ֻ���������ϷA
	phone = new PhoneA();
	game = new GameA();
	phone->setupGame(game);
	phone->play();
	printf("++++++++++++++++++++++++++++++++++\n");

	//Jungle��������ֻ�������ϷB
	game = new GameB();
	phone->setupGame(game);
	phone->play();

	system("pause");
	return 0;
}