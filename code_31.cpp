#include <unordered_map>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

typedef pair<int, int> i2;
int main()
{
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int, i2> ump;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            if (ump.find(sum) == ump.end())
            {
                ump[sum] = make_pair(i, j);
            }
            else
            {
                pair<int, int> p = ump[sum];
                cout << arr[i] << " , " << arr[j] << " :: " << arr[p.first] << " , " << arr[p.second] << "\n";
            }
        }
    }
}