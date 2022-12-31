#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

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

int Hash(string key, int tableSize)
{
	int hashValue = 0;

	for (int i = 0; i < key.length(); i++)
		hashValue = 35 * hashValue + key[i];

	hashValue %= tableSize;
	if (hashValue < 0)  
		hashValue += tableSize;

	return hashValue;
}


int main(void)
{
	fstream myFile;
	myFile.open("dict-en-US.txt");
	string key[50];
	List _Node;
	int choice;
	string word;
	const int SIZE = 50;

	while (!myFile.eof())
	{
		for (int y = 0; y < SIZE; y++)
		{
			myFile >> key[y];
		}
	}

	for (int x = 0; x < SIZE; x++)
	{
		_Node.GetValue(Hash(key[x], SIZE));
	}


	cout << "|Hash Table Spellcheck|" << endl;
	cout << "1) Spellcheck a word" << endl;
	cout << "2) Spellcheck a file" << endl;
	cout << "3) Display hash information" << endl;
	cout << "4) Exit" << endl;
	cout << ">>";
	cin >> choice;

	switch (choice)
	{
	case 1:


		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	default:
		cout << "Invaild Input" << endl;
		break;
	}
}