// Luis A. Ruiz ID:20469411
// Date: 9/8/2020
// Project_1
#include <iostream>
#include <string>
using namespace std;

int tester_vaild(string x, string z);

template <typename Object>
class sorter
{
	public:
		explicit sorter( const Object& initialvalue = Object{"54Asd4a5AE846FSf45547aAa53df"})
			: storedvalue{ initialvalue } { }

		void print()
		{
				for (size_t i = 0; i < n; i++)
				{
					cout << storedvalue[i];
				}
				cout << endl;
		}

		int search(string x)
		{
			int total;
			int sum_total = 0;
			for (int i = 0; i < x.length(); i++)
			{
				total = 0;
				for (int y = 0; y < storedvalue.length(); y++)
					if (storedvalue[y] == x[i])
						total++;
				cout << x[i] << " = " << total << endl;
				sum_total = sum_total + total;
			}
			return sum_total;
		}

		void add(string x)
		{
			storedvalue = storedvalue + x;
			cout << storedvalue << endl;
		}

		int n;
		void remove(string x)
		{
			n = storedvalue.length();
			for (int i = 0; i < x.length(); i++)
			{
				for (int y = 0; y < storedvalue.length(); y++)
				{
					if (storedvalue[y] == x[i])
					{
						n = n - 1;
						for (int j = y; j < n; j++)
							storedvalue[j] = storedvalue[j + 1];
					}
				}
			}
		}

	private:
		Object storedvalue;
};

int main(void)
{
	sorter<string> s1;
	string value;
	string tester = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int testcounter;
	int valueleng;

	int x;
	do
	{
		cout << "|Project 1|" << endl;
		cout << "1. Search" << endl;
		cout << "2. Add" << endl;
		cout << "3. Remove" << endl;
		cout << "4. Print" << endl;
		cout << "5. Quit" << endl;
		cout << ">>";
		cin >> x;
		cin.clear();
		system("cls");

		switch (x)
		{
			case 1:
				cout << " Input a string consisting only numbers 0-9 and lower and upper case letters!" << endl;
				cout << ">>";
				cin >> value;
				cin.clear();
				testcounter = 0;
				valueleng = value.length();
				testcounter = tester_vaild(value, tester);
				if (valueleng == testcounter)
				{
					s1.search(value);
					break;
				}
				else
				{
					cout << "Invaild Input" << endl;
					break;
				}
			case 2:
				cout << " Input a string consisting only numbers 0-9 and lower and upper case letters!" << endl;
				cout << ">>";
				cin >> value;
				cin.clear();
				testcounter = 0;
				valueleng = value.length();
				testcounter = tester_vaild(value, tester);
				if (valueleng == testcounter)
				{
					s1.add(value);
					break;
				}
				else
				{
					cout << "Invaild Input" << endl;
					break;
				}
				break;
			case 3:
				cout << " Input a string consisting only numbers 0-9 and lower and upper case letters!" << endl;
				cout << ">>";
				cin >> value;
				cin.clear();
				testcounter = 0;
				valueleng = value.length();
				testcounter = tester_vaild(value, tester);
				if (valueleng == testcounter)
				{
					s1.remove(value);
					break;
				}
				else
				{
					cout << "Invaild Input" << endl;
					break;
				}
				break;
			case 4:
				s1.print();
				break;
			case 5:
				x = 5;
		}

	} while (x != 5);

	return 0;
}

int tester_vaild(string x, string z)
{
	int total = 0;
	for (int i = 0; i <= x.length(); i++)
	{
		for (int y = 0; y < z.length(); y++)
		{
			if (x[i] == z[y])
			{
				total++;
			}
		}
	}
	return total;
}