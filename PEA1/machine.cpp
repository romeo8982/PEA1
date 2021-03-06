#include "stdafx.h"
#include "Machine.h"


void::Machine::setSize(int size)
{
	this->size = size;
	task = new Task[size];
	counter = 0;
	temperature = 25.0;
	decrease = temperature / ((size*(size - 1)) / 2);
	std::srand(unsigned(std::time(0)));
}

Machine::Machine()
{
	result = std::numeric_limits<int>::max();
}

void Machine::setGA(int turnamentSize, int numbeOfPopulation, double mutationRate, int numberOfCycle)
{
	this->turnamentSize = turnamentSize;
	this->numberOfPopulation = numbeOfPopulation;
	this->mutationRate = mutationRate;
	this->numberOfCycle = numberOfCycle;
}

void Machine::addTask(Task task, int position)
{
	if (position >= 0)
	{
		this->task[position].fillTask(task.id, task.executionTime, task.retioPunishment, task.deadLine);
	}

	optTaskList.push_back(task);
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
		if (tasks[i].deadLine - tasks[i].executionTime - time < 0)
		{
			result += (tasks[i].deadLine - tasks[i].executionTime - time)*-1 * tasks[i].retioPunishment;
		}

		time += tasks[i].executionTime;
	}
	return result;
}

