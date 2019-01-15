#pragma once
#include "machine.h"
class Population
{
public:
	Machine *machine;
	Population(int populationSize);
	~Population();
};

