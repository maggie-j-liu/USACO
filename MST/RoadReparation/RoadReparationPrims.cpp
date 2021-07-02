// CSES Task 1675 using Prim's
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int b, cost;
};
const int MAX_N = 1e5;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Node> graph[MAX_N];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
        graph[b - 1].push_back({a - 1, c});
    }
    bool visited[MAX_N]{};
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    long long ans = 0;
    int edges = -1;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if (visited[curr]) continue;
        visited[curr] = true;
        ans += cost;
        edges++;
        for (Node e : graph[curr])
        {
            if (!visited[e.b])
            {
                pq.push({-e.cost, e.b});
            }
        }
    }
    if (edges == n - 1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}