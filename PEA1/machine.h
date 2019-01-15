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
	double mutationRate = 0.015;
	int turnamentSize = 5;
	bool theBest;
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
	std::vector<Task> FindTheBest(std::vector<std::vector<Task>> pop);
	void showResult();
	void bruteforce(int start, int size);
	void swap(int firstPosition, int secondPosition, Task * task);
	void simulatedAnnealingRand();
	std::vector<Task> generateNextPopulation();
	void savePopulation(int position, std::vector<Task> optTaskList, std::vector<std::vector<Task>> PopulationList);
	int simulatedAnnealing(int start, int size);
	void setup();
	std::vector<std::vector<Task>> GeneticAlgoritm(std::vector<std::vector<Task>> pop);
	std::vector<Task> TurnamentSelection(std::vector<std::vector<Task>> pop);
	void mutate(std::vector<Task> task);
	void swapVector(int firstPosition, int secondPosition, std::vector<Task> task);
	std::vector<Task> crossover(std::vector<Task> parent1, std::vector<Task> parent2);
	void ShowMustGoOn();
	~Machine();
};