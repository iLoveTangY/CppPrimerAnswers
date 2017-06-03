#ifndef _EXE_28_
#define _EXE_28_
#pragma once

#include <string>

class TreeNode
{
public:
	TreeNode() : value(""), count(1), left(nullptr), right(nullptr) {}
	void CopyTree(void);
	int ReleaseTree(void);
	~TreeNode()
	{
		if (count)
			ReleaseTree();
	}

private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

void TreeNode::CopyTree(void)
{
	if (left)
		left->CopyTree();
	if (right)
		right->CopyTree();
	count++;
}

int TreeNode::ReleaseTree(void)
{
	if (left)
		if (!left->count)
			delete left;
	if (right)
		if (!right->count)
			delete right;
	count--;
	return count;
}

class BinStrTree
{
public:
	BinStrTree() : root(nullptr) {}
	BinStrTree(const BinStrTree& bst) : root(bst.root) { root->CopyTree(); }
	~BinStrTree();

private:
	TreeNode *root;
};

BinStrTree::~BinStrTree()
{
	if (!root->ReleaseTree())
		delete root;
}
#endif
