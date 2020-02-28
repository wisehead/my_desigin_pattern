#ifndef __COMMAND_PATTERN_H__
#define __COMMAND_PATTERN_H__

#include <mutex>
#include <time.h>
using namespace std;

//  ���������
#define COMMAND_QUEUE

// ���������� Command
class Command
{
public:
	Command(){}
	// ��������ӿڣ���������
	virtual void execute() = 0;
private:
	Command *command;
};

// �����ߣ������
class Lamp
{
public :
	Lamp(){
		this->lampState = false;
	}
	void on(){
		lampState = true;
		printf("Lamp is on\n");
	}
	void off(){
		lampState = false;
		printf("Lamp is off\n");
	}
	bool getLampState(){
		return lampState;
	}
private:
	bool lampState;
};

// �����ߣ�������
class Fan
{
public:
	Fan(){
		this->fanState = false;
	}
	void on(){
		fanState = true;
		printf("Fan is on\n");
	}
	void off(){
		fanState = false;
		printf("Fan is off\n");
	}
	bool getFanState(){
		return fanState;
	}
private:
	bool fanState;
};

// ���������� LampCommand
class LampCommand :public Command
{
public:
	LampCommand(){
		//printf("���ؿ��Ƶ��\n");
		printf("Switch for lamp.\n");
		lamp = new Lamp();
	}
	// ʵ��execute()
	void execute(){
		if (lamp->getLampState()){
			lamp->off();
		}
		else{
			lamp->on();
		}
	}
private:
	Lamp *lamp;
};

// ���������� FanCommand
class FanCommand :public Command
{
public:
	FanCommand(){
		//printf("���ؿ��Ʒ���\n");
		printf("Switch for Fan.\n");
		fan = new Fan();
	}
	// ʵ��execute()
	void execute(){
		if (fan->getFanState()){
			fan->off();
		}
		else{
			fan->on();
		}
	}
private:
	Fan *fan;
};

// ������ Button
class Button
{
public:
	Button(){}
	// ע��������������
	void setCommand(Command *cmd){
		this->command = cmd;
	}
	// �������������ť
	void touch(){
		//printf("��������:");
		printf("Touching the switch.......:");
		command->execute();
	}
private:
	Command *command;
};

#ifdef COMMAND_QUEUE
/*************************************/
/*             �������              */
#include <vector>

// ���������
class CommandQueue
{
public:
	CommandQueue(){
	}
	void addCommand(Command *cmd){
		commandQueue.push_back(cmd);
	}
	void execute(){
		for (int i = 0; i < commandQueue.size(); i++)
		{
			commandQueue[i]->execute();
		}
	}
private:
	vector<Command*>commandQueue;

};

// ������
class Button2
{
public:
	Button2(){}
	// ע�����������������
	void setCommandQueue(CommandQueue *cmdQueue){
		this->cmdQueue = cmdQueue;
	}
	// �������������ť
	void touch(){
		//printf("��������:");
		printf("Buffon2 touching the button........");
		cmdQueue->execute();
	}
private:
	CommandQueue *cmdQueue;
};

#endif


#endif //__COMMAND_PATTERN_H__
