#include <stdio.h>
#include <iostream>
#include <vector>
#include "CTimeStat.h"

using namespace std;

#define null -999999999

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


void genBTree(vector<int>& arr, TreeNode* node) {
	static int INDEX = 0;
	if (INDEX >= arr.size()) return;
	node->val = arr[INDEX];
	INDEX++;
	if (INDEX  < arr.size() && arr[INDEX] != null) {
		node->left = new TreeNode();
		genBTree(arr, node->left);
	}
	INDEX++;
	if (INDEX < arr.size() && arr[INDEX] != null) {
		node->right = new TreeNode();
		genBTree(arr, node->right);
	}
}

void seeBTree(const TreeNode* node) {
	if (node == nullptr) return;
	cout << node->val << ", ";
	seeBTree(node->left);
	seeBTree(node->right);
}
void showBTree(const TreeNode* node) {
	cout << "[";
	seeBTree(node);
	cout << "]" << endl;
}


void testBTree() {
	vector<int> arr = { 4,1,6,0,2,5,7,null,null,null,3,null,null,null,8 };
	TreeNode root;
	genBTree(arr, &root);

	showBTree(&root);
}

TreeNode* convertBST(TreeNode* root) {


}