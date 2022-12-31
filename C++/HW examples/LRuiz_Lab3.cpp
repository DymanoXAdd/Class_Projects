#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

void insertionSort(int[], const int);
void selectionSort(int[], const int);
void swap(int*, int*);

int main(void)
{
	const int SIZE = 20;
	int Array1[SIZE] = {0};
	srand(static_cast<unsigned>(time(NULL)));

	cout << setw(35) << "|Insertion Unsorted|" << endl;
	for (int x = 0; x < 20; x++)
	{
		Array1[x] = rand() % 100;
		cout << Array1[x] << "|";
	}
	cout << "\n";
	insertionSort(Array1, SIZE);
	cout << setw(34) << "|Insertion sorted|" << endl;
	for (int x = 0; x < 20; x++)
	{
		cout << Array1[x] << "|";
	}
	cout << "\n";
	cout << setw(35) << "|Selection Unsorted|" << endl;
	for (int x = 0; x < 20; x++)
	{
		Array1[x] = rand() % 100;
		cout << Array1[x] << "|";
	}
	cout << "\n";
	selectionSort(Array1, SIZE);
	cout << setw(34) << "|Selection sorted|" << endl;
	for (int x = 0; x < 20; x++)
	{
		cout << Array1[x] << "|";
	}

	system("pause");
	return 0;
}

void insertionSort(int arr[], const int SIZE)
{
	static int key, j, i = 1;

	if (i < SIZE)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		i++;
		insertionSort(arr, SIZE);
	}
}

void selectionSort(int arr[], const int SIZE)
{
	int min_index;
	static int j, i = 0;
	
	if(i < SIZE)
	{
		min_index = i;
		for (j = i + 1; j < SIZE; j++)
		{
			if (arr[j] < arr[min_index])
				min_index = j;
		}

		swap(&arr[min_index], &arr[i]);
		i++;
		selectionSort(arr, SIZE);
	}
}

void swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}