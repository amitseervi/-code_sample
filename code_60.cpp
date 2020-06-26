#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#define N 5
struct Edge
{
    int x, y, cost;
    Edge(int x, int y, int cost) : x(x), y(y), cost(cost)
    {
    }
};

struct CompareEdge
{
    bool operator()(const Edge &a, const Edge &b)
    {
        return a.cost > b.cost;
    }
};
// Minimum spanning tree
int main()
{
    int adjacency_matrix[][N] = {{0, 2, 0, 6, 0},
                                 {2, 0, 3, 8, 5},
                                 {0, 3, 0, 0, 7},
                                 {6, 8, 0, 0, 9},
                                 {0, 5, 7, 9, 0}};
    bool in_mst[N];
    memset(in_mst, false, sizeof(in_mst));
    priority_queue<Edge, vector<Edge>, CompareEdge> q;
    in_mst[0] = true;
    int cost = 0;
    for (int i = 1; i < N; i++)
    {
        if (adjacency_matrix[0][i] != 0)
        {
            q.push(Edge(0, i, adjacency_matrix[0][i]));
        }
    }
    int connected = 1;
    while (q.size() && connected < N)
    {
        Edge e = q.top();
        q.pop();
        if (!in_mst[e.x] && in_mst[e.y])
        {
            cost += e.cost;
            in_mst[e.x] = true;
            cout << "CONNECTED " << e.x << " " << e.y << "\n";
            connected++;
            for (int i = e.x + 1; i < N; i++)
            {
                if (adjacency_matrix[e.x][i] != 0)
                {
                    q.push(Edge(e.x, i, adjacency_matrix[e.x][i]));
                }
            }
        }
        else if (in_mst[e.x] && !in_mst[e.y])
        {
            cost += e.cost;
            in_mst[e.y] = true;
            cout << "CONNECTED " << e.x << " " << e.y << "\n";
            connected++;
            for (int i = e.y + 1; i < N; i++)
            {
                if (adjacency_matrix[e.y][i] != 0)
                {
                    q.push(Edge(e.y, i, adjacency_matrix[e.y][i]));
                }
            }
        }
    }
    cout << "MST cost " << cost << "\n";
}
