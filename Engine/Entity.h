#pragma once
#include "Graphics.h"

class Entity
{
protected:
	int x, y; //top left corner
	int r, g, b;
	int width, height;
public:
	Entity(int x, int y, int r = 255, int g = 255, int b = 255, int width = 20, int height = 20);
	bool isEaten = false;
	virtual void draw(Graphics& gfx) const;
	static bool checkCollision(const Entity& one, const Entity& two);

	int X() const { return x; }
	int Y() const { return y; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
};

typedef Entity Wall;
typedef Entity Food;