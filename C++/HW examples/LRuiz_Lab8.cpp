#include <iostream>

using namespace std;

//Fail Attempt for Adjacencey List

//class GraphBox
//{
//private:
//	int count = 0;
//	int counter = 0;
//
//public:
//
//	struct Node
//	{
//	public:
//		char data;
//		const int NUM_VERT = 7;
//		Node *dNext;
//
//		Node(char d, Node* next = NULL)
//		{
//			data = d;
//			dNext = next;
//		}
//
//	};
//
//	Node* listhead = NULL;
//	Node* insertPoint;
//	Node* newNode, * current;
//
//	void GetValue(char n)
//	{
//		newNode = new Node(n);
//
//		if (listhead == NULL)
//		{
//			listhead = new Node(n, listhead);
//			count++;
//		}
//		else {
//			insertPoint = listhead;
//			while (insertPoint->dNext != NULL)
//				insertPoint = insertPoint->dNext;
//
//			insertPoint->dNext = new Node(n);
//			count++;
//		}
//
//	}
//
//	void GetallInfo()
//	{
//		Node* traversal = listhead;
//		while (traversal != NULL)
//		{
//			cout << traversal->data;
//			traversal = traversal->dNext;
//		}
//	}
//
//	int getcounter(int s)
//	{
//		Node* temp = listhead;
//
//		while (temp != NULL)
//		{
//			temp = temp->dNext;
//			s++;
//		}
//		return s;
//	}
//
//	char Getinfo(char ver)
//	{
//		Node* traversal = listhead;
//
//		do
//		{
//			if (ver == traversal->data)
//			{
//				traversal = traversal->dNext;
//				ver = traversal->data;
//				traversal = traversal->dNext;
//			}
//			else if (ver < traversal->data)
//			{
//				traversal = traversal->dNext;
//			}
//			else
//			{
//				ver = traversal->data;
//				traversal = traversal->dNext;
//			}
//
//		} while (traversal != NULL);
//		return ver;
//	}
//
//};
//

// Attempt at Adjacencey Matrix
class GraphSearch
{
private:

	char* s;
	char* s2;
	int front = 0;
	int rear = 0;
	int capacity;
	int count = 0;

public:

	class OverflowException {};
	class UnderflowException {};

	GraphSearch(int Size) 
	{
		s = new char[Size];
		capacity = Size;
	}

	void enqueue(char x)
	{
		if (isFull())
			throw OverflowException();

		s[rear] = x;
		rear = (rear + 1) % capacity;
		count++;
	}

	void dequeuer(char& x)
	{
		if (isEmpty())
			throw UnderflowException();

		x = s[front];
		front = (front + 1) % capacity;
		count--;
	}

	char check(char a)
	{
		for (int x = 0; x < count; x++)
		{
			if (s[x] == a)
			{
				
			}

		}
	}

	bool isFull()
	{
		if (count >= capacity)
			return true;
		else
			return false;
	}

	bool isEmpty()
	{
		if (count <= 0)
			return true;
		else
			return false;
	}

};

