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

void print_binary(int x, int n) {
	int ans[n + 1];
	memset(ans, 0, sizeof(ans));
	int len = 0;
	while (x) {
		ans[len++] = x % 2;
		x >>= 1;
	}
	for (int i = n - 1; i >= 0; i--) {
		cout << ans[i];
	}
	cout << "\n";
}
int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << "0\n";
	} else if (n == 1) {
		cout << "0 1\n";
	} else {
		int size = pow(2, n);
		int arr[size];
		arr[0] = 0;
		arr[1] = 1;
		int current_size = 2;
		int extra_bit = 1 << 1;
		while (current_size < size) {
			int x = current_size;
			for (int i = current_size - 1; i >= 0; i--) {
				arr[x++] = arr[i];
			}
			for (int i = 0; i < current_size; i++) {
				arr[i + current_size] |= extra_bit;
			}
			extra_bit = extra_bit << 1;
			current_size *= 2;
		}
		for (int i = 0; i < current_size; i++) {
			print_binary(arr[i], n);
		}
	}
}
