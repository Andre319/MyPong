#pragma once
#include "sfwdraw.h"
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// defines a struct containing all of the variables related to a Player
struct Player
{
	float x;		// Position on the X-Axis
	float y;		// Position on the Y-Axis
	float width;
	float speed;	// Movement speed
};

struct Circle
{
	float xpos = 300, ypos = 400;	// Position
	float xvel = 200, yvel = 200;	// Velocity
	float radius = 10;				// Radius
	float xacc = 0, yacc = 0;		// Acceleration
};

void drawCircle(Circle c)
{
	sfw::drawCircle(c.xpos, c.ypos, c.radius);
}

void drawPlayer(Player p)
{
	sfw::drawLine(p.x, p.y, p.x, p.y + p.width);
}

void main()
{
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");

	Player one = { 10, SCREEN_HEIGHT/2, 80, 300 };
	Player two = {SCREEN_WIDTH-10, SCREEN_HEIGHT/2, 80, 300 };
	Circle ball;

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

		if (sfw::getKey('i')) {
			float foo = sfw::getDeltaTime();
			two.y -= two.speed * foo;
		}
		if (sfw::getKey('k')) {
			float foo = sfw::getDeltaTime();
			two.y += two.speed * foo;
		}

		ball.ypos += ball.yvel * sfw::getDeltaTime();
		ball.xpos += ball.xvel * sfw::getDeltaTime();
		////////////COLLISION/////////////////
		if (ball.ypos < 0 || ball.ypos >  SCREEN_HEIGHT )
		{ 
			ball.yvel *= -1; 
		}
		////// paddle collison/////
		if (ball.ypos > two.y &&
			ball.ypos < two.y + two.width && 
			ball.xpos > two.x-ball.radius)

		{
			
			ball.xvel *= -1;
		}
		
		if (ball.ypos >= one.y &&
			ball.ypos <= one.y + one.width &&
			ball.xpos <= ball.radius + one.x)

		{
			ball.xvel *= -1;
		}
		////////////// left paddle////////////
		if (one.y < 0)
			one.y = 0;
		else if (one.y + one.width > SCREEN_HEIGHT)
			one.y = SCREEN_HEIGHT - one.width;
		
		/////////////// right paddle//////////

		if (two.y < 0)
			two.y = 0;
		else if (two.y + two.width > SCREEN_HEIGHT)
			two.y = SCREEN_HEIGHT - two.width;
    //////////////// Reset the position of the ball///////////		
		
		
			
		
		
		
		
		
		//std::cout << "Ball Pos: " << ball.xpos << "," << ball.ypos << std::endl;

		drawCircle(ball);
		drawPlayer(one);
		drawPlayer(two);
	}

	sfw::termContext();
}












