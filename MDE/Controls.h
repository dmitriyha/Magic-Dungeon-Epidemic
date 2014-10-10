#ifndef CONTROLS_H
#define CONTROLS_H

#include <iostream>
#include <SDL.h>
#include "CameraStruct.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
using namespace std;

/** \brief Handles all of the games controls and is the game way to the logic of the game
 */     


class Controls{
	///show inventory or not
	bool inventory=false;
	///the inventory cursor location tracker
	int inventory_cursor=1;
	///first run flag
	bool first_run=true;
	///manages the player
	PlayerManager *managePlayer;
	///manages the enemies
	EnemyManager * manageEnemies;
	///the camera data to be handled in Camera
	CameraStruct* cameraData;
public:
	Controls();
	void buttons(SDL_Event event);
	CameraStruct* getData();
	~Controls();
private:
	void keyboard(SDL_Event event);
	void mouse(SDL_Event event);
};

#endif
