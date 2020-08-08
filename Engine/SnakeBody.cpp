#include "SnakeBody.h"
#include <cstdlib>

float SnakeBody::speed = 2;
SnakeBody::SnakeBody(int x, int y, int delayChange, int r, int g, int b)
	: Entity(x, y, r, g, b, 20, 20), delayChange(delayChange) {}

SnakeBody::SnakeBody(int x, int y, int delayChange, int svx, int svy)
	: Entity(x, y, 205, 82, 82), delayChange(delayChange)
{
	this->vx = svx, this->vy = svy;
	this->svx = svx, this->svy = svy;//210 180 140 
}

int SnakeBody::VX() const { return vx; }

int SnakeBody::VY() const { return vy; }

int SnakeBody::DelayChange() const { return delayChange; }

void SnakeBody::setSVX(const int vx) 
{
	this->svx = vx;
	delayChange = width;
}

void SnakeBody::setSVY(const int vy)
{
	this->svy = vy;
	delayChange = width;
}

void SnakeBody::draw(Graphics& gfx)
{
	for (int i = x + 2; i < x + width - 2; ++i)
		for (int j = y + 2; j < y + height - 2; ++j)
			gfx.PutPixel(i, j, r, g, b);
}

void SnakeBody::update()
{	
	if (delayChange == width)
		vx = svx, vy = svy;

	x += vx;
	y += vy;

	delayChange -= abs(vx) + abs(vy);
}
