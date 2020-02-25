#ifndef __BRIDGE_PATTERN_H__
#define __BRIDGE_PATTERN_H__

#include <iostream>
#include <string.h>
#include <mutex>
using namespace std;

//ʵ����ӿ�
class Game
{
public:
	Game(){}
	virtual void play() = 0;
private:
};

//����ʵ����GameA
class GameA:public Game
{
public:
	GameA(){}
	void play(){
		printf("Jungle����ϷA\n");
	}
};

//����ʵ����GameB
class GameB :public Game
{
public:
	GameB(){}
	void play(){
		printf("Jungle����ϷB\n");
	}
};

//������Phone
class Phone
{
public:
	Phone(){
	}
	//��װ��Ϸ
	virtual void setupGame(Game *igame) = 0;
	virtual void play() = 0;
private:
	Game *game;
};

//���������PhoneA
class PhoneA:public Phone 
{
public:
	PhoneA(){
	}
	//��װ��Ϸ
	void setupGame(Game *igame){
		this->game = igame;
	}
	void play(){
		this->game->play();
	}
private:
	Game *game;
};

//���������PhoneB
class PhoneB :public Phone
{
public:
	PhoneB(){
	}
	//��װ��Ϸ
	void setupGame(Game *igame){
		this->game = igame;
	}
	void play(){
		this->game->play();
	}
private:
	Game *game;
};


#endif //__BRIDGE_PATTERN_H__