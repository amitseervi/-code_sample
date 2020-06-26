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

int main() {
	int arr[] = { 0, 1, 0, 0, 1, 1, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int maxSoFar = 0;
	int maxEndingHere = 0;
	int cnt0 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			cnt0++;
		}
		int val = (arr[i] == 1) ? 1 : -1;
		maxEndingHere = max(0, maxEndingHere + val);
		maxSoFar = max(maxSoFar, maxEndingHere);
	}
	maxSoFar = max(0, maxSoFar);
	cout << (cnt0 + maxSoFar) << "\n";

}
