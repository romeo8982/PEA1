#include "stdafx.h"
#include <list>
#include "Task.h"
#pragma once
class Result
{
	std::string _track;
	int _result;
public:
	const int& result = _result;
	const std::string& track = _track;
	Result(std::list<Task> track, int result);
	~Result();
};

