#include <unordered_map>
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int arr[] = {10, 20, 15, 2, 23, 90, 67};
    int n = sizeof(arr) / sizeof(arr[0]);
    int left = 0;
    int right = n - 1;
    int ans = -1;
    while (left < right)
    {
        int mid = (left + right) >> 1;
        if (mid == 0)
        {
            if (arr[mid] < arr[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                ans = arr[mid];
                break;
            }
        }
        else if (mid == n - 1)
        {
            if (arr[mid] < arr[mid - 1])
            {
                right = mid - 1;
            }
            else
            {
                ans = arr[mid];
                break;
            }
        }
        else
        {
            if (arr[mid] < arr[mid + 1])
            {
                left = mid + 1;
            }
            else if (arr[mid] < arr[mid - 1])
            {
                right = mid - 1;
            }
            else
            {
                ans = arr[mid];
                break;
            }
        }
    }
    cout << "Answer " << ans << "\n";
}