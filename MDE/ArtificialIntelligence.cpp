#include "ArtificialIntelligence.h"

ArtificialIntelligence::ArtificialIntelligence(){
}


/** \brief Returns a calculated direction for the enemy to take
 *
 * \param playerLoc The array of the player location
 * \param coord The array of the enemy's location
 * \param liveEntities EntityData struct for the current dungeon level to ensure 2 entities don't overlap
 * \param mapLayer MapData struct of the current dungeon so that NPCs can see the map
 * \return returns the direction code as defined on the num pad, 0 for attack, -1 for do nothing
 *
 */     
int ArtificialIntelligence::direction(LocationCoordinates  playerLoc, LocationCoordinates coord, EntityData liveEntities, MapData mapLayer, CameraStruct* dataForManaging){
	if (abs(playerLoc.x - coord.x) + abs(playerLoc.y - coord.y) <= 7){//controls player visibility

		int choice = rand.generate(1, 2);
		if (playerLoc.x < coord.x&&playerLoc.y < coord.y){ //move diagonally towards palyer up and left

			if (liveEntities.live[coord.x - 1][coord.y] == 0 &&
				mapLayer.mapDim[coord.x - 1][coord.y] != '#' &&
				choice == 1 &&
				(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x - 1, coord.y) <= 0 ||
				IsBuildingHere(coord.x - 1, coord.y, dataForManaging)==false)){
				//move left
				return 4;
			}
			else if (liveEntities.live[coord.x][coord.y - 1] == 0 &&
				mapLayer.mapDim[coord.x][coord.y - 1] != '#' &&
				(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x, coord.y - 1) <= 0 || 
				IsBuildingHere(coord.x, coord.y - 1, dataForManaging) == false)){
				//move up
				return 8;
			}
			else{
				return -1;
			}
		}
		else if (playerLoc.x > coord.x&&playerLoc.y > coord.y){//move diagonally towards palyer down and right

			if (liveEntities.live[coord.x][coord.y + 1] == 0 &&
				mapLayer.mapDim[coord.x][coord.y + 1] != '#' &&
				choice == 1 &&
				(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x, coord.y + 1) <= 0 ||
				IsBuildingHere(coord.x, coord.y + 1, dataForManaging) == false)){
				//move down
				return 2;
			}
			else if (liveEntities.live[coord.x + 1][coord.y] == 0 &&
				mapLayer.mapDim[coord.x + 1][coord.y] != '#' &&
				(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x + 1, coord.y) <= 0 ||
				IsBuildingHere(coord.x + 1, coord.y, dataForManaging) == false)){
				//move right
				return 6;
			}
			else{
				return -1;
			}
		}
		else if (playerLoc.x > coord.x&&playerLoc.y < coord.y){//move diagonally towards palyer up and right
			if (liveEntities.live[coord.x][coord.y - 1] == 0 &&
				mapLayer.mapDim[coord.x][coord.y - 1] != '#' &&
				choice == 1 &&
				(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x, coord.y - 1) <= 0 ||
				IsBuildingHere(coord.x, coord.y - 1, dataForManaging) == false)){
				//move up
				return 8;
			}
			else if (liveEntities.live[coord.x + 1][coord.y] == 0 &&
				mapLayer.mapDim[coord.x + 1][coord.y] != '#' &&
				(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x + 1, coord.y) <= 0 ||
				IsBuildingHere(coord.x + 1, coord.y, dataForManaging) == false)){
				//move right
				return 6;
			}
			else{
				return -1;
			}
		}
		else if (playerLoc.x<coord.x&&playerLoc.y>coord.y){//move diagonally towards palyer down and left
			if (liveEntities.live[coord.x][coord.y + 1] == 0 &&
				mapLayer.mapDim[coord.x][coord.y + 1] != '#' &&
				(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x, coord.y + 1) <= 0 ||
				IsBuildingHere(coord.x, coord.y + 1, dataForManaging) == false)){
				//move down
				return 2;
			}
			else if (liveEntities.live[coord.x - 1][coord.y] == 0 &&
				mapLayer.mapDim[coord.x - 1][coord.y] != '#' &&
				(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x - 1, coord.y) <= 0 ||
				IsBuildingHere(coord.x - 1, coord.y, dataForManaging) == false)){
				//move left
				return 4;
			}
			else{
				return -1;
			}
		}
		else if (playerLoc.x == coord.x&&playerLoc.y < coord.y){//move up
			if (liveEntities.live[coord.x][coord.y - 1] == 1){
				//combat
				return 0;
			}
			if (EnemyAttacksBuildingCheck(coord.x, coord.y - 1, dataForManaging) == true){
				//Building combat
					return 10;
				}
			
				else if (liveEntities.live[coord.x][coord.y - 1] > 1 || mapLayer.mapDim[coord.x][coord.y - 1] == '#'){//up
					if (liveEntities.live[coord.x - 1][coord.y] == 0 &&
						mapLayer.mapDim[coord.x - 1][coord.y] != '#'  &&
						choice == 1 &&
						(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x - 1, coord.y) <= 0 ||
						IsBuildingHere(coord.x - 1, coord.y, dataForManaging) == false)){
						//move left
						return 4;
					}
					else if (liveEntities.live[coord.x + 1][coord.y] == 0 &&
						mapLayer.mapDim[coord.x + 1][coord.y] != '#' &&
						(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x + 1, coord.y) <= 0 ||
						IsBuildingHere(coord.x + 1, coord.y, dataForManaging) == false)){
						//move right
						return 6;
					}
					else{
						return -1;
					}
				}
				else if (liveEntities.live[coord.x][coord.y - 1] == 0 &&
					mapLayer.mapDim[coord.x][coord.y - 1] != '#' &&
					(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x, coord.y - 1) <= 0 ||
					IsBuildingHere(coord.x, coord.y - 1, dataForManaging) == false)){
					return 8;
				}
				else{
					return -1;
				}
			}
			else if (playerLoc.x == coord.x&&playerLoc.y > coord.y){//move down
				if (liveEntities.live[coord.x][coord.y + 1] == 1){
					//Combat
					return 0;
				}
				//if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x][coord.y + 1] > 0){
				if (EnemyAttacksBuildingCheck(coord.x, coord.y + 1, dataForManaging) == true){
					
					//Building combat
					return 11;
				}
				else if (liveEntities.live[coord.x][coord.y + 1] > 1 || mapLayer.mapDim[coord.x][coord.y + 1] == '#'){//down
					if (liveEntities.live[coord.x - 1][coord.y] == 0 &&
						mapLayer.mapDim[coord.x - 1][coord.y] != '#'  &&
						choice == 1 &&
						(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x - 1, coord.y) <= 0 ||
						IsBuildingHere(coord.x - 1, coord.y, dataForManaging) == false)){
						//move left
						return 4;
					}
					else if (liveEntities.live[coord.x + 1][coord.y] == 0 &&
						mapLayer.mapDim[coord.x + 1][coord.y] != '#' &&
						(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x + 1, coord.y) <= 0 ||
						IsBuildingHere(coord.x + 1, coord.y, dataForManaging) == false)){
						//move right
						return 6;
					}
					else{
						return -1;
					}
				}
				else if (liveEntities.live[coord.x][coord.y + 1] == 0 &&
					mapLayer.mapDim[coord.x][coord.y + 1] != '#' &&
					(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x, coord.y + 1) <= 0 ||
					IsBuildingHere(coord.x, coord.y + 1, dataForManaging) == false)){
					return 2;
				}
				else{
					return -1;
				}
			}
			else if (playerLoc.x < coord.x&&playerLoc.y == coord.y){//move left
				if (liveEntities.live[coord.x - 1][coord.y] == 1){
					//Combat
					return 0;
				}
				//if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x - 1][coord.y] > 0){
				if (EnemyAttacksBuildingCheck(coord.x - 1, coord.y, dataForManaging) == true){
					
					//Building combat
					return 12;
				}
				else if (liveEntities.live[coord.x - 1][coord.y] > 1 || mapLayer.mapDim[coord.x - 1][coord.y] == '#'){//left
					if (liveEntities.live[coord.x][coord.y - 1] == 0 &&
						mapLayer.mapDim[coord.x][coord.y - 1] != '#'  &&
						choice == 1 &&
						(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x, coord.y - 1) <= 0 ||
						IsBuildingHere(coord.x, coord.y - 1, dataForManaging) == false)){
						//move up
						return 8;
					}
					else if (liveEntities.live[coord.x][coord.y + 1] == 0 &&
						mapLayer.mapDim[coord.x][coord.y + 1] != '#' &&
						(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x, coord.y + 1) <= 0 ||
						IsBuildingHere(coord.x, coord.y + 1, dataForManaging) == false)){
						//move down
						return 2;
					}
					else{
						return -1;
					}
				}
				else if (liveEntities.live[coord.x - 1][coord.y] == 0 &&
					mapLayer.mapDim[coord.x - 1][coord.y] != '#' &&
					(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x - 1, coord.y) <= 0 ||
					IsBuildingHere(coord.x - 1, coord.y, dataForManaging) == false)){
					return 4;
				}
				else{
					return -1;
				}
			}
			else if (playerLoc.x > coord.x&&playerLoc.y == coord.y){//move right
				if (liveEntities.live[coord.x + 1][coord.y] == 1){
					//combat
					return 0;
				}
				//if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x + 1][coord.y] > 0 ){
				if (EnemyAttacksBuildingCheck(coord.x + 1, coord.y, dataForManaging) == true){
					//Building combat
					return 13;
				}
				else if (liveEntities.live[coord.x + 1][coord.y] > 1 || mapLayer.mapDim[coord.x + 1][coord.y] == '#'){//right
					if (liveEntities.live[coord.x][coord.y + 1] == 0 &&
						mapLayer.mapDim[coord.x][coord.y + 1] != '#' &&
						choice == 1 &&
						(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x, coord.y + 1) <= 0 ||
						IsBuildingHere(coord.x, coord.y + 1, dataForManaging) == false)){
						//move down
						return 2;
					}
					else if (liveEntities.live[coord.x][coord.y - 1] == 0 &&
						mapLayer.mapDim[coord.x][coord.y - 1] != '#' &&
						(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x, coord.y - 1) <= 0 ||
						IsBuildingHere(coord.x, coord.y - 1, dataForManaging) == false)){
						//move up
						return 8;
					}
					else{
						return -1;
					}
				}
				else if (liveEntities.live[coord.x + 1][coord.y] == 0 &&
					mapLayer.mapDim[coord.x + 1][coord.y] != '#' &&
					(GetBuildingType(dataForManaging, dataForManaging->currentLevel, coord.x + 1, coord.y) <= 0 ||
					IsBuildingHere(coord.x +1, coord.y, dataForManaging) == false)){
					return 6;
				}
				else{
					return -1;
				}
			}
			else{
				return -1;
			}
		}
		else{
			return -1;
		}
	}



	/** \brief gets the type of building front of the enemy
	*
	* \param dataForManaging. The CameraStruct.
	* \param currentdepth. The current level
	* \param xCoord. The X coordinate where the building is on the map.
	* \param yCoord. The Y coordinate where the building is on the map.
	* \return 0 if it is a trap. 1 if it is a tower. 2 if it is a barricade.
	*
	*/
	int ArtificialIntelligence::GetBuildingType(CameraStruct* dataForManaging, int currentdepth, int xCoord, int yCoord){

		int buildingID = 0;
		Building* building = new Building();
		if (dataForManaging->mapStruct[currentdepth].entityDataBuildings.live[xCoord][yCoord]>0){
			buildingID = dataForManaging->mapStruct[currentdepth].entityDataBuildings.live[xCoord][yCoord];
			building = dataForManaging->mapStruct[currentdepth].entityDataBuildings.building.at(buildingID - 1);
			if (building->getType() == 0){
				return 0;
			}
			else if (building->getType() == 1){
				return 1;
			}
			else if (building->getType() == 2){
				return 2;
			}
			else{
				return 99;
			}
		}
		else{
			return 99;
		}
	}
	/** \brief checks if building is at the given coordinates
	*
	* \param dataForManaging. The CameraStruct.
	* \param xCoord. The X coordinate where the building is on the map.
	* \param yCoord. The Y coordinate where the building is on the map.
	* \return true if building is here. Returns false if building isn't here.
	*
	*/
	bool ArtificialIntelligence::IsBuildingHere(int coordX, int coordY, CameraStruct* dataForManaging){
		if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coordX][coordY] > 0){
			return true;
		}
		else{
			return false;
		}
	}


	/** \brief checks if enemy can attack the building next to it.
	*
	* \param xCoord. The X coordinate where the building is on the map.
	* \param yCoord. The Y coordinate where the building is on the map.
	* \param dataForManaging. The CameraStruct.
	* \return true if enemy can attack the building. Returns false if enemy can't attack the building.
	*
	*/
	bool ArtificialIntelligence::EnemyAttacksBuildingCheck(int coordX, int coordY, CameraStruct* dataForManaging){
		bool buildingIsHere=false;
		bool buildingTypeIsAcceptable = false;

		if (IsBuildingHere(coordX, coordY,dataForManaging )==true){
			buildingIsHere = true;
		}
		if (GetBuildingType(dataForManaging, dataForManaging->currentLevel, coordX,coordY)>0){
			buildingTypeIsAcceptable = true;
		}
		//Jos x ja y kohdassa on rakennus ja rakennus on hyväksytty(este,torni ei ansa), niin palautetaan true
		if (buildingIsHere == true && buildingTypeIsAcceptable == true){
			return true;
		}
		else{
			return false;
		}

	}
	ArtificialIntelligence::~ArtificialIntelligence(){

	}
