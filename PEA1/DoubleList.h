#pragma once
#include <iostream>
#include "Task.h"
using namespace std;

class DoubleList
{
	struct Link
	{
		Link *next;
		Link *prev;
		Task *result;
		int key;
		Link(Task x[], int y) : result(x), key(y), next(NULL), prev(NULL)
		{}
	};
	Link *head = NULL;
	Link *tail = NULL;
public:
	int size = 0;
	void clear(int);
	void add(int,int,Task[]);
	void show();
	void test();
};