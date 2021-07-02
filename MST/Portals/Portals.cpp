// USACO 2021 US Open Gold Problem 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void init(int n);
bool unite(int a, int b);

struct Edge
{
    int from, to, cost;
};
const int MAX_N = 100000;
int parent[MAX_N * 2];
int comp_size[MAX_N * 2];
int main()
{
    int n;
    cin >> n;
    init(n * 2);
    int cost, p1, p2, p3, p4;
    vector<Edge> edges;
    for (int i = 0; i < n; i++)
    {
        cin >> cost >> p1 >> p2 >> p3 >> p4;
        // an edge from p1 to p2 or from p3 to p4 has 0 cost
        edges.push_back({p1 - 1, p2 - 1, 0});
        edges.push_back({p3 - 1, p4 - 1, 0});
        // to get an edge from p1 to p3, we need to pay to permute the portals
        edges.push_back({p1 - 1, p3 - 1, cost});
    }
    // sort edges in increasing order of cost
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.cost < b.cost;
    });
    int ans = 0;
    for (Edge edge : edges)
    {
        if (unite(edge.from, edge.to))
        {
            ans += edge.cost;
        }
    }
    cout << ans << endl;
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
    return a == parent[a] ? a : (parent[a] = find(parent[a]));
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