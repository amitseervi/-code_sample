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
	int arr[] = { 4, 3, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int mx[n];
	int mn[n];
	mn[0] = -1;
	int mn_v = arr[0];
	for (int i = 1; i < n; i++) {
		if (mn_v < arr[i]) {
			mn[i] = mn_v;
		} else {
			mn[i] = -1;
		}
		if (mn_v > arr[i]) {
			mn_v = arr[i];
		}
	}

	mx[n - 1] = -1;
	int mx_v = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (mx_v > arr[i]) {
			mx[i] = mx_v;
		} else {
			mx[i] = -1;
		}
		if (mx_v < arr[i]) {
			mx_v = arr[i];
		}
	}

	bool pass = false;
	for (int i = 0; i < n; i++) {
		if (mx[i] != -1 && mn[i] != -1) {
			pass = true;
			cout << mn[i] << " " << arr[i] << " " << mx[i] << "\n";
			break;
		}
	}
	if (!pass) {
		cout << "No such triplet\n";
	}
}
