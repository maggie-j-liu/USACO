// USACO 2015 February Silver Problem 3 (using Prim's)
#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 2000;
int main()
{
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
    int n;
    cin >> n;
    int ids[MAX_N];
    for (int i = 0; i < n; i++)
    {
        cin >> ids[i];
    }
    // n^2 prim's
    bool selected[MAX_N]{};
    int dist[MAX_N]{};
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        // the farthest node from the spanning tree
        int curr_vertex = -1;
        for (int j = 0; j < n; j++)
        {
            if (!selected[j] && (curr_vertex == -1 || dist[j] > dist[curr_vertex]))
            {
                curr_vertex = j;
            }
        }
        selected[curr_vertex] = true;
        ans += dist[curr_vertex];
        for (int to = 0; to < n; to++)
        {
            // since curr_vertex was added to the tree
            // update all other distances accordingly
            dist[to] = max(dist[to], ids[to] ^ ids[curr_vertex]);
        }
    }
    cout << ans << endl;
    return 0;
}