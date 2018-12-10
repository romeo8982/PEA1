#include "stdafx.h"
#include "Task.h"
#include <limits>
#pragma once
class Machine
{
public:
	int result;
	int size;
	Task *task;
	Machine();
	void setSize(int size);
	void addTask(Task task,int id);
	void printTasks();
	int countResult(Task tasks[]);
	void showResult();
	void bruteforce(int start, int size);
	void swap(int first, int second);
	~Machine();
};