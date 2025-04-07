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
	School nullSchool;

	//input validation
	if (name == "")
	{
		return nullSchool;		//input cannot be null
	}
	if (toDelete == nullptr)
	{
		return nullSchool;		//not in tree
	}

	//delete functionality based on cases
	School result = toDelete->data;
	
	//leaf node, no children
	if (toDelete->left == nullptr && toDelete->right == nullptr)
	{
		if (root == toDelete)
		{
			root = nullptr;
		}
		//unlink node from parent?
		//delete toDelete;
		toDelete = nullptr;
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

	//two children 
	else
	{
		//find successor
		TreeNode* successor = toDelete->right;
		while (successor->left != nullptr)
		{
			successor = successor->left;
		}

		//copy successor data
		toDelete->data = successor->data;
		//cout << "Successor : " << successor->data.name << endl;

		//delete successor
		
		//leaf node, no children
		if (successor->right == nullptr)
		{
			successor = nullptr;

		}
		//one right child
		else
		{
			successor = successor->right;
			//cout << "Successor's replacement : " << successor->data.name << endl;

		}
	}

	return result;
}

School SchoolBST::findByName(std::string name)
{
	TreeNode* foundNode = findNodeByName(name);
	if (foundNode == nullptr)
	{
		School nullSchool;
		return nullSchool;
	}

	return foundNode->data;
}

int SchoolBST::compareStrings(string string1, string string2)
{
	string lower1 = string1;
	string lower2 = string2;
	transform(lower1.begin(), lower1.end(), lower1.begin(), ::tolower);
	transform(lower2.begin(), lower2.end(), lower2.begin(), ::tolower);

	//cout << lower1 << " and " << lower2 << endl;

	if (lower1 > lower2)
	{
		return 1;
	}
	else if (lower1 < lower2)
	{
		return -1;
	}
	return 0;
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
		return nullptr;
	}

	//look for node
	while (temp != nullptr)
	{
		int val = compareStrings(name, temp->data.name);
		if (val > 0)
		{
			temp = temp->right;
		}
		else if (val < 0)
		{
			temp = temp->left;
		}
		else
		{
			return temp;
		}
	}
	return nullptr;
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

	delete node;
}