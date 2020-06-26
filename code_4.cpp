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
	int n;
	cin >> n;
	int ans = 0;
	int m = 5;
	while (n) {
		ans += (n % 2) * m;
		m = m * 5;
		n = n / 2;
	}
	cout << ans << "\n";
}
