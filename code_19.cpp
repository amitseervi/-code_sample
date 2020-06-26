//============================================================================
// Name        : Programing.cpp
// Author      : amit.chaudhary
// Version     :
// Copyright   : No copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;

int main() {
	int arr1[] = {2, 3, 7, 10, 12};
	int arr2[] = {1, 5, 7, 8};
	int n = sizeof(arr1) / sizeof(arr1[0]);
	int m = sizeof(arr2) / sizeof(arr2[0]);
	int i = 0, j = 0;
	int mx1 = 0;
	int mx2 = 0;
	while (i < n && j < m) {
		if (arr1[i] < arr2[j]) {
			mx1 += arr1[i++];
		} else if (arr1[i] > arr2[j]) {
			mx2 += arr2[j++];
		} else {
			mx1 = max(mx1, mx2);
			mx2 = mx1;
			mx1 += arr1[i++];
			mx2 += arr2[j++];
		}
	}
	while (i < n) {
		mx1 += arr1[i++];
	}
	while (j < m) {
		mx2 += arr2[j++];
	}
	cout << max(mx1, mx2) << "\n";
}
