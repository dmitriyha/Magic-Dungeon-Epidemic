#include "ItemRenderer.h"


ItemRenderer::ItemRenderer()
{
}

void ItemRenderer::renderItem(LocationCoordinates  renderLoc){
	int cursor = 0;
	for (int i = 0; i < GRID_WIDTH; i++){
		for (int j = 0; j < GRID_HEIGHT; j++){
			while (camData->mapStruct[camData->currentLevel].itemData.itemDataMap[i][j].size()>cursor){
				camData->mapStruct[camData->currentLevel].itemData.itemDataMap[i][j].at(cursor).render();
				cursor++;
			}
		}
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
