#include "stdafx.h"
#include "Task.h"
#include <limits>
#include <list>
#include <stdlib.h>
#include <time.h>
#include "Result.h"
#include <random>
#pragma once
class Machine
{
	std::knuth_b rand_engine;
	int deltaL;
	double temperature;
	bool probability(int optResult,int result,double temperature);
public:
	int result;
	
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
	void simulatedAnnealing(int start, int size, double temperature);
	double pmove(Task first, Task second, double temperature);
	~Machine();
};