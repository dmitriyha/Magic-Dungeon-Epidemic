#include"EnemyGen.h"


EnemyGen::EnemyGen(){
}

deque<Enemy> EnemyGen::Generate(int enemies, int depth){  //generates 'enemies'amount of enemies and puts them into deque, after witch it is returned
	int i;
	int y=5;
	//RNG random;
	enemies=enemies+2;
	deque<Enemy> enemy;
	for(i=0;i<enemies;i++){
		if (i==0||i==1){
			Enemy npc;
			npc.set_stats(0,0,0,0,0,0,0,0,0,0);
			enemy.emplace(enemy.begin()+i,npc);
			enemy[i].setCoords(-10,-10);
		}
		else{
			Enemy npc;
			npc.set_stats(4*depth,5*depth,1,1,1,1,1,1,1,i);
			npc.set_level(depth);
			enemy.emplace(enemy.begin()+i,npc);
			
		}		
		
		y++;
	}
	return enemy;
}

EnemyGen::~EnemyGen(){
}
