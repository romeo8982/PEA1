#include "stdafx.h"
#include "Task.h"
#include <limits>
#include <list>
#include <stdlib.h>
#include <time.h>
#include "Result.h"
#include <random>
#include <algorithm>  
#pragma once
class Machine
{
	std::knuth_b rand_engine;
	int deltaL;
	double temperature;
	bool probability(int optResult,int result,double temperature);
	int counter;
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
	int simulatedAnnealing(int start, int size);
	void nextPermutation(std::list<Task> taskList);
	~Machine();
};