//
//int findL(char s)
//{
//	static int LetterVal[11];
//	static int count = 0;
//	char Letters[11];
//	Letters[0] = 'A';
//	Letters[1] = 'B';
//	Letters[2] = 'C';
//	Letters[3] = 'D';
//	Letters[4] = 'E';
//	Letters[5] = 'F';
//	Letters[6] = 'G';
//	Letters[7] = 'H';
//	Letters[8] = 'I';
//	Letters[9] = 'J';
//	Letters[10] = 'K';
//
//	if (count == 0)
//	{
//		LetterVal[0] = 0;
//		LetterVal[1] = 0;
//		LetterVal[2] = 0;
//		LetterVal[3] = 0;
//		LetterVal[4] = 0;
//		LetterVal[5] = 0;
//		LetterVal[6] = 0;
//		LetterVal[7] = 0;
//		LetterVal[8] = 0;
//		LetterVal[9] = 0;
//		LetterVal[10] = 0;
//		count++;
//	}
//
//	if (s == Letters[0] && LetterVal[0] == 0)
//	{
//		LetterVal[0] = 1;
//		return 0;
//	}
//	if (s == Letters[1] && LetterVal[1] == 0)
//	{
//		LetterVal[1] = 1;
//		return 1;
//	}
//	if (s == Letters[2] && LetterVal[2] == 0)
//	{
//		LetterVal[2] = 1;
//		return 2;
//	}
//	if (s == Letters[3] && LetterVal[3] == 0)
//	{
//		LetterVal[3] = 1;
//		return 3;
//	}
//	if (s == Letters[4] && LetterVal[4] == 0)
//	{
//		LetterVal[4] = 1;
//		return 4;
//	}
//	if (s == Letters[5] && LetterVal[5] == 0)
//	{
//		LetterVal[5] = 1;
//		return 5;
//	}
//	if (s == Letters[6] && LetterVal[6] == 0)
//	{
//		LetterVal[6] = 1;
//		return 6;
//	}
//	if (s == Letters[7] && LetterVal[7] == 0)
//	{
//		LetterVal[7] = 1;
//		return 7;
//	}
//	if (s == Letters[8] && LetterVal[8] == 0)
//	{
//		LetterVal[8] = 1;
//		return 8;
//	}
//	if (s == Letters[9] && LetterVal[9] == 0)
//	{
//		LetterVal[9] = 1;
//		return 9;
//	}
//	if (s == Letters[10] && LetterVal[10] == 0)
//	{
//		LetterVal[10] = 1;
//		return 10;
//	}
//
//}
//
//int main(void)
//{
//	int const NUM_VERT = 11;
//	GraphBox* GraphList = new GraphBox[NUM_VERT];
//	GraphSearch* SearchList = new GraphSearch(20);
//	char Node1;
//	char Node2;
//
//	//A Limits
//	GraphList[0].GetValue('A');
//	GraphList[0].GetValue('B');
//	GraphList[0].GetValue('C');
//	GraphList[0].GetValue('E');
//	//B Limits
//	GraphList[1].GetValue('B');
//	GraphList[1].GetValue('A');
//	//C Limits
//	GraphList[2].GetValue('C');
//	GraphList[2].GetValue('D');
//	GraphList[2].GetValue('E');
//	//D Limits
//	GraphList[3].GetValue('D');
//	GraphList[3].GetValue('B');
//	GraphList[3].GetValue('F');
//	GraphList[3].GetValue('H');
//	//E Limits
//	GraphList[4].GetValue('E');
//	GraphList[4].GetValue('G');
//	GraphList[4].GetValue('I');
//	//F Limits
//	GraphList[5].GetValue('F');
//	GraphList[5].GetValue('B');
//	GraphList[5].GetValue('H');
//	//G Limits
//	GraphList[6].GetValue('G');
//	GraphList[6].GetValue('H');
//	GraphList[6].GetValue('I');
//	//H Limits
//	GraphList[7].GetValue('H');
//	GraphList[7].GetValue('G');
//	GraphList[7].GetValue('K');
//	//I Limits
//	GraphList[8].GetValue('I');
//	//J Limits
//	GraphList[9].GetValue('J');
//	GraphList[9].GetValue('F');
//	GraphList[9].GetValue('K');
//	//K Limits
//	GraphList[10].GetValue('K');
//	GraphList[10].GetValue('J');
//
//	cout << "Enter Node1:";
//	cin >> Node1;
//
//	cout << "Enter Node2:";
//	cin >> Node2;
//
//	char temp;
//	SearchList->enqueue(Node1);
//	int k;
//	k = findL(Node1);
//	do
//	{
//		cout << k << endl;
//		temp = GraphList[k].Getinfo(Node1);
//		cout << temp << endl;
//		Node1 = temp;
//		SearchList->enqueue(temp);
//		k = findL(temp);
//
//	} while (temp != Node2);
//
//
//	system("pause");
//	return 0;
//}

int findL(char s)
{
	int S = 0;
	char LetterVal[11];
	static int count = 0;

	S = s - 65;

	if (count == 0)
	{
		LetterVal[0] = 'A';
		LetterVal[1] = 'B';
		LetterVal[2] = 'C';
		LetterVal[3] = 'D';
		LetterVal[4] = 'E';
		LetterVal[5] = 'F';
		LetterVal[6] = 'G';
		LetterVal[7] = 'H';
		LetterVal[8] = 'I';
		LetterVal[9] = 'J';
		LetterVal[10] = 'K';
		count++;
	}

	if (LetterVal[S] == 0)
	{
		LetterVal[0] = 1;
		return 0;
	}
	if (LetterVal[S] == 0)
	{
		LetterVal[1] = 1;
		return 1;
	}
	if (LetterVal[S] == 0)
	{
		LetterVal[2] = 1;
		return 2;
	}
	if (LetterVal[S] == 0)
	{
		LetterVal[3] = 1;
		return 3;
	}
	if (LetterVal[S] == 0)
	{
		LetterVal[4] = 1;
		return 4;
	}
	if (LetterVal[S] == 0)
	{
		LetterVal[5] = 1;
		return 5;
	}
	if (LetterVal[S] == 0)
	{
		LetterVal[6] = 1;
		return 6;
	}
	if (LetterVal[S] == 0)
	{
		LetterVal[7] = 1;
		return 7;
	}
	if (LetterVal[S] == 0)
	{
		LetterVal[8] = 1;
		return 8;
	}
	if (LetterVal[S] == 0)
	{
		LetterVal[9] = 1;
		return 9;
	}
	if (LetterVal[S] == 0)
	{
		LetterVal[10] = 1;
		return 10;
	}

}

