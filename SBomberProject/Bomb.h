#pragma once

#include "DynamicObject.h"

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

private:

};

class BombDecorator : public DynamicObject
{
private:
	Bomb* bomb;
public:
	BombDecorator(Bomb* b) : bomb(b) 
	{
	}
	~BombDecorator() { delete bomb; }

	void Move(uint16_t time) override;

	void Draw() const override;

	void SetPos(double nx, double ny) override;

	double GetY() const override;

	double GetX() const override;

	void SetWidth(uint16_t widthN) override;

	uint16_t GetWidth() const override;
};

