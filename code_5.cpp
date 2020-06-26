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
	int arr[] = { 3, 3, 4, 3, 1, 1, 1, 7, 7, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int one = 0, two = 0, common_neg = 0;
	for (int i = 0; i < n; i++) {
		two = (one & arr[i]) | two;
		one = one ^ arr[i];
		common_neg = ~(two & one);
		one &= common_neg;
		two &= common_neg;
	}
	cout << "answer " << one << "\n";
}
