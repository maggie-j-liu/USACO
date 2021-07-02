// USACO 2021 US Open Gold Problem 2 (using Prim's)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 100000;
struct Node
{
    int vertex, cost;
    bool operator>(Node other) const
    {
        return cost > other.cost;
    }
};
int main()
{
    int n;
    cin >> n;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<Node> adj[2 * MAX_N];
    for (int i = 0; i < n; i++)
    {
        int cost, p1, p2, p3, p4;
        cin >> cost >> p1 >> p2 >> p3 >> p4;
        p1--; p2--; p3--; p4--;
        // an edge connecting p1 and p2 or connecting p3 and p4 has cost 0
        adj[p1].push_back({p2, 0});
        adj[p2].push_back({p1, 0});
        adj[p3].push_back({p4, 0});
        adj[p4].push_back({p3, 0});
        // to get an edge from p1 to p3, we need to pay to permute the portals
        adj[p1].push_back({p3, cost});
        adj[p3].push_back({p1, cost});
    }
    pq.push({0, 0});
    bool visited[2 * MAX_N]{};
    int ans = 0;
    // use Prim's to find the MST
    while (!pq.empty())
    {
        int curr = pq.top().vertex, cost = pq.top().cost;
        pq.pop();
        if (visited[curr])
        {
            continue;
        }
        visited[curr] = true;
        ans += cost;
        // add edges from the current, visited vertex to unvisited vertices
        for (Node next : adj[curr])
        {
            if (!visited[next.vertex])
            {
                pq.push(next);
            }
        }
    }
    cout << ans << endl;
    return 0;
}