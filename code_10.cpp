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
	bool arr[max_bit_len];
	memset(arr, false, sizeof(arr));
	int n;
	cin >> n;
	int len = 0;
	while (n) {
		arr[len++] = n % 2;
		n /= 2;
	}
	int last = 0;
	for (int i = 0; i + 2 < max_bit_len; i++) {
		if (arr[i] && arr[i + 1] && !arr[i + 2]) {
			while (last < i + 2) {
				arr[last++] = false;
			}
			arr[i + 2] = true;
		}
	}
	int ans = 0;
	for (int i = max_bit_len - 1; i >= 0; i--) {
		ans = (ans << 1) + arr[i];
	}
	cout << ans << "\n";
}
