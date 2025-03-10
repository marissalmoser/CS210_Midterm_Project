#include "SchoolBST.h"
#include <string>
#include <iostream>
#include <algorithm>



using namespace std;

void SchoolBST::insert(School school)
{
	if (school.name == "")
	{
		return;		//input cannot be null
	}
	if (root == nullptr)
	{
		TreeNode newNode(school);
		root = &newNode;			//new head - will this work?
		return;
	}

	insertNode(school, root);
}

void SchoolBST::insertNode(School school, TreeNode* node)
{
	if (compareStrings(school.name, node->data.name) > 0)
	{
		if (node->left == nullptr)
		{
			TreeNode newNode(school);
			node->left = &newNode;
			return;
		}
		insertNode(school, node->left);
	}
	else
	{
		if (node->right == nullptr)
		{
			TreeNode newNode(school);
			node->right = &newNode;
			return;
		}
		insertNode(school, node->right);
	}
}

School SchoolBST::deleteByName(std::string name)
{
	TreeNode* toDelete = findByName(name);

	//input validation
	if (name == "")
	{
		toDelete->data.name = "";
		return;		//input cannot be null
	}
	if (toDelete->data.name == "")
	{
		toDelete->data.name = "";
		return;		//not in tree
	}

	//delete functionality based on cases
	TreeNode* result = toDelete;
	
	//leaf node
	if (toDelete->left == nullptr && toDelete->right == nullptr)
	{
		delete toDelete;
	}

	//one child
	else if (toDelete->left == nullptr)
	{
		toDelete = toDelete->right;
	}
	else if (toDelete->right == nullptr)
	{
		toDelete = toDelete->left;
	}

	//two children - find successor
	else
	{
		TreeNode* successor = toDelete->right;
		while (successor->left != nullptr)
		{
			successor = successor->left;
		}
		//delete/replace successor
		toDelete->data = successor->data;
		if (successor->right == nullptr)
		{
			delete successor;
		}
		else
		{
			successor = successor->right;
		}
	}

	return result->data;
}

TreeNode* SchoolBST::findByName(std::string name)
{
	if (name == "")
	{
		return;		//input cannot be null
	}

	TreeNode* temp = root;
	//look for node
	while (temp != nullptr)
	{
		if (compareStrings(name, temp->data.name) > 0)
		{
			if (temp->left == nullptr)
			{
				temp->data.name = "";
				return temp; //not in tree
			}
			temp = temp->left;
		}
		else if (compareStrings(name, temp->data.name) < 0)
		{
			if (temp->right == nullptr)
			{
				temp->data.name = "";
				return temp; //not in tree
			}
			temp = temp->right;
		}
		else
		{
			return temp;
		}
	}
}

int SchoolBST::compareStrings(string string1, string string2)
{
	string lower1 = string1;
	string lower2 = string2;
	transform(lower1.begin(), lower1.end(), lower1.begin(), ::tolower);
	transform(lower2.begin(), lower2.end(), lower2.begin(), ::tolower);

	if (lower1 == lower2)
	{
		return 0;
	}
	else if (lower1 < lower2)
	{
		return 1;
	}
	else if (lower1 > lower2)
	{
		return -1;
	}
}

void SchoolBST::displayInOrder()
{
	if (root != nullptr)
	{
		inOrder(root);
		cout << std::endl;
	}
}

void SchoolBST::displayPreOrder()
{
	if (root != nullptr)
	{
		preOrder(root);
		cout << std::endl;
	}
}

void SchoolBST::displayPostOrder()
{
	if (root != nullptr)
	{
		postOrder(root);
		cout << std::endl;
	}
}

void SchoolBST::inOrder(TreeNode* node)
{
	if (node->left != nullptr) inOrder(node->left);
	displaySchool(node->data);
	if (node->right != nullptr) inOrder(node->right);
}

void SchoolBST::preOrder(TreeNode* node)
{
	displaySchool(node->data);
	if (node->left != nullptr) preOrder(node->left);
	if (node->right != nullptr) preOrder(node->right);
}

void SchoolBST::postOrder(TreeNode* node)
{
	if (node->left != nullptr) postOrder(node->left);
	if (node->right != nullptr) postOrder(node->right);
	displaySchool(node->data);
}

void displaySchool(School inputSchool)
{
	cout << inputSchool.name << ", " <<
		inputSchool.address << ", " <<
		inputSchool.city << ", " <<
		inputSchool.state << ", " <<
		inputSchool.county << "\n" << endl;
}