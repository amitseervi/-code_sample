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

Node* findLCAUtil(int n1, int n2, Node *root, bool *v1, bool *v2) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data == n1) {
		*v1 = true;
		return root;
	}
	if (root->data == n2) {
		*v2 = true;
		return root;
	}

	Node *left_lca = findLCAUtil(n1, n2, root->left, v1, v2);
	Node *right_lca = findLCAUtil(n1, n2, root->right, v1, v2);
	if (left_lca != NULL && right_lca != NULL) {
		return root;
	} else {
		return (left_lca == NULL) ? right_lca : left_lca;
	}
}

bool find_key(Node *root, int key) {
	if (root == NULL) {
		return false;
	}
	if (root->data == key) {
		return true;
	}
	return find_key(root->left, key) || find_key(root->right, key);
}

Node* findLCA(int n1, int n2, Node *root) {
	bool present_n1 = false;
	bool present_n2 = false;
	Node *lca = findLCAUtil(n1, n2, root, &present_n1, &present_n2);
	if ((present_n1 && present_n2) || (present_n1 && find_key(root, n2))
			|| (present_n2 && find_key(root, n1))) {
		return lca;
	}
	return NULL;
}

int main() {
	Node *root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(11);
	root->right->left->left = new Node(12);
	root->right->left->right = new Node(13);
	root->right->right->left = new Node(14);
	root->right->right->right = new Node(15);

	Node *lca = findLCA(4, 1, root);
	if (lca != NULL) {
		cout << lca->data << "\n";
	} else {
		cout << "LCA not found\n";
	}
}
