// Kickstart 2021 Round A
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 500;
int parent[2 * MAX_N];
int comp_size[2 * MAX_N];
void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        comp_size[i] = 1;
    }
}

int find(int a)
{
    if (a == parent[a])
    {
        return a;
    }
    return parent[a] = find(parent[a]);
}

bool unite(int a, int b)
{
    int roota = find(a), rootb = find(b);
    if (roota == rootb) return false;
    if (comp_size[roota] > comp_size[rootb]) swap(roota, rootb);
    comp_size[rootb] += comp_size[roota];
    parent[roota] = rootb;
    return true;
}

struct Edge
{
    int from, to, cost;
};

void solve(int c)
{
    int n;
    cin >> n;
    vector<Edge> edges;
    int matrix[MAX_N][MAX_N];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int total_cost = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cost;
            cin >> cost;
            total_cost += cost;
            if (matrix[i][j] == -1)
            {
                edges.push_back({i, j + n, cost});
            }
        }
    }
    for (int i = 0; i < 2 * n; i++)
    {
        int trash;
        cin >> trash;
    }
    init(2 * n);
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.cost > b.cost; });
    int added_edges = 0;
    int dont_pay = 0;
    for (Edge e : edges)
    {
        if (unite(e.from, e.to))
        {
            added_edges++;
            dont_pay += e.cost;
            if (added_edges == 2 * n - 1)
            {
                break;
            }
        }
    }
    printf("Case #%d: %d\n", c, total_cost - dont_pay);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}