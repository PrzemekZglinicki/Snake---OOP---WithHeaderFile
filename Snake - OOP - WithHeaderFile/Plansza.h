#pragma once
#ifndef PLANSZA_H
#define PLANSZA_H

using namespace std;

#include "Robak.h"

class Bomba
{
private:
	int X;
	int Y;

public:
	Bomba()
	{	}

	void RandomShow(int w, int h)
	{
		X = rand() % w;
		Y = rand() & h;
	}

	int getX() { return X; }
	int getY() { return Y; }



};

class Owoc
{
private:
	int X;
	int Y;

public:
	Owoc(int x, int y)
		: X(x), Y(y) {}

	int getX() { return X; }
	int getY() { return Y; }

	void RandFruit(int w, int h)
	{
		X = rand() % w;
		Y = rand() % h;
	}

};

class Bonus
{
private:
	int X;
	int Y;

public:
	Bonus() {}

	int getX() { return X; }
	int getY() { return Y; }

	void RandBonus(int w, int h)
	{
		X = rand() % w;
		Y = rand() % h;
	}

	void Reset()
	{
		X = -2;
		Y = -2;
	}
};

class Plansza
{
private:

	int width, height;
	Robak *Snake;
	Owoc *Fruit;
	Bomba *Bomb;
	Bonus *Bon;

public:
	static int nCounter;
	Plansza(int w, int h, Robak *S, Owoc *F, Bomba *B, Bonus *Bo)
		: width(w), height(h)
	{
		Snake = new Robak(w / 2, h / 2);
		Snake = S;
		Fruit = new Owoc(rand() % w, rand() % h);
		Fruit = F;
		Bomb = new Bomba();
		Bomb = B;
		Bon = new Bonus();
		Bon = Bo;
	}

	~Plansza()
	{
		delete Fruit;
		delete Snake;
	}

	void Draw()
	{
		system("cls");

		for (int i = 0; i < width + 2; i++)
			cout << "\xB2";

		cout << endl;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int SnakeX = Snake->getX();
				int SnakeY = Snake->getY();

				int FruitX = Fruit->getX();
				int FruitY = Fruit->getY();

				int BombX = Bomb->getX();
				int BombY = Bomb->getY();

				int BonX = Bon->getX();
				int BonY = Bon->getY();

				if (j == 0)
					cout << "\xB2";

				if (j == SnakeX && i == SnakeY)
				{
					cout << "O";
				}
				else if (j == FruitX && i == FruitY)
				{
					cout << "F";
				}
				else
				{
					bool print = false;

					for (int k = 0; k < Snake->getTail(); k++)
					{
						if (Snake->tailX[k] == j && Snake->tailY[k] == i)
						{
							cout << "o";
							print = true;
						}
					}

					if (j == BombX && i == BombY)
					{
						cout << "Q";
						print = true;
					}

					if (j == BonX && i == BonY)
					{
						cout << "B";
						print = true;
					}

					if (!print)
						cout << " ";
				}

				if (j == width - 1)
					cout << "\xB2";
			}

			cout << endl;
		}
		for (int i = 0; i < width + 2; i++)
			cout << "\xB2";

		cout << endl;
		cout << "Scores:" << Snake->getScore() << endl;
		cout << "Counter: " << nCounter << endl;
		cout << "F - Owocek - podstawa Twojego zycia! " << endl;
		cout << "Q - Bomba - uwazaj na nia!" << endl;
		cout << "B - Bonus - chwytaj ile mozesz, o ile zdazysz!" << endl;
	}

	int getW() { return width; }
	int getH() { return height; }

};

int Plansza::nCounter = 0;


#endif // !PLANSZA_H
