//============================================================================
// Name        : Programing.cpp
// Author      : amit.chaudhary
// Version     :
// Copyright   : No copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;

string smallest_possible_no(string str, int n, int index, string result,
	int len) {
	if (index == len) {
		return result;
	}
	if (n == 0) {
		for (int i = index; i < len; i++) {
			result += str[i];
		}
		return result;
	}
	if (len - index <= n) {
		return result;
	}
	char smallest_char = index;
	for (int i = index + 1; i <= index + n; i++) {
		if (str[smallest_char] > str[i]) {
			smallest_char = i;
		}
	}
	int diff = smallest_char - index;
	return smallest_possible_no(str, n - diff, smallest_char + 1,
		result + str[smallest_char], len);
}

int main() {
	string str;
	int n;
	cin >> str >> n;
	cout << "ANSWER : " << smallest_possible_no(str, n, 0, "", str.size())
		<< "\n";

}