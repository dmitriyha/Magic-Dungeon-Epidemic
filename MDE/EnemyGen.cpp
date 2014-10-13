#include"EnemyGen.h"


EnemyGen::EnemyGen(CameraStruct* cam){  //generates 'enemies'amount of enemies and puts them into deque, after witch it is returned
	int i;
	int y = 5;
	int enemies = MAX_ENEMIES;
	int currentLevel = cam->currentLevel + 1;
	vector<string> characters = getEnemyListForGeneration(currentLevel);

	//RNG random;
	enemies = enemies + 2;
	deque<Enemy*> enemy;
	for (i = 0; i<enemies; i++){
		if (i == 0 || i == 1){
			Enemy* npc = EnemyFactory::create_enemy("goblin");
			npc->set_stats(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			enemy.emplace(enemy.begin() + i, npc);
			enemy[i]->setCoords(-10, -10);
			//delete npc;
		}
		else{
			Enemy* npc = EnemyFactory::create_enemy("goblin");
			npc->set_stats(4 * currentLevel, 5 * currentLevel, 1, 1, 1, 1, 1, 1, 1, i);
			npc->set_level(currentLevel);
			enemy.emplace(enemy.begin() + i, npc);
			//delete npc;
		}

		y++;
	}
	cam->mapStruct[cam->currentLevel].entityData.enemy = enemy;
}

/** \brief This method is
 *
 * \param enemies The amount enemies to be generated.
 * \param depth the depth of the dungeon used to tweak the difficulty of the level
 * \return returns the deque that contains Enemy objects.
 *
 */     

vector<string> EnemyGen::getEnemyListForGeneration(int depth){
	vector<string> characters;
	if (depth == 1){
		characters.push_back( "goblin");
	}
	else if (depth == 2){
		characters.push_back("goblin");
		characters.push_back("orc");
	}
	else if (depth == 3){
		characters.push_back("werewolf");
		characters.push_back("orc");
		characters.push_back("werewolf boss");
	}
	return characters;
}

EnemyGen::~EnemyGen(){
}
