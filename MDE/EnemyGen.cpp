#include"EnemyGen.h"
//TODO jaa vihollisgeneroimiset omiin funktioihin

EnemyGen::EnemyGen(CameraStruct* cam, Texture* texture){  //generates 'enemies'amount of enemies and puts them into deque, after witch it is returned
	int id=0;
	bool firstEnemy=true;
	int enemies = MAX_ENEMIES;
	int boses = MAX_BOSSENEMIES;
	int currentLevel = cam->currentLevel + 1;
	vector<string> characters = getEnemyListForGeneration(currentLevel);

	//RNG random;
	enemies = enemies + 2;
	//deque<Enemy*> enemy;
	id=GenerateNormalEnemys(enemies, id, firstEnemy, currentLevel, texture);
	GenerateBosses(boses, id, currentLevel, texture);
	
	cam->mapStruct[cam->currentLevel].entityData.enemy = enemy;
}
/** \brief Generates normal enemies
*
* \param numberOfEnemies The amount enemies to be generated.
* \param id It is first available id which can be used when generating enemies.
* \param firstEnemy if generated enemy is first to be created
* \param currentLevel Current level
* \param texture used to set enemys texture
*/
int EnemyGen::GenerateNormalEnemys(int numberOfEnemies, int id, bool firstEnemy, int currentLevel, Texture* texture){
	//Generates normal enemys
	int i;
	for (i = id; i<numberOfEnemies; i++){
		if (i == 0 || i == 1){
			Enemy* npc = EnemyFactory::create_enemy("goblin", firstEnemy);
			npc->set_Id(0);
			enemy.emplace(enemy.begin() + i, npc);
			enemy[i]->setCoords(-10, -10);
			//delete npc;
			firstEnemy = false;
		}
		else{
			Enemy* npc = EnemyFactory::create_enemy("goblin", firstEnemy);
			npc->set_Id(i);
			npc->set_level(currentLevel);
			npc->setTexture(texture);
			enemy.emplace(enemy.begin() + i, npc);
			//delete npc;
		}
	}
	cout << "Peli generoi "<< i-2 << " verran normi vihollisia"<< endl;
	return i;
}

/** \brief Generates boss enemies
*
* \param numberOfBosses The amount enemies to be generated.
* \param startingID It is first available id which can be used when generating bosses.
* \param currentLevel Current level
* \param texture used to set enemys texture
*/
void EnemyGen::GenerateBosses(int numberOfBosses, int startingID, int currentLevel, Texture* texture){
	int i = startingID;
	int j;
	//Generates bosess
	for (j = 0; j < numberOfBosses; j++){
		Enemy* npc = EnemyFactory::create_enemy("goblingking", false);
		npc->set_Id(i);
		npc->set_level(currentLevel);
		npc->setTexture(texture);
		enemy.emplace(enemy.begin() + i, npc);
		//delete npc;
		i++;
	}
	cout << "Peli generoi " << numberOfBosses << " verran pomo vihollisia" << endl;
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
