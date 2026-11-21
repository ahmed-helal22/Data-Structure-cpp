// A balanced expression is one in which every opening bracket has a corresponding closing bracket
// For example, the expression "{[()]}" is balanced, while the expression "{[(])}" is not balanced.
// This program checks if a given expression is balanced or not using a stack data structure.

#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool arepaired(char opening, char closing)
{
	if (opening == '(' && closing == ')')
		return true;
	else if (opening == '[' && closing == ']')
		return true;
	else if (opening == '{' && closing == '}')
		return true;
	else
		return false;
} 
bool arebalanced(string exp)
{
	stack<char> s;
	for (int i = 0;i < exp.length();i++)
	{
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
		{
			s.push(exp[i]);
		}
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
		{
			if (s.empty() || !arepaired(s.top(), exp[i]))
				return false;
			else
			s.pop();

		}

	}
	return s.empty();
}
int main()
{
	string exp;
	cout << "Enter an expression:" <<"\n";
	cin >> exp;
	if (arebalanced(exp))
		cout << "The expression is balanced." << endl;
	else
		cout << "The expression is not balanced." << endl;
	return 0;
}
