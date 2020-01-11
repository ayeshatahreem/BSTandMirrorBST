#ifndef H_H
#define H_H

#include <iostream>
using namespace std;

struct node
{
	node *left;
	node *right;
	int data;
};

class bst
{
private:
	node *root;

public:
	bst()
	{
		root = NULL;
	}

	bool isEmpty()
	{
		if (root == NULL)
		{
			return true;
		}
		else
			return false;
	}

	bool search(int d, node * p)
	{
		if (p == NULL)
		{
			return false;
		}
		else if (p->data == d)
		{
			return true;
		}
		else if (d < p->data)
		{
			search(d, p->left);
		}
		else if (d > p->data)
		{
			search(d, p->right);
		}
	}

	void insert(int key, node *n)
	{
		node *p = NULL;
		p = n;
		node *temp = new node;
		temp->data = key;
		temp->left = NULL;
		temp->right = NULL;
		if (n == NULL)
		{
			root = temp;
			return;
		}
		while (n != NULL)
		{
			if (key < n->data)
			{
				p = n;
				n = n->left;
			}
			else if (key > n->data)
			{
				p = n;
				n = n->right;
			}
		}
		if (key < p->data)
		{
			p->left = temp;
		}
		else if (key > p->data)
		{
			p->right = temp;
		}
	}

	node *getter()
	{
		return root;
	}

	void lvr(node *p)
	{
		if (p == NULL)
		{
			return;
		}
		else
		{
			lvr(p->left);
		}
		cout << p->data << " ";
		lvr(p->right);
	}

	void print(node *p)
	{
		if (p != NULL)
		{
			cout << p->data;
		}
	}

	void rvl(node *p)
	{
		if (p == NULL)
		{
			return;
		}
		else
		{
			rvl(p->right);
		}
		cout << p->data << " ";
		rvl(p->left);
	}

	int countNode(node *p)
	{
		int count = 1;
		if (p == NULL)
		{
			return 0;
		}
		else if (p != NULL)
		{
			count = count + countNode(p->left);
			count = count + countNode(p->right);
			return count;
		}
	}

	int calculateDepth(node *p)
	{
		node *temp = new node;
		temp = p;
		if (p == NULL)
		{
			return 0;
		}
		else if (p->right == 0 && p->left == 0)
		{
			return 1;
		}
		else
		{
			int lefty = calculateDepth(p->left);
			int righty = calculateDepth(p->right);
			if (lefty > righty)
			{
				return (lefty + 1);
			}
			else
			{
				return (righty + 1);
			}
		}
	}

	void MirrorBST(node *p)
	{
		if (p == NULL)
		{
			return;
		}
		node *temp = new node;
		temp = p->left;
		p->left = p->right;
		p->right = temp;
		MirrorBST(p->left);
		MirrorBST(p->right);
	}

	node *find(node *root) 
	{
		if (root == NULL)
		{
			return NULL;
		}
		else
		{
			node *curr = new node;
			curr = root;
			while (curr->left != NULL)
			{
				curr = curr->left;
				return curr;
			}
		}
	}

	

	node *deleteNode(node *root, int data)
	{
		if (root == NULL)
		{
			return root;
		}
		else if (data < root->data)
		{
			root->left = deleteNode(root->left, data);
		}
		else if (data > root->data)
		{
			root->right = deleteNode(root->right, data);
		}
		else
		{
			if (root->left == NULL && root->right == NULL)
			{
				delete root;
				root = NULL;
			}
			else if (root->left == NULL)
			{
				node *temp = new node;
				temp = root;
				root = root->right;
				delete temp;
			}
			else if (root->right == NULL)
			{
				node *temp = new node;
				temp = root;
				root = root->left;
				delete temp;
			}
			else
			{
				node *temp = new node;
				temp = find(root->right);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
			}
		}
		return root;
	}

	
};
#endif