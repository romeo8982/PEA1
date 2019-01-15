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
	int numberOfPopulation;
	std::vector<std::vector<Task>> populationList;
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
	std::vector<Task> generateNextPopulation();
	int simulatedAnnealing(int start, int size);
	void savePopulation(int position, std::vector<Task> optTaskList);
	std::vector<Task> FindTheBest();
	~Machine();
};