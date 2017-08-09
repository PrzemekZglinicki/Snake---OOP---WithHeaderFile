#pragma once
#ifndef GAMEMENAGER_H
#define GAMEMENAGER_H

using namespace std;

#include "Robak.h"
#include "Plansza.h"

class cGameMenager
{
private:

	int xF, yF;
	bool bQuit;
	Robak *Snake;
	Plansza *Table;
	Owoc *Fruit;
	Dir eDir;
	Bomba *Bomb;
	Bonus *Bon;
	bool BonusTime;

public:
	cGameMenager(int w, int h)
	{
		srand(time(NULL));
		eDir = STOP;
		bQuit = false;
		Snake = new Robak(w / 2, h / 2);
		Fruit = new Owoc(rand() % w, rand() % h);
		Bomb = new Bomba();
		Bon = new Bonus();
		Table = new Plansza(w, h, Snake, Fruit, Bomb, Bon);
		BonusTime = false;

	}

	~cGameMenager()
	{
		//delete Fruit;
		//delete Snake;
		delete Table;
	}

	void Input()
	{
		Snake->move();

		if (_kbhit())
		{
			int snakeX = Snake->getX();
			int snakeY = Snake->getY();

			char current = _getch();

			if (Snake->getDirection() == STOP)
			{
				Snake->changeDirection(eDir);
			}

			if (current == 'w')
			{
				Snake->changeDirection(UP);
			}

			if (current == 'd')
				Snake->changeDirection(RIGHT);
			if (current == 's')
				Snake->changeDirection(DOWN);
			if (current == 'a')
				Snake->changeDirection(LEFT);

			if (current == 'q')
			{
				cout << "THE END" << endl;
				bQuit = true;
			}
		}
	}

	void Logic()
	{
		Snake->TailMove();

		int Snakex = Snake->getX();
		int Snakey = Snake->getY();
		int width = Table->getW();
		int height = Table->getH();

		if (Snakex < 0)
			Snake->setX(width);
		if (Snakex >= width)
			Snake->setX(0);
		if (Snakey < 0)
			Snake->setY(height);
		if (Snakey >= height)
			Snake->setY(0);

		/*
		if (Snakex == 0)
		Snake->changeDirection(RIGHT);
		if (Snakex == width)
		Snake->changeDirection(LEFT);
		if (Snakey == 0)
		Snake->changeDirection(DOWN);
		if (Snakey == height)
		Snake->changeDirection(UP);
		if (Snakex == 0)
		Snake->changeDirection(RIGHT);
		if (Snakex == width)
		Snake->changeDirection(LEFT);
		if (Snakey == 0)
		bQuit = true;
		if (Snakey == height)
		bQuit = true;
		*/

		/////////////////////////////////////////////
		if (Snake->getX() == Fruit->getX() && Snake->getY() == Fruit->getY())
		{
			Snake->setScore();
			Fruit->RandFruit(Table->getW(), Table->getH());
			Snake->setTail();
			Bomb->RandomShow(width, height);
			if (Snake->getTail() % 3 == 0)
			{
				Bon->RandBonus(width, height);
				BonusTime = true;
			}
		}

		if (BonusTime && Plansza::nCounter % 50 == 0)
		{
			Bon->Reset();
			BonusTime = false;
		}

		if (Snake->getX() == Bon->getX() && Snake->getY() == Bon->getY())
		{
			Snake->setBonusScore();
			Bon->Reset();
		}

		if (Snake->getX() == Bomb->getX() && Snake->getY() == Bomb->getY())
		{
			bQuit = true;
		}


		/////////////////////////////////////////////		
		for (int i = 0; i < Snake->getTail(); i++)
		{
			if (Snake->tailX[i + 1] == Snake->getX() && Snake->tailY[i + 1] == Snake->getY())
				bQuit = true;
		}
	}

	void Run()
	{
		while (!bQuit)
		{
			Table->Draw();
			Input();
			Logic();
			Sleep(100);
			Plansza::nCounter++;

		}
	}
};


#endif // !GAMEMENAGER_H
