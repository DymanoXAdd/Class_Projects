#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class student
{
	private:
		string fname;
		string lname;
		float GPA;

	public:

		student() {}

		void setfname(string name)
		{
			fname = name;
		}

		string getfname()
		{
			return fname;
		}

		void setlname(string name)
		{
			lname = name;
		}

		string getlname()
		{
			return lname;
		}

		void setGPA(float Num)
		{
			GPA = Num;
		}

		float getGPA()
		{
			return GPA;
		}

};

void quickSort(student arr[], int, int);
int partition(student arr[], int, int);
void swap(student *arr, student *ar);
void mergeSort(student arr[], float, float);
void merge(student arr[], int , int, int);

int main(void)
{
	int total_Grades;
	int gradeCounter;
	float grade;
	int choice;
	string name;
	ifstream myfile;
	myfile.open("student.txt");
	
	if (!myfile)
	{
		cout << "Did not read File!" << endl;
	}
	
	myfile >> total_Grades;

	student *Student_Name = new student[total_Grades];

	gradeCounter = 0;
	
	cout << "|Unsorted File|" << endl;
	while (!myfile.eof())
	{
		//First Name Input
		myfile >> name;
		Student_Name[gradeCounter].setfname(name);
		cout << Student_Name[gradeCounter].getfname() << " ";
		//Last Name Input
		myfile >> name;
		Student_Name[gradeCounter].setlname(name);
		cout << Student_Name[gradeCounter].getlname() << " ";
		//Grade Input
		myfile >> grade;
		Student_Name[gradeCounter].setGPA(grade);
		cout << Student_Name[gradeCounter].getGPA() << endl;

		gradeCounter++;
	}
	myfile.close();

	cout << "\n";
	cout << "|-------------|" << endl;
	cout << "|1. Quick Sort|" << endl;
	cout << "|2. Merge Sort|" << endl;
	cout << "|-------------|" << endl;
	cout << ">>";
	cin >> choice;

	// Quick Sort
	if (choice == 1)
	{
		quickSort(Student_Name, 0, 19);
		cout << "\n";
		cout << "|Quick Sort - Sorted|" << endl;
		for (int x = 0; x < total_Grades; x++)
		{
			cout << Student_Name[x].getfname() << " ";
			cout << Student_Name[x].getlname() << " ";
			cout << Student_Name[x].getGPA() << endl;
		}
	}
	//Merge Sort
	else if (choice == 2)
	{
		mergeSort(Student_Name, 0, 19);
		cout << "\n";
		cout << "|Merge Sort - Sorted|" << endl;
		for (int x = 0; x < total_Grades; x++)
		{
			cout << Student_Name[x].getfname() << " ";
			cout << Student_Name[x].getlname() << " ";
			cout << Student_Name[x].getGPA() << endl;
		}
	}
	system("pause");
	return 0;
}

void quickSort(student arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[pi] is now
		   at right place */
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);  // Before pi
		quickSort(arr, pi + 1, high); // After pi
	}
}

int partition(student arr[], int low, int high)
{
	// pivot (Element to be placed at right position)
	float pivot = arr[high].getGPA();

	int i = (low - 1);  // Index of smaller element

		for (int j = low; j <= high - 1; j++)
		{
			// If current element is smaller than the pivot
			if (arr[j].getGPA() < pivot)
			{
				i++;    // increment index of smaller element
				swap(&arr[i], &arr[j]);
			}
		}
		swap(&arr[i + 1], &arr[high]);
		return (i + 1);
}

void swap(student *a, student *b)
{
	student t = *a;
	*a = *b;
	*b = t;
}

void mergeSort(student arr[], float left, float right)
{
	if (left < right)
	{
		float mid = (left + right) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

void merge(student arr[], int left, int mid, int right)
{
	int i, j, k;
	int s1 = mid - left + 1;
	int s2 = right - mid;

	float* leftarr = new float[s1];
	float* rightarr = new float[s2];

	for (i = 0; i < s1; i++)
	{
		leftarr[i] = arr[left + i].getGPA();
	}

	for (j = 0; j < s2; j++)
	{
		rightarr[j] = arr[mid + 1 + j].getGPA();
	}

	i = 0;
	j = 0;
	k = left;

	while (i < s1 && j < s2)
	{
		if (leftarr[i] <= rightarr[j])
		{
			arr[k].setGPA(leftarr[i]);
			i++;
		}
		else
		{
			arr[k].setGPA(rightarr[j]);
			j++;
		}
		k++;
	}

	while (i < s1)
	{
		arr[k].setGPA(leftarr[i]);
		i++;
		k++;
	}

	while (j < s2)
	{
		arr[k].setGPA(rightarr[j]);
		j++;
		k++;
	}
}