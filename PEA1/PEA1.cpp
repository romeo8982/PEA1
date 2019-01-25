
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

	double elapsed_secs=0;
	for (int i = 0; i < 1; i++)
	{
		
	clock_t begin = clock();
	machine.setGA(5, 50, 0.015, 1000);
	machine.ShowMustGoOn();
	clock_t end = clock();
	elapsed_secs += double(end - begin) / CLOCKS_PER_SEC;
	}
	
	cout <<"Koniec liczenia "<<elapsed_secs<< endl;
	
	system("pause");
	return 0;
}

