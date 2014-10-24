#pragma once
#include "CameraStruct.h"
#include "Texture.h"
class ItemRenderer
{
	Texture* itemIcons;
	Texture* itemsOnMap;
	CameraStruct* camData;
public:
	ItemRenderer();
	void renderItem(int* renderLoc);
	void setPointer(CameraStruct* _camData);
	void setIconTexture(Texture* _itemIcons);
	Texture* getItemTexture();
	~ItemRenderer();
};

