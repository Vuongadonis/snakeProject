/*
 * snake.c
 *
 *  Created on: Dec 3, 2023
 *      Author: TVB09
 */

#include "snake.h"
#include "lcd.h"

struct info snake[3000];
int lengthOfArray= 3000;
int direction= RIGHT;

void initGame()
{
	snake[0].x= 30;
	snake[0].y= 0;
	snake[1].x= 25;
	snake[1].y= 0;
	snake[2].x= 20;
	snake[2].y= 0;
	snake[3].x= 15;
	snake[3].y= 0;
	snake[4].x= 10;
	snake[4].y= 0;
	snake[5].x= 5;
	snake[5].y= 0;
	snake[6].x= 0;
	snake[6].y= 0;
	for (int i= 7; i < 1000; i++)
	{
		snake[i].x= 0;
		snake[i].y= 0;
	}
	direction= RIGHT;
//	snakeLength= 1;
}

void goLeft()
{

	switch (direction)
	{
	case RIGHT:
		goRight();
	default:
		direction= LEFT;
		for (int i= 1000; i >= 0; i--)
		{
			if (i== 0)
			{
				snake[i].x -= 5;
				snake[i].y= snake[i].y;
			}
			else
			{
				if (snake[i].x || snake[i].y)
				{
					snake[i].x= snake[i- 1].x;
					snake[i].y= snake[i-1].y;
				}
			}
		}
		break;
	}
}

void goRight()
{
	switch (direction)
	{
	case LEFT:
		goLeft();
		break;
	default:
		direction= RIGHT;
		for (int i= 1000; i >= 0; i--)
		{
			if (i== 0)
			{
				snake[i].x+= 5;
				snake[i].y= snake[i].y;
			}
			else
			{
				if (snake[i].x || snake[i].y)
				{
					snake[i].x= snake[i-1 ].x;
					snake[i].y= snake[i-1 ].y;
				}
			}
		}
		break;
	}
}

void goUp()
{
	switch (direction)
	{
	case DOWN:
		goUp();
		break;
	default:
		direction= UP;
		for (int i= 1000; i >= 0; i--)
		{
			if (i== 0)
			{
				snake[i].x = snake[i].x;
				snake[i].y-= 5;
			}
			else
			{
				if (snake[i].x || snake[i].y)
				{
					snake[i].x= snake[i-1].x;
					snake[i].y= snake[i-1].y;
				}
			}
		}
		break;
	}
}

void goDown()
{
	switch (direction)
	{
	case UP:
		goDown();
		break;
	default:
		direction= DOWN;
		for (int i= 1000; i >= 0; i--)
		{
			if (i== 0)
			{
				snake[i].x= snake[i].x;
				snake[i].y+= 5;
			}
			else
			{
				if (snake[i].x || snake[i].y)
				{
					snake[i].x= snake[i-1].x;
					snake[i].y= snake[i-1].y;
				}
			}
		}
		break;
	}
}

void move()
{
	switch (direction)
	{
		case DOWN:
			goDown();
			break;
		case UP:
			goUp();
			break;
		case RIGHT:
			goRight();
			break;
		case LEFT:
			goLeft();
			break;
		default:
			break;
	}
}

void displaySnake()
{
	for (int i= 0; i < 1000; i++)
	{
		if (i == 0)
		{
			lcd_Fill(snake[i].x, snake[i].y, snake[i].x+ 5, snake[i].y+ 5, BLUE);
		}
		else
		{
			if (snake[i].x || snake[i].y)
				lcd_Fill(snake[i].x, snake[i].y, snake[i].x+ 5, snake[i].y+ 5, BLUE);
			else
				break;
		}
	}
}
