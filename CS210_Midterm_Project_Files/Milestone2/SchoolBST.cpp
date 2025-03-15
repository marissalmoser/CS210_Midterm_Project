#include "SchoolBST.h"
#include <string>
#include <iostream>
#include <algorithm>



using namespace std;

void SchoolBST::insertNode(School school, TreeNode*& node)
{
	if (node == nullptr)
	{
		node = new TreeNode(school);
	}
	else if (compareStrings(school.name, node->data.name) > 0)
	{
		// If the school name is greater than the current node's name, go to the right subtree
		insertNode(school, node->right);
	}
	else
	{
		// If the school name is less than or equal to the current node's name, go to the left subtree
		insertNode(school, node->left);
	}
}

void SchoolBST::insert(School school)
{
	if (school.name == "")
	{
		cout << "input can't be null" << endl;
		return;		//input cannot be null
	}
	if (root == nullptr)
	{
		root = new TreeNode(school);
		return;
	}

	insertNode(school, root);
}

School SchoolBST::deleteByName(std::string name)
{
	TreeNode* toDelete = findNodeByName(name);

	//input validation
	if (name == "")
	{
		toDelete->data.name = "";
		return toDelete->data;		//input cannot be null
	}
	if (toDelete->data.name == "")
	{
		toDelete->data.name = "";
		return toDelete->data;		//not in tree
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

School SchoolBST::findByName(std::string name)
{
	return findNodeByName(name)->data;
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
	return -1;
}

void SchoolBST::displayInOrder()
{
	if (root != nullptr)
	{
		inOrder(root);
		cout << endl;
	}
}

void SchoolBST::displayPreOrder()
{
	if (root != nullptr)
	{
		preOrder(root);
		cout << endl;
	}
}

void SchoolBST::displayPostOrder()
{
	if (root != nullptr)
	{
		postOrder(root);
		cout << endl;
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
	//cout << node->data.name;
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

TreeNode* SchoolBST::findNodeByName(std::string name)
{
	TreeNode* temp = root;

	if (name == "")
	{
		temp->data.name = "";
		return temp;		//input cannot be null
	}

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
	return temp;
}

void SchoolBST::displaySchool(School inputSchool)
{
	string s = inputSchool.name + ", " +
		inputSchool.address + ", " +
		inputSchool.city + ", " +
		inputSchool.state + ", " +
		inputSchool.county;

	cout << s << endl;
}

SchoolBST::~SchoolBST()
{
	cout << "destructor called" << endl;
	deleteTree(root);
}

void SchoolBST::deleteTree(TreeNode* node)
{
	if (node == nullptr)
		return;

	deleteTree(node->left);  // Recursively delete left subtree
	deleteTree(node->right); // Recursively delete right subtree

	//delete node;  // Delete the current node
	//cout << node->data.name;
}