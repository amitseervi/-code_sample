#include <iostream>
#include <stack>
#include <vector>
#define N 6
using namespace std;

void topologicalSortUtil(bool visited[], stack<int> &s, int i, vector<int> graph[])
{
    if (visited[i])
    {
        return;
    }
    visited[i] = true;
    s.push(i);
    for (vector<int>::iterator it = graph[i].begin(); it != graph[i].end(); it++)
    {
        topologicalSortUtil(visited, s, *it, graph);
    }
}

void topologicalSort(vector<int> graph[])
{
    bool visited[N];
    memset(visited, false, sizeof(visited));
    stack<int> s;
    for (int i = 0; i < N; i++)
    {
        topologicalSortUtil(visited, s, i, graph);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}
int main()
{
    vector<int> graph[N];
    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);
    topologicalSort(graph);
}