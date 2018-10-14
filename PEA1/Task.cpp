#include "stdafx.h"
#include "task.h"



Task::Task()
{
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
}

Task::~Task()
{
}

std::ostream & operator<<(std::ostream & display, const Task & task)
{
	display << task.id << " " << task.executionTime << " " << task.retioPunishment << " " << task.deadLine<<std::endl;
	return display;
}
