#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Touple
{
    ll x, y, z;
};

int answer(int x, int y, int z, int a, int b, int c)
{
    ll ans = 3;
    ll diff1 = a - x;
    ll diff2 = b - y;
    ll diff3 = c - z;
    if (diff1 == diff2)
    {
        if (diff3 == 0)
        {
            ans = 1;
        }
        else
        {
            ans = min((ll)2, ans);
        }
    }

    if (diff1 == diff3)
    {
        if (diff2 == 0)
        {
            ans = 1;
        }
        else
        {
            ans = min((ll)2, ans);
        }
    }

    if (diff3 == diff2)
    {
        if (diff1 == 0)
        {
            ans = 1;
        }
        else
        {
            ans = min((ll)2, ans);
        }
    }

    if (diff1 == diff2 && diff2 == diff3)
    {
        ans = 1;
    }
    int m1 = -1;
    int m2 = -2;
    int m3 = -3;
    if (x != 0 && a % x == 0)
    {
        m1 = a / x;
    }
    if (y != 0 && b % y == 0)
    {
        m2 = b / y;
    }
    if (z != 0 && c % z == 0)
    {
        m3 = c / z;
    }

    if (m1 == m2)
    {
        if (m3 == 1)
        {
            ans = 1;
        }
        else
        {
            ans = min((ll)2, ans);
        }
    }
    if (m1 == m3)
    {
        if (m2 == 1)
        {
            ans = 1;
        }
        else
        {
            ans = min((ll)2, ans);
        }
    }
    if (m3 == m2)
    {
        if (m1 == 1)
        {
            ans = 1;
        }
        else
        {
            ans = min((ll)2, ans);
        }
    }
    if (m1 == m2 && m2 == m3)
    {
        ans = 1;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y, z, a, b, c;
        cin >> x >> y >> z;
        cin >> a >> b >> c;
        cout << answer(x, y, z, a, b, c) << "\n";
    }
}