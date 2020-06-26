//============================================================================
// Name        : Programing.cpp
// Author      : amit.chaudhary
// Version     :
// Copyright   : No copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;
const int max_bit_len = 36;

struct Node {
	int data;
	Node *left, *right;

	Node(int d) :
			data(d) {
		left = NULL;
		right = NULL;
	}
};

bool isBalanced(Node *root, int *height) {
	if (root == NULL) {
		*height = 0;
		return true;
	}
	int left_height = 0;
	int right_height = 0;
	bool left_ans = isBalanced(root->left, &left_height);
	bool right_ans = isBalanced(root->right, &right_height);
	if (height != NULL) {
		*height = max(left_height, right_height) + 1;
	}
	return left_ans && right_ans && abs(left_height - right_height) <= 1;
}

int main() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->right->left = new Node(6);
	cout << (isBalanced(root, NULL) ? "is balanced" : "is not balanced")
			<< "\n";
}
