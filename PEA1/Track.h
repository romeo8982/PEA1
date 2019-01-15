#pragma once
#include "machine.h"
class Track
{
public:
	Machine machine;
	std::vector<Task> taskList;
	double best;
	double result;
	Track();
	~Track();
};

