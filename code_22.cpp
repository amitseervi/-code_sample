#include <bits/stdc++.h>
using namespace std;

int value[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
string symbol[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
int main()
{
    int vlen = sizeof(value) / sizeof(value[0]);
    int n;
    cin >> n;
    for (int i = vlen - 1; i >= 0; i--)
    {
        while (n >= value[i])
        {
            cout << symbol[i];
            n = n - value[i];
        }
    }
    cout << "\n";
}