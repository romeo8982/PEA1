// PEA1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Initiator.h"
#include "Machine.h"

using namespace std;
int main()
{
	Machine machine;
	string fileName;
	cout << "Podaj nazwe pliku tekstowego: ";
	cin >> fileName;
	Initiator compliteMachine(fileName, machine);
	machine.permute(0,machine.size);
	machine.bruteforce();
	system("pause");
	return 0;
}

