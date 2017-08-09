#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
#include<ctime>
#include<time.h>
#include<cstdlib>

#include "GameMenager.h"
#include "Plansza.h"
#include "Robak.h"

using namespace std;


int main()
{
	int w = 30;
	int h = 20;
	cGameMenager Game(w, h);
	Game.Run();

	system("pause");
	return 0;
}