#ifndef RNG_H
#define RNG_H

#include <chrono>
#include <cstdlib>
#include "GlobalDef.h"
using namespace std;

class RNG{
	bool first_run=true;
public:
	RNG();
	int generate(int start,int amount);
	~RNG();
};
#endif
