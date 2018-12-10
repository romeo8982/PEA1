#include "stdafx.h"
#include "Initiator.h"

bool Initiator::is_number(const std::string & s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

Initiator::Initiator(std::string name, Machine &machine)
{
	int i = 0;
	int idCounter = 0;
	std::fstream file;
	file.open(name.c_str());
	if (file.good() == true)
	{
		std::string word;
		while (file >> word)
		{			
			if (is_number(word))
			{
				if (i == 1)
				{
					machine.setSize(std::stoi(word));
				}
				else
				{
					int executionTime = std::stoi(word);
					file >> word;
					int retioPunishment = std::stoi(word);
					file >> word;
					int deadLine = std::stoi(word);
					Task task;
					task.fillTask(idCounter, executionTime, retioPunishment, deadLine);
					machine.addTask(task,idCounter);
					idCounter++;
				}
			}
			i++;
		}
	}
	file.close();
}

Initiator::~Initiator()
{
}
