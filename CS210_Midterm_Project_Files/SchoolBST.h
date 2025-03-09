#pragma once

#include "School.cpp"

struct TreeNode {
	School data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(School val) : data(val), left(nullptr), right(nullptr) {}
};

class SchoolBST
{
public:
	void insert(School school);
	School deleteByName(std::string name);
	School findByName(std::string name);
	void displayInOrder();
	void displayPreOrder();
	void displayPostOrder();
private:
	TreeNode* root;
};