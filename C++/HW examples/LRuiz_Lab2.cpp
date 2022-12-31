#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int Collatz(int);

int main(void)
{
	int Num;

	cout << "Enter a value:";
	cin >> Num;
	cout << "\n";
	Collatz(Num);

	system("pause");
	return 0;
}

int Collatz(int num)
{
	int temp;
	static unsigned int counter = 0;
	temp = num;

	if (num % 2 == 0)
	{
		num = num / 2;
		counter++;
	}
	else
	{
		num = (3 * num) + 1;
		counter++;
	}

	if (temp % 2 == 0)
	{
		cout << setw(6);
		cout << temp << " / 2 = " << num << endl;
	}
	else
	{
		cout << setw(2);
		cout << temp << " * 3 + 1 = " << num << endl;
	}

	if (num != 1)
		Collatz(num);
	else
	{
		cout << "\n";
		cout << "Value 1 reached in " << counter << " steps." << endl;
	}
	return num;
}