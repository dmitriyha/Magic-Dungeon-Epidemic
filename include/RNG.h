#ifndef RNG_H
#define RNG_H

#include <chrono>
#include <cstdlib>
#include "GlobalDef.h"
using namespace std;

/** \brief generates a pseudo random number
 *
 */     


class RNG{
	bool first_run=true;
public:
	RNG();
	int generate(int start,int amount);
	~RNG();
};
#endif
