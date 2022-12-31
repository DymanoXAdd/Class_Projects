#include <iostream>
#include <string>
using namespace std;

class EmployeeInfo
{
private:

public:

	struct TreeNode
	{
	public:
		int data;
		string dataFN;
		string dataLN;
		TreeNode* lChild;
		TreeNode* rChild;

		TreeNode(int d, string fs, string ls, TreeNode* l = NULL, TreeNode* r = NULL)
		{
			data = d;
			dataFN = fs;
			dataLN = ls;
			lChild = l;
			rChild = r;
		}
	};

	TreeNode* root = NULL;

	void insert(int key, string fname, string lname)
	{
		insert(key, fname, lname, root);
	}

	void insert(int key, string fs, string ls,TreeNode*& leaf)
	{
		if (leaf == NULL)
		{
			leaf = new TreeNode(key, fs, ls);
			return;
		}

		if (key < leaf->data && key != leaf->data)
			insert(key, fs, ls, leaf->lChild);
		else if (key > leaf->data && key != leaf->data)
			insert(key, fs, ls, leaf->rChild);
		else
		{
			throw string("ID NOT Allowed! Already Taken!\n");
		}
	}

	void inOrder()
	{
		inOrder(root);
	}

	void inOrder(TreeNode* r)
	{
		if (r != NULL)
		{
			inOrder(r->lChild);
			cout << r->data << "|" << r->dataFN  << " " << r->dataLN << endl;
			inOrder(r->rChild);
		}
	}

	void search(int key)
	{
		TreeNode* leaf = root;

		while (leaf != NULL)
		{
			if (leaf->data == key)
			{
				cout << leaf->data << "|" << leaf->dataFN << " " << leaf->dataLN << endl << endl;
				break;
			}
			else if (key < leaf->data)
				leaf = leaf->lChild;
			else
				leaf = leaf->rChild;
			if (leaf == NULL)
			{
				throw string("ID doesn't exist\n");
			}
		}
	}
};

int main(void)
{
	EmployeeInfo* Emplopyeeinfo = new EmployeeInfo;
	string Fname;
	string Lname;
	int Id;
	int choice;

	do
	{
		cout << "|Menu|" << endl;
		cout << "1.Insert Employee Info" << endl;
		cout << "2.Search for Employee" << endl;
		cout << "3.Employees List" << endl;
		cout << ">>";
		cin >> choice;
		cout << "\n";

		switch (choice)
		{
		case 1:
			cout << "Enter ID Number:";
			cin >> Id;
			cin.clear();
			cout << "Enter First Name:";
			cin >> Fname;
			cout << "Enter Last Name:";
			cin >> Lname;
			try
			{
				Emplopyeeinfo->insert(Id, Fname, Lname);
			}
			catch (string s)
			{
				cout << s << endl;
			}
			break;
		case 2:
			cout << "Enter Employee ID:" << endl;
			cout << ">>";
			cin >> Id;
			cout << "Looking for User...." << endl;
			try
			{
				Emplopyeeinfo->search(Id);
			}
			catch (string s)
			{
				cout << s << endl;
			}
			break;
		case 3:
			cout << "\n";
			Emplopyeeinfo->inOrder();
		case 4:
			break;
		default:
			cout << "Invaild Input\n" << endl;
			break;
		}

	}while (choice != 4);

	system("pause");
	return 0;
}