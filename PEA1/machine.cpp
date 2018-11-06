#include "stdafx.h"
#include "Machine.h"
#include <memory>
#include <limits>


void::Machine::setSize(int size)
{
	this->size = size;
	task = new Task[size];
	arrayOfResult = new int[size];
}

Machine::Machine()
{
	result = std::numeric_limits<int>::max();
}

void Machine::addTask(Task task, int position)
{
	if (position >= 0)
	{
		this->task[position].fillTask(task.id, task.executionTime, task.retioPunishment, task.deadLine);
	}
}

void Machine::printTasks()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << task[i];
	}
}

int Machine::countResult(Task tasks[])
{
	int result=0;
	int time=0;
	for (int i = 0; i < this->size; i++)
	{
		if (tasks[i].deadLine - tasks[i].executionTime - time >= 0)
		{
			result += 0;
		}
		else
		{
			result+=(tasks[i].deadLine - tasks[i].executionTime - time)*-1 * tasks[i].retioPunishment;
		}

		time += tasks[i].executionTime;
	}
	return result;
}

void Machine::bruteforce()
{
	List.show();
	std::cout << result<<std::endl;
}

void Machine::permute(int start, int size)
{
	if (start == size)
	{
		if (result >= countResult(task))
		{
			if (result > countResult(task)) {
				for (int i = List.size; i > 0; i--) { List.clear(result); }
			}
			result = countResult(task);
			List.add(List.size, result, task);
			bruteforce();
			//printTasks();
			//std::cout << result <<std::endl;
		}
	}
	else
	{
		for (int i = start; i < size; i++)
		{
			swap(start, i);
			permute(start + 1, size);
			swap(start, i);
		}
	}
}

void Machine::swap(int firstPosition, int secondPosition)
{
	Task helper;
	helper.fillTask(task[firstPosition].id,task[firstPosition].executionTime, task[firstPosition].retioPunishment, task[firstPosition].deadLine);
	task[firstPosition].fillTask(task[secondPosition].id, task[secondPosition].executionTime, task[secondPosition].retioPunishment, task[secondPosition].deadLine);
	task[secondPosition].fillTask(helper.id, helper.executionTime, helper.retioPunishment, helper.deadLine);
}

Machine::~Machine()
{
	delete[] task;
}
