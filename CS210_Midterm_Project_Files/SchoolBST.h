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
	TreeNode* findByName(std::string name);
	void displayInOrder();
	void displayPreOrder();
	void displayPostOrder();
private:
	TreeNode* root;
	void insertNode(School school, TreeNode* node);
	int compareStrings(std::string string1, std::string string2);
	void inOrder(TreeNode* node);
	void preOrder(TreeNode* node);
	void postOrder(TreeNode* node);
};