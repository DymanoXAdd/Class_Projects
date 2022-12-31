#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class List
{
private:

public:

	struct Node
	{
		double data;
		Node* next;

		Node(double d, Node* p = NULL)
		{
			data = d;
			next = p;
		}
	};

	Node* listHead = NULL;
	Node* insertPoint;
	Node* newNode, * current;

	void GetValue(double val)
	{
		newNode = new Node(val);

		if (listHead == NULL || listHead->data >= newNode->data) {
			newNode->next = listHead;
			listHead = newNode;
		}
		else {
			current = listHead;
			while (current->next != NULL && current->next->data < newNode->data)
				current = current->next;

			newNode->next = current->next;
			current->next = newNode;
		}

	}

	void deleteNode(double key)
	{
		Node* temp = listHead, * prev = NULL;

		if (temp != NULL && temp->data == key) {
			listHead = temp->next;
			delete temp;
			return;
		}

		while (temp != NULL && temp->data != key) {
			prev = temp;
			temp = temp->next;
		}

		if (temp == NULL)
			return;
		prev->next = temp->next;
		delete temp;
	}

	void Display()
	{
		Node* traversal = listHead;
		while (traversal != NULL)
		{
			cout << traversal->data << endl;
			traversal = traversal->next;
		}
	}

};

int main(void)
{
	fstream myFile;
	int Link_Total = 0;
	int choice = 0;
	double delete_choice = 0;
	List _Node;
	int count = 0;
	double newData;

	myFile.open("numbersUnsorted.txt");
	while (!myFile.eof())
	{
		myFile >> newData;
		_Node.GetValue(newData);
		Link_Total++;
	}

	while (choice != 5)
	{
		cout << "|Menu|" << endl;
		cout << "1. Display List Content" << endl;
		cout << "2. Display List Length" << endl;
		cout << "3. Insert an Element" << endl;
		cout << "4. Delete an Element" << endl;
		cout << "5. Exit Menu" << endl;
		cout << ">>";
		cin >> choice;
		switch (choice)
		{
		case 1:

			system("cls");
			cout << "Output" << endl;
			_Node.Display();
			cout << "\n";
			break;
		case 2:
			system("cls");
			cout << "Output" << endl;
			cout << "Current List Length:" << Link_Total << endl;
			cout << "\n";
			break;
		case 3:
			system("cls");
			cout << "Output" << endl;
			cin >> newData;
			_Node.GetValue(newData);
			cout << "\n";
			Link_Total++;
			break;
		case 4:
			system("cls");
			cout << "Output" << endl;
			cin >> delete_choice;
			_Node.deleteNode(delete_choice);
			cout << "\n";
			Link_Total--;
			break;
		default:
			system("cls");
			cout << "Output" << endl;
			cout << "Invalid Input";
			cout << "\n";
		}
		cout << "|------------------|" << endl;
	}

	return 0;
}