#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {5, 1, 3, 4, 7};
    int x = 12;
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int requiredSum = x - arr[i];
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            int temp = arr[left] + arr[right];
            if (temp >= requiredSum)
            {
                right--;
            }
            else
            {
                ans += (right - left);
                left++;
            }
        }
    }
    cout << "total such triplets are " << ans << "\n";
}