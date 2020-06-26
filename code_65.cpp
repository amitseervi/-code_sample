#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int max_size = 50000;
const ll MAX_ANS = 1e15;

struct Node
{
    ll sub_tree_sum;
    int enter_time;
    int exit_time;
};

ll min_ans, total_sum;
int current_time;
Node dfs_travel_path[max_size];

//INPUT VALUES PER TEST
int n;
ll node_value[max_size];
vector<int> graph[max_size];

//First entered sub tree with provided sum
//Last entered sub tree with provided sum
map<ll, int> min_time_sum_node, max_time_sum_node;

void reset()
{
    total_sum = 0;
    current_time = 0;
    min_ans = MAX_ANS;

    for (int i = 0; i < max_size; i++)
    {
        graph[i].clear();
    }
    min_time_sum_node.clear();
    max_time_sum_node.clear();
}

void dfs(int root, int parent)
{
    current_time++;
    dfs_travel_path[root].enter_time = current_time;
    dfs_travel_path[root].sub_tree_sum = node_value[root];
    for (vector<int>::iterator it = graph[root].begin(); it != graph[root].end(); it++)
    {
        if (*it != parent)
        {
            dfs(*it, root);
            dfs_travel_path[root].sub_tree_sum += dfs_travel_path[*it].sub_tree_sum;
        }
    }
    dfs_travel_path[root].exit_time = current_time;
}

ll getEnterTime(int root)
{
    return dfs_travel_path[root].enter_time;
}

ll getExitTime(int root)
{
    return dfs_travel_path[root].exit_time;
}

ll getFirstTreeForSum(ll sum)
{
    if (min_time_sum_node.find(sum) == min_time_sum_node.end())
    {
        return -1;
    }
    return min_time_sum_node[sum];
}

ll getLastTreeForSum(ll sum)
{
    if (max_time_sum_node.find(sum) == max_time_sum_node.end())
    {
        return -1;
    }
    return max_time_sum_node[sum];
}

void handle_case_1(int root)
{
    ll sub_tree_sum = dfs_travel_path[root].sub_tree_sum;
    if ((total_sum - sub_tree_sum) % 2 != 0)
    {
        return;
    }
    ll p = (total_sum - sub_tree_sum) / 2; //Other components sum

    int x = -1;

    // Check for first independent tree with sum of p
    if ((x = getFirstTreeForSum(p)) != -1)
    {
        //First tree comes after root
        if (dfs_travel_path[x].enter_time > dfs_travel_path[root].exit_time ||
            dfs_travel_path[x].exit_time < dfs_travel_path[root].enter_time)
        {
            min_ans = min(min_ans, p - sub_tree_sum);
        }
    }

    // Check for second independent tree with sum of p
    if ((x = getLastTreeForSum(p)) != -1)
    {
        //Last tree comes after root
        if (dfs_travel_path[x].enter_time > dfs_travel_path[root].exit_time ||
            dfs_travel_path[x].exit_time < dfs_travel_path[root].enter_time)
        {
            min_ans = min(min_ans, p - sub_tree_sum);
        }
    }

    //First tree is parent of root and have sum of sum(root)+p
    if ((x = getFirstTreeForSum(p + sub_tree_sum)) != -1)
    {
        if (dfs_travel_path[x].enter_time <= dfs_travel_path[root].enter_time &&
            dfs_travel_path[x].exit_time >= dfs_travel_path[root].exit_time)
        {
            min_ans = min(min_ans, p - sub_tree_sum);
        }
    }

    //Second tree is parent of root and have sum of sum(root)+p
    if ((x = getLastTreeForSum(p + sub_tree_sum)) != -1)
    {
        if (dfs_travel_path[x].enter_time <= dfs_travel_path[root].enter_time &&
            dfs_travel_path[x].exit_time >= dfs_travel_path[root].exit_time)
        {
            min_ans = min(min_ans, p - sub_tree_sum);
        }
    }
}

void handle_case_2(int root)
{
    ll sub_tree_sum = dfs_travel_path[root].sub_tree_sum;
    ll add_sum = (3 * sub_tree_sum) - total_sum;

    //There exist two different subTrees with sum = sub_tree_sum;
    //Only one is pending
    if (getFirstTreeForSum(sub_tree_sum) != getLastTreeForSum(sub_tree_sum))
    {
        min_ans = min(min_ans, add_sum);
    }

    int x = -1;
    if ((x = getFirstTreeForSum(sub_tree_sum - add_sum)) != -1)
    {
        if (dfs_travel_path[x].exit_time < dfs_travel_path[root].enter_time ||
            dfs_travel_path[x].enter_time > dfs_travel_path[root].exit_time)
        {
            min_ans = min(min_ans, add_sum);
        }
    }

    if ((x = getLastTreeForSum(sub_tree_sum - add_sum)) != -1)
    {
        if (dfs_travel_path[x].exit_time < dfs_travel_path[root].enter_time ||
            dfs_travel_path[x].enter_time > dfs_travel_path[root].exit_time)
        {
            min_ans = min(min_ans, add_sum);
        }
    }

    if ((x = getFirstTreeForSum((2 * sub_tree_sum) - add_sum)) != -1)
    {
        min_ans = min(min_ans, add_sum);
    }

    if ((x = getLastTreeForSum(2 * sub_tree_sum)) != -1)
    {
        min_ans = min(min_ans, add_sum);
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        total_sum += node_value[i];
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++)
    {
        ll sub_tree_sum = dfs_travel_path[i].sub_tree_sum;
        if (min_time_sum_node.find(sub_tree_sum) == min_time_sum_node.end())
        {
            min_time_sum_node[sub_tree_sum] = i;
            max_time_sum_node[sub_tree_sum] = i;
        }
        else
        {
            int current_min_node = min_time_sum_node[sub_tree_sum];
            int current_max_node = max_time_sum_node[sub_tree_sum];
            if (dfs_travel_path[current_min_node].enter_time > dfs_travel_path[i].enter_time)
            {
                min_time_sum_node[sub_tree_sum] = i;
            }

            if (dfs_travel_path[current_max_node].enter_time < dfs_travel_path[i].enter_time)
            {
                max_time_sum_node[sub_tree_sum] = i;
            }
        }
    }

    min_ans = MAX_ANS;
    //Check whether it is possible to divde tree in such way that two tree have same values if yes than for third tree we can add same amount of value to balance
    if (total_sum % 2 == 0 && min_time_sum_node.find(total_sum / 2) != min_time_sum_node.end())
    {
        min_ans = total_sum / 2;
    }

    for (int i = 0; i < n; i++)
    {
        ll sub_tree_sum = dfs_travel_path[i].sub_tree_sum;

        //Check whether it is possible to use whole sub tree as whole
        if (3 * sub_tree_sum <= total_sum)
        {
            handle_case_1(i);
        }
        else if (2 * sub_tree_sum < total_sum)
        {
            handle_case_2(i);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> node_value[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        solve();
        if (min_ans == MAX_ANS)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << min_ans << "\n";
        }
    }
}
