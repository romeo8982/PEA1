#include "stdafx.h"
#include "Task.h"
#pragma once
class Machine
{
public:
	int *arrayOfResult;
	int result;
	int size;
	Task *task;
	Machine();
	void setSize(int size);
	void addTask(Task task,int id);
	void printTasks();
	int countResult(Task tasks[]);
	void bruteforce();
	void permute(int start, int size);
	void swap(int first, int second);
	~Machine();
};