#include "stdafx.h"
#include "task.h"



Task::Task()
{
	bool empty = true;
}

void::Task::fillTask(int id,int executionTime, int retioPunishment, int deadLine)
{
	
	if ((id>=0)&&(executionTime >= 0) && (retioPunishment > 0) && (deadLine >= 0))
	{
		this->executionTime = executionTime;
		this->retioPunishment = retioPunishment;
		this->deadLine = deadLine;
		this->id = id;
	}
	empty = false;
}


std::ostream & operator<<(std::ostream & display, const Task & task)
{
	display << task.id+1 << " " << task.executionTime << " " << task.retioPunishment << " " << task.deadLine<<std::endl;
	return display;
}

bool operator==(const Task & t1, const Task & t2)
{
	bool equal=false;
	if (t1.id == t2.id) equal = true;
	return equal;
}
