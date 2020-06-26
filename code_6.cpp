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
	int arr[] = { 2, 3, 3, 5, 3, 4, 1, 7 };
	int k = 8;
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++) {
		arr[arr[i] % k] += k;
	}
	int ans = 0;
	int mx = arr[0] / k;
	for (int i = 1; i < n; i++) {
		if (mx < arr[i] / k) {
			mx = arr[i] / k;
			ans = i;
		}
	}
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] % k;
	}
	cout << "Answer is " << ans << "\n";
}
