// RetroSnake.cpp : 
//

#include <random>
#include <vector>
#include <stdio.h>
#include <tchar.h>
#include <thread>
#include <iostream>
#include <mutex>
#include <windows.h>
#include "snake.h"

#define A 10
#define msleep(mt) std::this_thread::sleep_for(std::chrono::milliseconds(mt));
#define mprint(str) std::cout << str << std::endl;
#define Rep(n) for(int i =0;i != n;++i)

void update();

int main(void)

{
	Snake retrosnake = Snake();
	retrosnake.showTheTable();
	getchar();

	char key, lastkey = '0';

	while (key =  getchar())
	{
		switch (key)
		{
		case 'w':
			if (lastkey != 's'){
				retrosnake.updateGame(top);
			}
			else{
				retrosnake.updateGame(bottom);
			}
			break;

		case 's':
			if (lastkey != 'a'){
				retrosnake.updateGame(bottom);
			}
			if (lastkey != 'a'){
				retrosnake.updateGame(top);
			}
			break;

		case 'a':
			if (lastkey != 'd'){
				retrosnake.updateGame(left);
			}
			else retrosnake.updateGame(right);
			break;

		case 'd':
			if (lastkey != 'a'){
				retrosnake.updateGame(right);
			}
			else retrosnake.updateGame(left);
			break;
		}
		lastkey = key;
		system("cls");
		retrosnake.showTheTable();
	}
}


void update()
{
	int i = 5;
	while (i--){
		// msleep(1000);
		//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		Sleep(1);
		mprint("Hello from thread ");
	}
}
