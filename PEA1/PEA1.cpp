
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

	//machine.showResult();
	//machine.bruteforce(0, machine.size);
	//machine.simulatedAnnealing(0, machine.size);
	//double elapsed_secs=0;
	//for (int i = 0; i < 10; i++)
	//{
		//
	//clock_t begin = clock();
	//machine.simulatedAnnealingRand();
	//clock_t end = clock();
	//elapsed_secs += double(end - begin) / CLOCKS_PER_SEC;
	//}
	//cout <<"Koniec liczenia "<<elapsed_secs<< endl;
	machine.ShowMustGoOn();
	system("pause");
	return 0;
}

