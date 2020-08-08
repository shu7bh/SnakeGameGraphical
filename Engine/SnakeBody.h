#pragma once
#include "Entity.h"
#include <random>
#include "MainWindow.h"
#include <ctime>

class SnakeBody :
    public Entity
{
private:
    std::default_random_engine generator;
    std::uniform_int_distribution<int> rg;

protected:
    int vx = 0, vy = 0;
    int svx = 0, svy = 0;
    int delayChange = width;
    static float speed;
public:
    SnakeBody(int x, int y, int delayChange, int r, int g, int b);
    SnakeBody(int x, int y, int delayChange, int svx = 0, int svy = 0);

    int VX() const;
    int VY() const;
    int DelayChange() const;

    void setSVX(const int vx);
    void setSVY(const int vy);

    virtual void draw(Graphics& gfx);

    virtual void update();
    virtual void changeDir(MainWindow& wnd) {};
};