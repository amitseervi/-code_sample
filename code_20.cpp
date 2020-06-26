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
	int currentAns = 0;
	int multiplier = 1;
	int numbertill = 0;
	int ansTemporary = 1;
	int index = 0;
	do {
		if (n & 1) {
			currentAns = numbertill + ansTemporary + currentAns;
		}
		ansTemporary = 2 * (ansTemporary - 1) + multiplier + 1;
		numbertill = (((n & 1) << (index++)) | numbertill);
		multiplier <<= 1;
	} while (n >>= 1);
	cout << "ans " << currentAns << "\n";
}
