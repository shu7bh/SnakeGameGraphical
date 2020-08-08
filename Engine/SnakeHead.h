#pragma once
#include "SnakeBody.h"
class SnakeHead :
    public SnakeBody
{    
public:
    SnakeHead(int x, int y, int delayChange = 0, int svx = 0, int svy = 0);

    void changeDir(MainWindow& wnd) override;
    void update() override;

    void draw(Graphics& gfx) override;
};

