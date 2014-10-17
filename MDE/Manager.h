#pragma once
#include "CameraStruct.h"
#include "BattleHandler.h"

class Manager
{
public:
	Manager();
	void setPointers(CameraStruct* data);
	virtual int move(int direction);
	virtual ~Manager();
protected:
	CameraStruct* dataForManaging;
};

