#include "stdafx.h"
#include "Result.h"

Result::Result(std::list<Task> track, int result)
{
	_track = "";
	std::list<Task>::iterator it;
	for (it = track.begin(); it != track.end(); it++)
	{
		_track += std::to_string(it->id+1);
	}
	_result = result;
}

Result::~Result()
{
}
