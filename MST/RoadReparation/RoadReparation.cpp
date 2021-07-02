// CSES Task 1675
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void init(int n);
bool unite(int a, int b);

struct Edge
{
    int a, b, cost;
};
const int MAX_N = 1e5;
int parent[MAX_N];
int comp_size[MAX_N];
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> graph;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({a - 1, b - 1, c});
    }
    sort(graph.begin(), graph.end(), [](Edge a, Edge b){
        return a.cost < b.cost;
    });
    init(n);
    int num_edges = 0;
    long long ans = 0;
    for (Edge e : graph)
    {
        if (unite(e.a, e.b))
        {
            num_edges++;
            ans += e.cost;
        }
        if (num_edges == n - 1)
        {
            cout << ans << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
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
    int root_a = find(a), root_b = find(b);
    if (root_a == root_b)
    {
        return false;
    }
    if (comp_size[root_a] > comp_size[root_b])
    {
        swap(root_a, root_b);
    }
    parent[root_a] = root_b;
    comp_size[root_b] += comp_size[root_a];
    return true;
}