char FL(int s)
{
	if (s == 0)
	{
		cout << "A" << endl;
		return 'A';
	}
	if (s == 1)
	{
		cout << "B" << endl;
		return 'B';
	}
	if (s == 2)
	{
		cout << "C" << endl;
		return 'C';
	}
	if (s == 3)
	{
		cout << "D" << endl;
		return 'D';
	}
	if (s == 4)
	{
		cout << "E" << endl;
		return 'E';
	}
	if (s == 5)
	{
		cout << "F" << endl;
		return 'F';
	}
	if (s == 6)
	{
		cout << "G" << endl;
		return 'G';
	}
	if (s == 7)
	{
		cout << "H" << endl;
		return 'H';
	}
	if (s == 8)
	{
		cout << "I" << endl;
		return 'I';
	}
	if (s == 9)
	{
		cout << "J" << endl;
		return 'J';
	}
	if (s == 10)
	{
		cout << "K" << endl;
		return 'K';
	}
}

bool FLBool(int s)
{
	static int LetterVal[11];
	static int count = 0;
	if (count == 0)
	{
		LetterVal[0] = 0;
		LetterVal[1] = 0;
		LetterVal[2] = 0;
		LetterVal[3] = 0;
		LetterVal[4] = 0;
		LetterVal[5] = 0;
		LetterVal[6] = 0;
		LetterVal[7] = 0;
		LetterVal[8] = 0;
		LetterVal[9] = 0;
		LetterVal[10] = 0;
		count++;
	}

	if (LetterVal[s] == 0)
	{
		LetterVal[0] = 1;
		return true;
	}
	if (LetterVal[s] == 0)
	{
		LetterVal[1] = 1;
		return true;
	}
	if (LetterVal[s] == 0)
	{
		LetterVal[2] = 1;
		return true;
	}
	if (LetterVal[s] == 0)
	{
		LetterVal[3] = 1;
		return true;
	}
	if (LetterVal[s] == 0)
	{
		LetterVal[4] = 1;
		return true;
	}
	if (LetterVal[s] == 0)
	{
		LetterVal[5] = 1;
		return true;
	}
	if (LetterVal[s] == 0)
	{
		LetterVal[6] = 1;
		return true;
	}
	if (LetterVal[s] == 0)
	{
		LetterVal[7] = 1;
		return true;
	}
	if (LetterVal[s] == 0)
	{
		LetterVal[8] = 1;
		return true;
	}
	if (LetterVal[s] == 0)
	{
		LetterVal[9] = 1;
		return true;
	}
	if (LetterVal[s] == 0)
	{
		LetterVal[10] = 1;
		return true;
	}

	return false;
}

int main(void)
{
	const int SIZE = 11;
	bool edges[SIZE][SIZE];
	GraphSearch* SearchList = new GraphSearch(20);
	int PS, PE;
	
	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			edges[x][y] = false;
		}
	}

	//A
	edges[0][1] = true;
	edges[0][2] = true;
	edges[0][4] = true;

	//B
	edges[1][0] = true;

	//C
	edges[2][3] = true;
	edges[2][4] = true;

	//D
	edges[3][1] = true;
	edges[3][5] = true;
	edges[3][7] = true;
	
	//E
	edges[4][6] = true;
	edges[4][8] = true;

	//F
	edges[5][1] = true;
	edges[5][7] = true;

	//G
	edges[6][7] = true;
	edges[6][8] = true;

	//H
	edges[7][6] = true;
	edges[7][10] = true;

	//I

	//J
	edges[9][5] = true;
	edges[9][10] = true;

	//K
	edges[10][9] = true;
	cout << "|Point Markers|" << endl;
	cout << "A, B, C, D, E, F, G, H, I, J, K" << endl;
	cout << "0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10\n" << endl;

	cout << "Start Point:";
	cin >> PS;

	cout << "End Point:";
	cin >> PE;

	char temp1 = PS, temp2 = PE;

	cout << PS;
	do
	{
		findL(temp1);
		for (int x = 0; x < SIZE; x++)
		{
			if (edges[temp1][x] == true && FLBool(x))
			{
				FL(temp1);
				SearchList->enqueue(temp1);
				temp1 = x;
				break;
			}
		}
		SearchList->check(temp1);

	} while (temp1 != temp2);

}
