//============================================================================
// Name        : Programing.cpp
// Author      : amit.chaudhary
// Version     :
// Copyright   : No copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;

int shift_arr(int arr[], int size) {
	int i = 0;
	for (int j = 0; j < size; j++) {
		if (arr[j] <= 0) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	return i;
}

int calculate_missing_no(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int index = abs(arr[i]) - 1;
		if (index >= 0 && index < size) {
			arr[index] = -arr[index];
		}
	}
	for (int i = 0; i < size; i++) {
		if (arr[i] > 0) {
			return i + 1;
		}
	}
	return size + 1;
}

int main() {
	int arr[] = { 0, 10, 2, -10, -20 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int start_at = shift_arr(arr, n);
	int ans = calculate_missing_no(arr + start_at, n - start_at);
	cout << "Answer " << ans << "\n";
}
