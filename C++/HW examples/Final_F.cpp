#include <iostream>

using namespace std;
double PChec(double);
double BChec(double);
double DChec(double);

class PopulationCal
{
	private:
		double Pnum;
		double Bnum;
		double Dnum;

	public:

		double setPopulation(double Num)
		{
			this->Pnum = Num;
			return Num;
		}

		double setBirths(double Num)
		{
			this->Bnum = Num;
			return Num;
		}

		double setDeaths(double Num)
		{
			this->Dnum = Num;
			return Num;
		}

		double getP()
		{
			return Pnum;
		}

		double getBirthRate()
		{
			return Bnum / Pnum;
		}

		double getDeathRate()
		{
			return Dnum / Pnum;
		}

		friend double PChec(double Num);
		friend double BChec(double Num);
		friend double DChec(double Num);
};

int main(void)
{
	PopulationCal Pcal;
	double num;

	cout << "Enter total Population:" << endl;
	cin >> num;
	num = PChec(num);
	Pcal.setPopulation(num);
	cout << "Enter annual number of Births:" << endl;
	cin >> num;
	num = BChec(num);
	Pcal.setBirths(num);
	cout << "Enter annual number of Deaths:" << endl;
	cin >> num;
	num = DChec(num);
	Pcal.setDeaths(num);

	cout << "Population Statistics\n" << endl;
	cout << "Population:" << Pcal.getP() << endl;
	cout << "Birth Rate:" << Pcal.getBirthRate() << endl;
	cout << "Death Rate:" << Pcal.getDeathRate() << endl;

	system("pause");
	return 0;
}

double PChec(double Num)
{
	if (Num < 0)
	{
		do
		{
			cout << "Invalid Input!" << endl;
			cin >> Num;
		} while (Num < 0);

		if (Num == 1)
		{
			Num = 2;
			return Num;
		}
		return Num;
	}
	else if (Num == 1)
	{
		Num = 2;
		return Num;
	}
	else
	{
		return Num;
	}
}

double BChec(double Num)
{
	if (Num < 0)
	{
		do
		{
			cout << "Invalid Input!" << endl;
			cin >> Num;
		} while (Num < 0);
	}
	return Num;
}

double DChec(double Num)
{
	if (Num < 0)
	{
		do
		{
			cout << "Invalid Input!" << endl;
			cin >> Num;
		} while (Num < 0);
	}
	return Num;
}