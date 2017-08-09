#pragma once
#ifndef ROBAK_H
#define ROBAK_H

using namespace std;

enum Dir
{
	STOP = 0,
	UP = 1,
	RIGHT = 2,
	DOWN = 3,
	LEFT = 4
};

class Robak
{
private:
	int X;
	int Y;
	int StartX, StartY;
	Dir eDir;
	int score;
	int nTail;

public:
	Robak(int x, int y)
		: X(x), Y(y), StartX(x), StartY(y), eDir(STOP)
	{
		nTail = 1;
		score = 0;
	}

	int tailX[100];
	int tailY[100];

	void changeDirection(Dir d)
	{
		eDir = d;
	}

	void move()
	{
		switch (eDir)
		{
		case STOP:
			break;
		case UP:
			Y--;
			break;
		case RIGHT:
			X++;
			break;
		case DOWN:
			Y++;
			break;
		case LEFT:
			X--;
			break;
		default:
			break;
		}
	}

	Dir getDirection() { return eDir; }

	int getTail() { return nTail; }
	int getScore() { return score; }
	int getX() { return X; }
	int getY() { return Y; }
	void setX(int x) { X = x; }
	void setY(int y) { Y = y; }
	void setScore() { score += 10; }
	void setTail() { nTail++; }

	void TailMove()
	{
		int prevX = tailX[0];
		int prevY = tailY[0];

		int prev2X, prev2Y;

		tailX[0] = X;
		tailY[0] = Y;

		for (int i = 1; i < nTail; i++)
		{
			prev2X = tailX[i];
			prev2Y = tailY[i];

			tailX[i] = prevX;
			tailY[i] = prevY;

			prevX = prev2X;
			prevY = prev2Y;
		}
	}

	void setBonusScore()
	{
		score += 50;
	}
};

#endif // 


