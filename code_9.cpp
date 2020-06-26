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
	int arr[] = { 0, 0, 0, 1 };
	int m = 4;
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++) {
		arr[i] = 1 - arr[i];
	}
	int left = 0, right = 0;
	int mx_len = 0, start = 0, end = 0;
	int current_sum = arr[0];
	while (left < n) {
		while (current_sum <= m && right + 1 < n
				&& arr[right + 1] + current_sum <= m) {
			current_sum += arr[right + 1];
			right++;
		}
		if (right + 1 - left > mx_len) {
			mx_len = right + 1 - left;
			start = left;
			end = right;
		}
		current_sum -= arr[left];
		left++;
	}
	for (int i = start; i <= end; i++) {
		if (arr[i] == 1) {
			cout << "index : " << i << "\n";
		}
	}
}
