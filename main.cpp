#pragma once
#include "sfwdraw.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

struct Player
{
	float x;
	float y;
	float width;
	float speed;
};

void drawPlayer(Player p)
{
	sfw::drawLine(p.x, p.y, p.x, p.y + p.width);
}

void main()
{
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");

	Player one = { 10, SCREEN_HEIGHT/2, 40, 300 };

	while (sfw::stepContext())
	{
		if (sfw::getKey('w')) {
			float foo = sfw::getDeltaTime();
			one.y -= one.speed * foo;
		}
		if (sfw::getKey('s')) {
			float foo = sfw::getDeltaTime();
			one.y += one.speed * foo;
		}
		

		drawPlayer(one);
	}

	sfw::termContext();
}

void drawPlayer(Player p)
{
	sfw::drawLine(p.x, p.y, p.x, p.y + p.width);

	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");

	Player two = { -10, SCREEN_HEIGHT / 2, 40, 300 };

	while (sfw::stepContext())
	{
		if (sfw::getKey('8')) {
			float foo = sfw::getDeltaTime();
			two.y -= two.speed * foo;
		}
		if (sfw::getKey('2')) {
			float foo = sfw::getDeltaTime();
			two.y += two.speed * foo;
		}


		drawPlayer(two);
	}

	sfw::termContext();
}










