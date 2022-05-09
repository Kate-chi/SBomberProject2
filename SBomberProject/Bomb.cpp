
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


void BombDecorator::Move(uint16_t time)
{
	bomb->Move(time * 1.6);
}

void BombDecorator::Draw() const
{
	bomb->Draw();

	MyTools::GotoXY(bomb->GetX(), bomb->GetY() - 1);
	std::cout << "|";
}

void BombDecorator::SetPos(double nx, double ny) { bomb->SetPos(nx, ny); }

double BombDecorator::GetY() const { return bomb->GetY(); }

double BombDecorator::GetX() const { return bomb->GetX(); }

void BombDecorator::SetWidth(uint16_t widthN) { bomb->SetWidth(widthN); }

uint16_t BombDecorator::GetWidth() const { return bomb->GetWidth(); }
