//Luis A. Ruiz
//Project - Class Temp
#include <iostream>
#include <string>

using namespace std;


template<class MarkNut>
class BobRoss
{
private:
	MarkNut* GenArr;
	int Limit;

public:

	BobRoss(int size)
	{
		Limit = size;
		GenArr = new MarkNut[size];
	}

	int getlimit()
	{
		return Limit;
	}

	void findMinandMax()
	{
		MarkNut numMax = GenArr[0];
		MarkNut numMin = GenArr[0];

		for (int x = 0; x < Limit; x++)
		{
			if (GenArr[x] > numMax)
			{
				numMax = GenArr[x];
			}
			else if (GenArr[x] < numMin)
			{
				numMin = GenArr[x];
			}
		}
		cout << "Max:" << numMax << endl;
		cout << "Min:" << numMin << endl;
	}

	MarkNut& operator[] (int Index)
	{
		if (Index < 0 || Index >= Limit)
		{
			throw string("*Out of Range*");
		}
		return GenArr[Index];
	}

};

int main()
{
	int size = 20;
	int csize = 25;
	BobRoss<int> Dataset(size);
	BobRoss<char> Datacet(csize);
	BobRoss<double> Datadet(size);

	for (int x = 0; x < size; x++)
	{
		Dataset[x] = x;
		cout << Dataset[x] << ",";
	}
	try
	{
		cout << Dataset[20] << endl;
	}
	catch (string s)
	{
		cout << s << endl;
	}

	Dataset.findMinandMax();

	cout << "\n";
	int a = 65;
	for (int i = 0; i < csize; i++)
	{
		Datacet[i] = a;
		a = a + 1;
		cout << Datacet[i] << ",";
	}
	try
	{
		cout << Datacet[91] << endl;
	}
	catch (string s)
	{
		cout << s << endl;
	}

	Datacet.findMinandMax();

	cout << "\n";
	for (double x = 0; x < size; x++)
	{
		Datadet[x] = x + .5;
		cout << Datadet[x] << ",";
	}
	try
	{
		cout << Datadet[20] << endl;
	}
	catch (string s)
	{
		cout << s << endl;
	}

	Datadet.findMinandMax();

	system("pause");
	return 0;
}
