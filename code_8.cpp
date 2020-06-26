//============================================================================
// Name        : Programing.cpp
// Author      : amit.chaudhary
// Version     :
// Copyright   : No copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node *next;

	Node(int data) :
			data(data) {
		next = NULL;
	}
};

Node *root;

int main() {
	int arr[] = { 2, 3, 7, 9, 11, 2, 3, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int a = 0;
	for (int i = 0; i < n; i++) {
		a ^= arr[i];
	}

	int right_most_bit = a & ~(a - 1);
	int x = 0;
	int y = 0;
	for (int i = 0; i < n; i++) {
		if (right_most_bit & arr[i]) {
			x = x ^ arr[i];
		} else {
			y = y ^ arr[i];
		}
	}
	cout << x << " " << y << "\n";

}
