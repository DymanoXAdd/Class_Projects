#include <iostream>

using namespace std;

class Menu_Orders
{
private:
	int count = 0;
	int counter = 0;

public:
	class OverflowException {};
	class UnderflowException {};

	struct Node
	{
		string Name;
		double Cost;
		Node* next;

		Node(string d, double c, Node *p = NULL)
		{
			Name = d;
			Cost = c;
			next = p;
		}

	};

	Node* listhead = NULL;
	Node* insertPoint;
	Node* newNode, * current;

	double GetOrder()
	{
		double T = 0;
		int choice;

		do
		{
			cout << "\n";
			cout << "|Menu|" << endl;
			cout << "1. Small Coffee ----- 3.99" << endl;
			cout << "2. Large Coffee ----- 5.99" << endl;
			cout << "3. Tea -------------- 3.99" << endl;
			cout << "4. Blueberry Scone -- 1.50" << endl;
			cout << "5. Quit" << endl;
			cout << ">>";
			cin.clear();
			cin >> choice;

			switch (choice)
			{
			case 1:
				cout << "Placing Small Coffee on Order...." << endl;
				cout << "\n";
				T = T + 3.99;
					break;
			case 2:
				cout << "Placing Large Coffee on Order...." << endl;
				cout << "\n";
				T = T + 5.99;
					break;
			case 3:
				cout << "Placing Tea on Order...." << endl;
				cout << "\n";
				T = T + 3.99;
					break;
			case 4:
				cout << "Placing Blueberry Scone on Order...." << endl;
				cout << "\n";
				T = T + 1.50;
					break;
			case 5:
				cout << "End of Order" << endl;
				cout << "\n";
				break;
			default:
				cout << "Invalid Input" << endl;
				cout << "\n";
			}
			
		} while (choice != 5);

		return T;
	}

	void GetNameValue(string n,double val)
	{
		newNode = new Node(n,val);

		if (listhead == NULL)
		{
			listhead = new Node(n, val, listhead);
			count++;
		}
		else {
			insertPoint = listhead;
			while (insertPoint->next != NULL)
				insertPoint = insertPoint->next;

			insertPoint->next = new Node(n,val);
			count++;
		}

	}

	void deleteNode()
	{
		Node* temp = listhead, *prev = NULL;


		try
		{
			if (isEmpty())
				throw UnderflowException();
			cout << "Order#" << ++counter << endl;
			cout << "Name:";
			cout << listhead->Name << endl;
			cout << "Total:";
			cout << listhead->Cost << endl;

			if (temp != NULL && temp->Name == listhead->Name && temp->Cost == listhead->Cost) 
			{
				listhead = temp->next;
				count--;
				delete temp;
				return;
			}

			while (temp != NULL && temp->Name != listhead->Name && temp->Cost != listhead->Cost) {
				prev = temp;
				temp = temp->next;
			}

			if (temp == NULL)
				return;

			prev->next = temp->next;
			count--;
			delete temp;
		}
		catch (UnderflowException ex)
		{
			cout << "No More Orders" << endl;
		}
	}


	bool isEmpty()
	{
		if (count <= 0)
			return true;
		else
			return false;
	}

};

int main(void)
{

	Menu_Orders* Order = new Menu_Orders;
	string name;
	double Cost = 0;
	int counter = 0;
	double Total = 0;
	int choice;

	do
	{
		cout << "|Main Menu|" << endl;
		cout << "1. Take an Order" << endl;
		cout << "2. Close an Order" << endl;
		cout << "3.Quit" << endl;
		cout << ">>";
		cin >> choice;
		cout << "\n";

		switch (choice)
		{
		case 1:
			cout << "*Placing Order*" << endl;
			cout << "Name Needed:";
			cin >> name;
			Cost = Order->GetOrder();
			Order->GetNameValue(name,Cost);
			cout << "\n";
			break;
		case 2:
			cout << "*Closing Order*" << endl;
			Order->deleteNode();
			cout << "\n";
			break;
		case 3:
			break;
		default:
			cout << "Invaild Input" << endl;
			break;
		}
	} while (choice != 3);

	system("pause");
	return 0;
}
