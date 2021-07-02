// CF Round 270 D
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool unite(int a, int b);
bool dfs(int node, int par, int source, int distance);
void init(int n);

const int MAX_N = 2000;
struct Edge
{
    int from, to, dist;
};
struct Node
{
    int b, w;
};
int parent[MAX_N * MAX_N];
int comp_size[MAX_N * MAX_N];
int dist[MAX_N][MAX_N];
vector<Node> adj[MAX_N];
int main()
{
    int n;
    cin >> n;
    vector<Edge> edges;
    bool ans = true;
    init(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &dist[i][j]);
            if (i < j)
            {
                edges.push_back({i, j, dist[i][j]});
            }
            else if (i == j && dist[i][i] != 0)
            {
                printf("NO\n");
                return 0;
            }
            else if (j < i && dist[i][j] != dist[j][i])
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.dist < b.dist;
    });
    int added_edges = 0;
    for (Edge edge : edges)
    {
        if (unite(edge.from, edge.to))
        {
            added_edges++;
            adj[edge.from].push_back({edge.to, edge.dist});
            adj[edge.to].push_back({edge.from, edge.dist});
            if (added_edges == n - 1)
            {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans &= dfs(i, -1, i, 0);
    }
    printf((ans ? "YES\n" : "NO\n"));
    return 0;
}

bool dfs(int node, int par, int source, int distance)
{
    if (dist[source][node] != distance
            || (source != node && dist[source][node] == 0))
    {
        return false;
    }
    bool ans = true;
    for (auto next : adj[node])
    {
        if (next.b != par)
        {
            ans &= dfs(next.b, node, source, distance + next.w);
        }
    }
    return ans;
}

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
    if (roota == rootb)
    {
        return false;
    }
    if (comp_size[roota] > comp_size[rootb])
    {
        swap(roota, rootb);
    }
    parent[roota] = rootb;
    comp_size[rootb] += comp_size[roota];
    return true;
}