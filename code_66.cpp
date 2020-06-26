#include <bits/stdc++.h>
#define DOUT       \
    if (logEnable) \
    cout
using namespace std;
typedef long long ll;
#define MAX_N 100000
#define MAX_BITS 30
struct TrieNode
{
    bool isLeaf;
    TrieNode *next[2];
    int v;

    TrieNode()
    {
        next[0] = NULL;
        next[1] = NULL;
    }
};

TrieNode *head = new TrieNode();
void addInTrie(int x)
{
    TrieNode *current = head;
    for (int i = MAX_BITS; i >= 0; i--)
    {
        int bit = (x & (1 << i)) ? 1 : 0;
        if (current->next[bit] != NULL)
        {
            current = current->next[bit];
        }
        else
        {
            current->next[bit] = new TrieNode();
            current = current->next[bit];
        }
    }
    current->isLeaf = true;
    current->v = x;
}

int findMaxXor(int x)
{
    TrieNode *current = head;
    int find = 0;
    for (int i = MAX_BITS; i >= 0; i--)
    {
        int bit = (x & (1 << i)) ? 1 : 0;
        if (current->next[1 - bit] != NULL)
        {
            current = current->next[1 - bit];
            find = (find << 1) + (1 - bit);
        }
        else
        {
            current = current->next[bit];
            find = (find << 1) + bit;
        }
    }
    return find ^ x;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        addInTrie(x);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << findMaxXor(x) << "\n";
    }
}