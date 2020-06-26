#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int matrix[100][100];
int p;

struct MyRect
{
    int x1;
    int y1;
    int x2;
    int y2;
};

int getTotal(MyRect r)
{
    cout << 1 << " " << r.x1 << " " << r.y1 << " " << r.x2 << " " << r.y2 << "\n";
    int ans;
    cin >> ans;
    return ans;
}

bool shouldCheck(MyRect r)
{
    int x = rand() % 100;
    return x >= 25 && x < 50;
}

void constructMatrix(MyRect root, int total)
{
    if (total == 0)
    {
        return;
    }
    if (root.x1 == root.x2 && root.y1 == root.y2)
    {
        matrix[root.x1][root.y1] = total;
        return;
    }
    MyRect r[4];
    int m1 = (root.x1 + root.x2) / 2;
    int m2 = (root.y1 + root.y2) / 2;
    r[0] = (struct MyRect){root.x1, root.y1, m1, m2};
    r[1] = (struct MyRect){root.x1, m2 + 1, m1, root.y2};
    r[2] = (struct MyRect){m1 + 1, root.y1, root.x2, m2};
    r[3] = (struct MyRect){m1 + 1, m2 + 1, root.x2, root.y2};
    int check = 0;
    int totalChecked = 0;
    int remainingSum = total;
    //Iterate to check uniformally
    for (int i = 0; i < 10 && totalChecked < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (((check & (1 << j)) == 0) && (shouldCheck(r[j]) || i == 9) && remainingSum > 0 && totalChecked < 3)
            {
                check = check | (1 << j);
                int sum = getTotal(r[j]);
                if (sum < 0)
                {
                    exit(-2);
                }
                remainingSum -= sum;
                totalChecked++;
                constructMatrix(r[j], sum);
            }
        }
    }

    for (int j = 0; j < 4; j++)
    {
        if (((check & (1 << j)) == 0) && remainingSum > 0)
        {
            check = check | (1 << j);
            int sum = remainingSum;
            remainingSum = 0;
            totalChecked++;
            constructMatrix(r[j], sum);
            break;
        }
    }
    return;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n >> p;
        unsigned int time_ui = (unsigned int)(time(NULL));
        srand(time_ui);
        int total = getTotal((struct MyRect){1, 1, n, n});
        memset(matrix, 0, sizeof(matrix));
        constructMatrix((struct MyRect){1, 1, n, n}, total);
        cout << 2 << "\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
}