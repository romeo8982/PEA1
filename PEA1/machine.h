#include "stdafx.h"
#include "Task.h"
#include <limits>
#include <list>
#include <stdlib.h>
#include <time.h>
#include "Result.h"
#include <random>
#include <algorithm>  
#include <ctime>
#pragma once
class Machine
{
	std::knuth_b rand_engine;
	int deltaL;
	double temperature;
	double decrease;
	bool probability(int optResult,int result,double temperature);
	int counter;
public:
	int result;
	
	int size;
	Task *task;
	std::vector<Task> taskList;
	std::vector<Task> optTaskList;
	Machine();
	void setSize(int size);
	void addTask(Task task,int id);
	void printTasks();
	int countResult(Task tasks[]);
	void showResultVector();
	int countResultVector(std::vector<Task> taskList);
	void showResult();
	void bruteforce(int start, int size);
	void swap(int first, int second);
	void simulatedAnnealingRand();
	int simulatedAnnealing(int start, int size);
	void nextPermutation(std::vector<Task> taskList);
	~Machine();
};