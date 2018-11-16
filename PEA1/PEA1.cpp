
#include "stdafx.h"
#include "Initiator.h"
#include <ctime>
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

	for (int i = 0; i < 10 ;i++ )
	{
		clock_t begin = clock();
		machine.bruteforce(0, machine.size);
		clock_t end = clock();
		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		result =result + elapsed_secs;
	}
	result = elapsed_secs / 10.0;
	cout <<result<< endl;
	system("pause");
	return 0;
}