void Machine::showResultVector()
{
	for (std::vector<Task>::iterator it = optTaskList.begin(); it != optTaskList.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << result;
	std::cout << std::endl;
}

void Machine::showResult()
{
	printTasks();
	std::cout << result <<std::endl;
}

void Machine::bruteforce(int start, int size)
{
	if (start == size)
	{
		if (result >= countResult(task))
		{
			result = countResult(task);
		}
	}
	else
	{
		for (int i = start; i < size; i++)
		{
			swap(start, i,task);
			bruteforce(start + 1, size);
			swap(start, i,task);
		}
	}
}

void Machine::swap(int firstPosition, int secondPosition,Task *task)
{
	Task helper;
	helper.fillTask(task[firstPosition].id,task[firstPosition].executionTime, task[firstPosition].retioPunishment, task[firstPosition].deadLine);
	task[firstPosition].fillTask(task[secondPosition].id, task[secondPosition].executionTime, task[secondPosition].retioPunishment, task[secondPosition].deadLine);
	task[secondPosition].fillTask(helper.id, helper.executionTime, helper.retioPunishment, helper.deadLine);
}

void Machine::simulatedAnnealingRand()
{
	int helper;
	int counter = 0;

	do
	{
		std::random_shuffle(optTaskList.begin(),optTaskList.end());
		helper = countResultVector(optTaskList);
		if (result >= helper)
		{
			counter = 0;
			result = helper;
		}
		else if (probability(result, helper, temperature))
		{
			result = helper;
			counter++;

		}
		else
		{
			counter++;
		}
		if (counter >= 3.0)
		{
			temperature = temperature - 0.0001;
			counter = 0;
					
		}
	}while (temperature > 0.0);
	showResultVector();
}


int Machine::simulatedAnnealing(int start, int size)
{
	if (start == size)
	{
		if (result > countResult(task)) system("cls");
		if (result >= countResult(task))
		{
			counter = 0;
			result = countResult(task);
			showResult();
		}
		else if (probability(result, countResult(task), temperature))
		{
			result = countResult(task);
			showResult();
			counter++;
		}
		else
		{
			counter++;
		}
	}
	else
	{
		for (int i = start; i < size; i++)
		{
			if (temperature > 0.0)
			{
			swap(start, i,task);

			if (counter >= 3.0)
			{
				counter = 0;
				temperature = temperature - 0.0001;
				simulatedAnnealing(start + 1, size);
			}
			else
				simulatedAnnealing(start + 1, size);

			swap(start, i,task);
			}
			else
			{
				return 0;
			}
		}
	}
	return 0;//delete warrning
}

bool Machine::probability(int optResult, int result, double temperature)
{
	double P;
	deltaL = optResult - result;
	P = exp(deltaL / temperature);
	if (P > 1)
	{
		P = 1;
	}
	std::bernoulli_distribution random_bool_generator(P);
	
	return random_bool_generator(rand_engine);
}


std::vector<Task> Machine::generateNextPopulation()
{
	std::random_shuffle(optTaskList.begin(), optTaskList.end());
	return optTaskList;
}

void Machine::savePopulation(int position,std::vector<Task> optTaskListk,std::vector<std::vector<Task>> &Population)
{
	Population.insert(Population.begin()+position,optTaskListk);
}

int Machine::countResultVector(std::vector<Task> taskList)
{
	int result = 0;
	int time = 0;
	for (int i = 0; i < this->size; i++)
	{
		if (taskList[i].deadLine - taskList[i].executionTime - time < 0)
		{
			result += (taskList[i].deadLine - taskList[i].executionTime - time)*-1 * taskList[i].retioPunishment;
		}

		time += taskList[i].executionTime;
	}
	return result;
}

std::vector<Task> Machine::FindTheBest(std::vector<std::vector<Task>> pop)
{
	std::vector<Task> localTaskResult=pop[0];
	int localResult = std::numeric_limits<int>::max();
	int helper = std::numeric_limits<int>::max();
	for (int i = 0; i < pop.size(); i++)
	{
		helper = countResultVector(pop[i]);
		if (result>=helper)
		{
			localResult = helper;
			result = localResult;
			localTaskResult = pop[i];
		}
		else if (localResult>=helper)
		{ 
			localResult = helper;
			localTaskResult = pop[i];
		}
	}
	return localTaskResult;
}

void Machine::setup()
{
	std::vector<Task> helper;
	for (int i = 0; i < numberOfPopulation; i++)
	{
		helper = generateNextPopulation();
		savePopulation(i, helper,populationList);
	}
}

std::vector<std::vector<Task>> Machine::GeneticAlgoritm(std::vector<std::vector<Task>> pop)
{
	std::vector<std::vector<Task>> localPopulationList;
	savePopulation(0,FindTheBest(pop), localPopulationList);


	for (int i = 1; i < pop.size(); i++)
	{
		std::vector<Task> parent1 = TurnamentSelection(pop);
		std::vector<Task> parent2 = TurnamentSelection(pop);

		std::vector<Task> child = crossover(parent1, parent2);

		savePopulation(i, child, localPopulationList);
	}

	for (int i = 1; i < localPopulationList.size(); i++) {
		mutate(localPopulationList[i]);
	}
	return localPopulationList;
}


std::vector<Task> Machine::TurnamentSelection(std::vector<std::vector<Task>> pop)
{
	std::vector<std::vector<Task>> turnament;
	for (int i = 0; i < turnamentSize; i++) {
		int randomId = rand() % populationList.size();
		savePopulation(i, pop[randomId],turnament);
	}
	return FindTheBest(turnament);
}
void Machine::mutate(std::vector<Task> &task)
{
	std::bernoulli_distribution random_bool_generator(mutationRate);
	for (int firstPosition = 0; firstPosition < task.size(); firstPosition++) {
		if (random_bool_generator(rand_engine))
		{
			int secondPosition = rand() % task.size();
			swapVector(firstPosition, secondPosition, task);
		}
	}
}

bool Machine::contain(std::vector<Task> child, Task task)
{
	bool contain = false;
	contain = std::find(child.begin(), child.end(), task) != child.end();
	return contain;
}

void Machine::swapVector(int firstPosition, int secondPosition, std::vector<Task> &task)
{
	Task helper;
	helper.fillTask(task[firstPosition].id, task[firstPosition].executionTime, task[firstPosition].retioPunishment, task[firstPosition].deadLine);
	task[firstPosition].fillTask(task[secondPosition].id, task[secondPosition].executionTime, task[secondPosition].retioPunishment, task[secondPosition].deadLine);
	task[secondPosition].fillTask(helper.id, helper.executionTime, helper.retioPunishment, helper.deadLine);
}

std::vector<Task> Machine::crossover(std::vector<Task> parent1, std::vector<Task> parent2) {

	std::vector<Task> child;
	Task *helperTask = new Task[size];
	for (int i = 0; i < size; i++)
	{
		child.push_back(helperTask[i]);
	}
	
	int startPos = rand() % parent1.size();
	int endPos = rand() %  parent1.size();

	for (int i = 0; i < size; i++) {
		if ( i >= startPos && i <= endPos) {
			child[i] = parent1[i];
		}
	}
	for (int i = 0; i < size; i++) {
		if (!contain(child,parent2[i])) {
			for (int j = 0; j < size; j++) {
					if (child[j].empty) {
						child[j] = parent2[i];
						break;
					}
			}
		}
	}
	delete[] helperTask;
	return child;
}

void Machine::ShowMustGoOn()
{
	setup();
	for (int i = 0; i < numberOfCycle; i++) {
		populationList = GeneticAlgoritm(populationList);
	}
	optTaskList = FindTheBest(populationList);
	showResultVector();
}


Machine::~Machine()
{
	delete[] task;
}
