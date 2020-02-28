#include <iostream>
#include "CommandPattern.h"

int main()
{
	// ʵ���������ߣ���ť
	Button *button = new Button();
	Command *lampCmd, *fanCmd;

	// ��ť���Ƶ��
	lampCmd = new LampCommand();
	button->setCommand(lampCmd);
	button->touch();
	button->touch();
	button->touch();

	printf("\n\n");

	// ��ť���Ʒ���
	fanCmd = new FanCommand();
	button->setCommand(fanCmd);
	button->touch();
	button->touch();
	button->touch();

#ifdef COMMAND_QUEUE

	printf("\n\n***********************************\n");
	Button2 *button2 = new Button2();
	Command *lampCmd2, *fanCmd2;
	CommandQueue *cmdQueue = new CommandQueue();

	// ��ť���Ƶ��
	lampCmd2 = new LampCommand();
	cmdQueue->addCommand(lampCmd2);

	// ��ť���Ʒ���
	fanCmd2 = new FanCommand();
	cmdQueue->addCommand(fanCmd2);

	button2->setCommandQueue(cmdQueue);
	button2->touch();

#endif

	printf("\n\n");
	system("pause");
	return 0;
}