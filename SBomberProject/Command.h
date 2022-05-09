#pragma once

#include "Plane.h"
#include<vector>

class AbctractCommand
{
public:
	virtual void Execute() = 0;
	virtual ~AbctractCommand(){}
};

class ComDeleteDynamic : public AbctractCommand
{
private:
	DynamicObject* pObj;
	std::vector<DynamicObject*>& vecDynamicObj;
public:
	ComDeleteDynamic(DynamicObject* Obj, std::vector<DynamicObject*>& vec) : vecDynamicObj(vec), pObj(Obj)
	{

	}

	void Execute() override;
};

class ComDeleteStatic : public AbctractCommand
{
private:
	GameObject* pObj;
	std::vector<GameObject*>& vecStaticObj;
public:
	ComDeleteStatic(GameObject* Obj, std::vector<GameObject*>& vec) : vecStaticObj(vec), pObj(Obj)
	{

	}

	void Execute() override;
};

class ComDropBomb : public AbctractCommand
{
private:
	const Plane* plane;
	std::vector<DynamicObject*>& vecDynamicObj;
	uint16_t bombsNumber;
public:
	ComDropBomb(const Plane* p, std::vector<DynamicObject*>& vec, uint16_t bombs)
		: plane(p), vecDynamicObj(vec), bombsNumber(bombs)
	{

	}

	void Execute() override;
};
