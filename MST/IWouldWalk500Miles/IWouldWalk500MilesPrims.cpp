// USACO 2019 US Open Gold Problem 2 (using Prim's)
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 7500;
const long long MOD = 2019201997;
int main()
{
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    long long dist[MAX_N];
    bool selected[MAX_N]{};
    for (int i = 0; i < n; i++)
    {
        dist[i] = MOD;
    }
    vector<long long> edges;
    for (int i = 0; i < n; i++)
    {
        int vertex = -1;
        for (int j = 0; j < n; j++)
        {
            if (!selected[j] && (vertex == -1 || dist[j] < dist[vertex]))
            {
                vertex = j;
            }
        }
        edges.push_back(dist[vertex]);
        selected[vertex] = true;
        for (int j = 0; j < n; j++)
        {
            dist[j] = min(dist[j], ((2019201913LL * (min(j, vertex) + 1))
                                        + (2019201949LL * (max(j, vertex) + 1))) % MOD);
        }
    }
    sort(edges.begin(), edges.end(), greater<>());
    cout << edges[k - 1] << endl;
    return 0;
}