
#include "stdafx.h"
#include "Initiator.h"
#include "Machine.h"

using namespace std;
int main()
{
	double elapsed_secs=0;
	double result = 0;
	Machine machine;

	string fileName;
	cout << "Podaj nazwe pliku tekstowego: ";
	cin >> fileName;

	Initiator compliteMachine(fileName, machine);

	machine.bruteforce(0, machine.size);
	cout <<"Koniec liczenia"<< endl;
	system("pause");
	return 0;
}

