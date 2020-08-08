#include "SnakeHead.h"
#include <cstdlib>

SnakeHead::SnakeHead(int x, int y, int delayChange, int svx, int svy)
	: SnakeBody(x, y, delayChange, 165, 42, 42)
{
	this->vx = svx, this->vy = svy;
	this->svx = svx, this->svy = svy;
}

void SnakeHead::changeDir(MainWindow& wnd)
{
	if (wnd.kbd.KeyIsPressed('W'))
		svy = -int(speed), svx = 0;
	if (wnd.kbd.KeyIsPressed('S'))
		svy = int(speed), svx = 0;
	if (wnd.kbd.KeyIsPressed('A'))
		svx = -int(speed), svy = 0;
	if (wnd.kbd.KeyIsPressed('D'))
		svx = int(speed), svy = 0;
 }

void SnakeHead::update()
{
	if (delayChange <= 0)
		delayChange = width, vx = svx, vy = svy;

	x += vx;
	y += vy;

	if (vx == 0 && vy == 0)
		delayChange -= int(speed);
	else
		delayChange -= abs(vx) + abs(vy);

	/*
	top left 
	2nd snake part is going to take head top left as the var 
	head going to store
	   h.  
	  .h.   
	  .b   
	   b.    2 * 5 iterations = 10 out of 20
	*/
	// .
	//.h.
	// .
}

void SnakeHead::draw(Graphics& gfx)
{
	for (int i = x; i < x + width; ++i)
		for (int j = y; j < y + height; ++j)
			gfx.PutPixel(i, j, r, g, b);
}
