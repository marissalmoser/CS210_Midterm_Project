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
	SchoolBST() : root(nullptr) {}
	void insert(School school);
	School deleteByName(std::string name);
	School findByName(std::string name);
	void displayInOrder();
	void displayPreOrder();
	void displayPostOrder();
	~SchoolBST();
private:
	TreeNode* root;
	void insertNode(School school, TreeNode *& node);
	int compareStrings(std::string string1, std::string string2);
	void inOrder(TreeNode* node);
	void preOrder(TreeNode* node);
	void postOrder(TreeNode* node);
	TreeNode* findNodeByName(std::string name);
	void deleteTree(TreeNode* node);
	void displaySchool(School inputSchool);
};