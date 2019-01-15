#pragma once
#include "stdafx.h"

class Task
{
	
public:
	bool empty = true;
	int executionTime;
	int retioPunishment;
	int deadLine;
	int id;
	Task();
	void fillTask(int id,int executionTime,int retioPunishment,int deadLine);
	friend std::ostream& operator<<(std::ostream& display, const Task& task);
	~Task();
};
