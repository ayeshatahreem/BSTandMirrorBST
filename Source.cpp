#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	bst object;
	int input = 0, num = 0;
	cout << "Enter data in order to insert :"<<endl;
	while (num != 1)
	{
		cin >> input;
		if (input != -1)		// continue taking input until user enters '-1' just like in flag
		{
			node *p = NULL;
			p = object.getter();
			object.insert(input , p);
		}
		else
		{
			num = 1;			 
		}
	}
	cout << "Tree in descending order as: ";
	node *temp = NULL;		
	temp = object.getter();
	object.rvl(temp);
	cout << endl;
	cout << "Tree in ascending order as: ";
	temp = object.getter();
	object.lvr(temp);
	cout << endl << endl;
	node *temp1 = NULL;
	temp1 = object.getter();
	cout<<"Total nodes in tree are: "<<object.countNode(temp1);
	cout << endl;
	node *temp2 = NULL;
	temp2 = object.getter();
	cout <<"Depth of tree is: "<< object.calculateDepth(temp2);
	cout << endl;

	system("pause");
	return 0;
}