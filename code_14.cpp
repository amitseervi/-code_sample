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

void level_order_traversal(Node *root) {
	stack<Node*> s[2];
	s[0].push(root);
	int current = 0;
	while (!s[current].empty()) {
		Node *top = s[current].top();
		cout << top->data << " ";
		s[current].pop();
		int next = 1 - current;
		if (current == 1) {
			if (top->left != NULL) {
				s[next].push(top->left);
			}
			if (top->right != NULL) {
				s[next].push(top->right);
			}
		} else {
			if (top->right != NULL) {
				s[next].push(top->right);
			}
			if (top->left != NULL) {
				s[next].push(top->left);
			}
		}
		if (s[current].empty()) {
			current = 1 - current;
		}
	}
	cout << "\n";
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

	level_order_traversal(root);
}
