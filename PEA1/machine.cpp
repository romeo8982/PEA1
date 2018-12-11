#include "stdafx.h"
#include "Machine.h"


void::Machine::setSize(int size)
{
	this->size = size;
	task = new Task[size];
	counter = 0;
	temperature = 1000.0;
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

void Machine::showResult()
{
	printTasks();
	std::cout << result <<std::endl;
	//Result _result(optTaskList, result);
	//std::cout << _result.result << _result.track;
}

void Machine::bruteforce(int start, int size)
{
	if (start == size)
	{
		if (result > countResult(task)) system("cls");
		if (result >= countResult(task))
		{
			result = countResult(task);
			showResult();
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

void Machine::simulatedAnnealing()
{
	/*int nextTaskID;
	temperature = std::numeric_limits<int>::max();
	int taskId = rand() % 10;
	optTaskList.push_back(task[taskId]);
	do
	{
		do
		{
			nextTaskID = rand() % 10;
		} while (nextTaskID != taskId);


	} while (true);*/

	simulatedAnnealing(0, size);
}
int Machine::simulatedAnnealing(int start, int size)
{   
	//std::cout << temperature<<std::endl;
	//std::cout << counter << std::endl;
	if (temperature > 0.0)
	{
		if (start == size)
		{
			//if (result > countResult(task)) system("cls");
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
				swap(start, i);

				if (counter >= 3.0)
				{
					counter = 0;
					temperature = temperature - 1;
					simulatedAnnealing(start + 1, size);
				}
				else
					simulatedAnnealing(start + 1, size);

				swap(start, i);
			}
		}
	}
	else
	{
		//std::cout << "koniec" << std::endl;
		return 0;
	}
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



//void Machine::nextPermutation(std::list<Task> taskList)
//{
//	std::next_permutation(taskList,taskList.size);
//	showResult();
//}

Machine::~Machine()
{
	delete[] task;
}
