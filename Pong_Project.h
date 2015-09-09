#pragma once
#include "sfwdraw.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//void main()
//{
//	sfw::initContext(800, 600, "Dinosaurs!");
//	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT, "Dinosaurs");
//
//
//	float xpos = 300, ypos = 400;
//
//	yvel += yacc * sfw::getDeltaTime();
//
//	sfw::drawCircle(xpos, ypos, 30);
//
//	sfw::drawLine(5, 5, 5, SCREEN_HEIGHT - 5);
//	sfw::drawLine(5, 5, SCREEN_WIDTH - 5, 5);
//
//	sfw::drawLine(SCREEN_WIDTH-5, SCREEN_HEIGHT-5, 5, SCREEN_HEIGHT-5);
//	sfw::drawLine(SCREEN_WIDTH - 5, SCREEN_HEIGHT - 5, SCREEN_WIDTH - 5, 5);
//
//}
/////////////// Players

struct Player
{
	int x;
	int y;	
	int width;
};

void drawPlayer(Player p)
{
	sfw::drawLine(p.x, p.y, p.x, p.y + p.width);
}



void main()
{
	sfw::initContext(800, 600, "Pong");


	Player one = {400,300,40};
	
	while (sfw::stepContext())
	{
		drawPlayer(one);
	}

	sfw::termContext();
}









