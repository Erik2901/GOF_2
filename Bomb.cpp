
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}

void BombDecorator::Draw() const
{
    bomb.Draw();
    GotoXY(bomb.GetX(), bomb.GetY() - 1);
    cout << "|";
}

void BombDecorator::Move(uint16_t time) {
    bomb.Move(time * 1.6);
}

void BombDecorator::SetPos(double nx, double ny) 
{ 
    bomb.SetPos(nx, ny); 
}
uint16_t BombDecorator::GetWidth() const 
{ 
    return bomb.GetWidth(); 
}
