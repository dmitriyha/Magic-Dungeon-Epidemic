#include "ItemRenderer.h"


ItemRenderer::ItemRenderer()
{
}

void ItemRenderer::renderItem(int* renderLoc){
	int cursor = 0;
	while (camData->mapStruct[camData->currentLevel].itemData.itemDataMap[renderLoc[0]][renderLoc[1]].size()>cursor){
		camData->mapStruct[camData->currentLevel].itemData.itemDataMap[renderLoc[0]][renderLoc[1]].at(cursor).render();
		cursor++;
	}
}

void ItemRenderer::setPointer(CameraStruct* _camData){
	camData = _camData;
}

void ItemRenderer::setIconTexture(Texture* _itemIcons){
	itemIcons = _itemIcons;
}

ItemRenderer::~ItemRenderer()
{
}
