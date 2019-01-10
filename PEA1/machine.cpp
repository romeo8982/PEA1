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

void Machine::showResult()
{
	printTasks();
	std::cout << result <<std::endl;
}

void Machine::bruteforce(int start, int size)
{
	if (start == size)
	{
		//if (result > countResult(task)) system("cls");
		if (result >= countResult(task))
		{
			result = countResult(task);
			//showResult();
		}
	}
	else
	{
		for (int i = start; i < size; i++)
		{
			swap(start, i);
			bruteforce(start + 1, size);
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

void Machine::simulatedAnnealingRand()
{
	//std::cout << counter << std::endl;
	//std::cout << temperature << std::endl;
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
			//showResultVector();
		}
		else if (probability(result, helper, temperature))
		{
			result = helper;
			//showResultVector();
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
//std::cout << counter<<std::endl;
//std::cout << temperature << std::endl;
	
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
			swap(start, i);

			if (counter >= 3.0)
			{
				counter = 0;
				temperature = temperature - 0.0001;
				simulatedAnnealing(start + 1, size);
			}
			else
				simulatedAnnealing(start + 1, size);

			swap(start, i);
			}
			else
			{
				return 0;
			}
		}
	}
}

void Machine::nextPermutation(std::vector<Task> taskList)
{
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



Machine::~Machine()
{
	delete[] task;
}
