#include "Entity.h"

Entity::Entity(int x, int y, int r, int g, int b, int width, int height)
	: x(x), y(y), r(r), g(g), b(b), width(width), height(height) {}

void Entity::draw(Graphics& gfx) const
{
	for(int i = x; i < x + width; ++i)
		for(int j = y; j < y + height; ++j)
			gfx.PutPixel(i, j, r, g, b);
}

bool Entity::checkCollision(const Entity& one, const Entity& two) 
{
	return
		one.x < two.x + two.width && // left <= right
		one.x + one.width > two.x && // right >= left
		one.y < two.y + two.height && // top <= bottom
		one.y + one.height > two.y; // bottom >= top
}