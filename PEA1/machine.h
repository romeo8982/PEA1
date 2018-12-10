#include "stdafx.h"
#include "Task.h"
#include <limits>
#include <list>
#include <stdlib.h>
#include <time.h>
#include "Result.h"
#pragma once
class Machine
{
public:
	int result;
	int temperature;
	int size;
	Task *task;
	std::list<Task> taskList;
	std::list<Task> optTaskList;
	Machine();
	void setSize(int size);
	void addTask(Task task,int id);
	void printTasks();
	int countResult(Task tasks[]);
	void showResult();
	void bruteforce(int start, int size);
	void swap(int first, int second);
	void simulatedAnnealing();
	double pmove(Task first, Task second, double temperature);
	~Machine();
};