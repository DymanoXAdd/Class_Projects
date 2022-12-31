#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Prototypes
string infixToPostfix(string infix);	// Converts an infix expression into its postfix equivalent.
bool isOperand(int);					// Returns true if the char is an alphanumeric
bool isOperator(int);					// Returns true for the four basic operators (+, -, *, /)
int opWeight(int op);					// Used by hasPrecedence to weight the operators
bool hasPrecedence(int top, int c);	// Returns true if top has a higher weight than c.

int main()
{
	string infix;
	string postfix;
	string choice;

	do
	{

		cout << "Enter an infix expression: ";
		getline(cin, infix);
		postfix = infixToPostfix(infix);
		cout << postfix << endl;

		cout << "Again? (n/y)";
		getline(cin, choice);

	} while (choice != "n");

	system("pause");
	return 0;
}

string infixToPostfix(string infix)
{
	stack<char> ops;
	string postfix = "";

	for (int i = 0; i < infix.length(); i++)
	{
		// If the character in the infix expression is a space, skip it.
		if (infix[i] == ' ')
			continue;

		// Else, if the character is an operand (digit or letter), write it to the postfix string.
		else if (isOperand(infix[i]))
		{
			postfix += infix[i];
		}

		// Else, if the character is an open parenthesis, push it to our ops stack for now.
		else if (infix[i] == '(')
			ops.push(infix[i]);

		// Else, if the character is a close parenthesis, we need to write everything from the stack
		// to the postfix expression, stopping at the open parenthesis.
		else if (infix[i] == ')')
		{
			// while the stack is empty, and the top element isn't an open parenthesis...
			while (!ops.empty() && ops.top() != '(')
			{
				// We write the top element to the postfix expression, then pop that element.
				postfix += ops.top();
				postfix += ' ';
				ops.pop();
			}

			ops.pop();	// Afterwards, we pop the top element, to get rid of the open parenthesis.
		}

		// Else, if the character is an operator (+, -, *, /), we will push it to the stack.
		// However, before we do, we need to check if there are higher precedence operators
		// on the top of the stack already. If there are, we pop them and write them to the postfix.
		else if (isOperator(infix[i]))
		{
			// We loop until the stack is empty, we find an open parenthesis, or the operator 
			// on the top of the stack is not higher precedence than the one we are about to push.
			while (!ops.empty() && ops.top() != '(' && hasPrecedence(ops.top(), infix[i]))
			{
				postfix += ops.top();
				postfix += ' ';
				ops.pop();
			}

			// After all higher precedence operators are written to the postfix, push the current.
			ops.push(infix[i]);
		}

		// We'd like to seperate operators and operands in the postfix expression with spaces, 
		// so we add a space to the postfix after each character. However, we don't want to seperate
		// multi-digit operands, so we peek ahead, and if the next character isn't an operand,
		// then we can add the space.
		if (!isOperand(infix[i + 1]))
			postfix += ' ';
	}

	// After processing the entire expression, write anything remaining on the stack to the postfix.
	while (!ops.empty())
	{
		postfix += ops.top();
		postfix += ' ';
		ops.pop();
	}

	// Return the completed postfix expression
	return postfix;
}

bool isOperand(int c)
{
	// If the character is between 0-9, a-z, or A-Z, return true
	if (c >= '0' && c <= '9')
		return true;
	if (c >= 'a' && c <= 'z')
		return true;
	if (c >= 'A' && c <= 'Z')
		return true;

	// Else, it is a non alphanumeric character, return false.
	return false;
}

bool isOperator(int c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}

int opWeight(int op)
{
	switch (op)
	{
	case '*':
	case '/': return 2;
		break;
	case '+':
	case '-': return 1;
		break;
	}
}

bool hasPrecedence(int top, int c)
{
	int op1 = opWeight(top);
	int op2 = opWeight(c);

	if (op1 >= op2)
		return true;
	else
		return false;
}