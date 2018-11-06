#include "stdafx.h"
#include "Task.h"
#include "DoubleList.h"
#pragma once
class Machine
{
public:
	int *arrayOfResult;
	int result;
	int size;
	Task *task;
	DoubleList List;
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