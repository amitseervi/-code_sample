//============================================================================
// Name        : Programing.cpp
// Author      : amit.chaudhary
// Version     :
// Copyright   : No copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;

bool all_order_decreasing_or_equal(string str, int len) {
	for (int i = 0; i < len - 1; i++) {
		if (str[i] < str[i + 1]) {
			return false;
		}
	}
	return true;
}

bool all_order_increasing(string str, int len) {
	for (int i = 0; i < len - 1; i++) {
		if (str[i] >= str[i + 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	string str;
	cin >> str;
	int len = str.size();
	if (all_order_decreasing_or_equal(str, len)) {
		cout << "Not possible\n";
	}
	else if (all_order_increasing(str, len)) {
		swap(str[len - 2], str[len - 1]);
		cout << str << "\n";
	}
	else {
		int cnt[10];
		memset(cnt, 0, sizeof(cnt));
		char last_char = str[len - 1];
		int last_index = len - 1;
		for (int i = len - 1; i > 0; i--) {
			cnt[str[i] - '0']++;
			if (str[i] > str[i - 1]) {
				last_char = str[i - 1];
				last_index = i - 1;
				cnt[str[i - 1] - '0']++;
				break;
			}
		}
		char replace_start_with = last_char;
		for (int i = last_char - '0' + 1; i <= 9; i++) {
			if (cnt[i] > 0) {
				replace_start_with = i + '0';
				cnt[i]--;
				break;
			}
		}
		str[last_index] = replace_start_with;
		int currentIndex = 0;
		for (int i = last_index + 1; i < len; i++) {
			while (currentIndex < 9 && cnt[currentIndex] == 0) {
				currentIndex++;
			}
			str[i] = currentIndex + '0';
			cnt[currentIndex]--;
		}
		cout << str << "\n";
	}

}
