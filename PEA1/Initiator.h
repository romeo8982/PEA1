#include "stdafx.h"
#include <fstream>
#include "Machine.h"
#pragma once
class Initiator
{
	bool is_number(const std::string& s);
public:
	Initiator(std::string name, Machine &machine);
	~Initiator();
};

