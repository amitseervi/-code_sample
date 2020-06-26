#include <bits/stdc++.h>
using namespace std;

#define BIT_LENGTH 32

typedef long long int ll;

ll fact[BIT_LENGTH];
ll ChooseDp[BIT_LENGTH + 1][BIT_LENGTH + 1];

void initialize()
{
    for (int i = 0; i < BIT_LENGTH; i++)
    {
        fact[i] = -1;
    }

    for (int i = 0; i <= BIT_LENGTH; i++)
    {
        for (int j = 0; j <= BIT_LENGTH; j++)
        {
            ChooseDp[i][j] = -1;
        }
    }
}

ll getFact(ll n)
{
    if (n <= 1)
    {
        return 1;
    }

    if (fact[n] != -1)
    {
        return fact[n];
    }
    return fact[n] = getFact(n - 1) * n;
}

bool isSingleEdge(ll b1, ll b2, ll n)
{
    if (b2 == (b1 + 1) % n)
    {
        return true;
    }
    if (b1 == (b2 + 1) % n)
    {
        return true;
    }
    return false;
}

ll bubbleSort(int arr[], int n)
{
    ll count = 0;
    bool swapped = true;
    while (swapped != false)
    {
        swapped = false;
        count++;
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    }
    return count;
}
ll dp[BIT_LENGTH];

ll getAns(ll arr[], ll n, ll target, ll l)
{
    if (target < 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return 0;
    }
    if (target == 0 && l == 0)
    {
        return 1;
    }
    if (l == 0)
    {
        return 0;
    }
    return getAns(arr, n - 1, target, l) + getAns(arr, n - 1, target - arr[n], l - 1);
}

ll choose(ll n, ll r)
{
    if (r > n)
    {
        return 0;
    }
    if (n == r || r == 0)
    {
        return 1;
    }
    if (ChooseDp[n][r] != -1)
    {
        return ChooseDp[n][r];
    }

    return ChooseDp[n][r] = choose(n - 1, r - 1) + choose(n - 1, r);
}

int main()
{
    initialize();
    int t;
    cin >> t;
    while (t--)
    {
        ll n, l;
        cin >> n >> l;
        ll bitCount[BIT_LENGTH];
        memset(bitCount, 0, sizeof(bitCount));
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            ll x = arr[i];
            for (int j = 0; j < BIT_LENGTH; j++)
            {
                bitCount[j] += (x % 2);
                x /= 2;
            }
        }
        ll bitPairs[BIT_LENGTH];
        ll m = 1;
        for (int i = 0; i < BIT_LENGTH; i++)
        {
            bitPairs[i] = bitCount[i] * m;
            m = m * 2;
        }
        sort(bitPairs, bitPairs + BIT_LENGTH);

        /*
        cout << "--------\n";
        for (int i = 0; i < BIT_LENGTH; i++)
        {
            cout << bitPairs[i] << "\n";
        }
        cout << "-------\n"; */
        ll target = 0;
        ll prev = -1;
        ll pc = 0;
        ll totalPc = 0;
        int i = 0;
        for (i = BIT_LENGTH - 1; l > 0; i--, l--)
        {
            target += bitPairs[i];
            if (prev == bitPairs[i])
            {
                pc++;
            }
            else
            {
                pc = 1;
            }
            prev = bitPairs[i];
        }
        totalPc = pc;
        while (i >= 0 && prev == bitPairs[i])
        {
            totalPc++;
            i--;
        }
        if (prev == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << choose(totalPc, pc) << "\n";
        }
    }
}