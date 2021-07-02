// USACO 2016 February Gold Problem 3
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
void init(int n);
bool unite(int a, int b);

const int MAX_NM = 2000;
struct Edge
{
    int from, to, weight;
};

int parent[(MAX_NM + 1) * (MAX_NM + 1)];
int comp_size[(MAX_NM + 1) * (MAX_NM + 1)];
int main()
{
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    int vertical[MAX_NM], horizontal[MAX_NM];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vertical[i]);
    }
    sort(vertical, vertical + n);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &horizontal[i]);
    }
    sort(horizontal, horizontal + m);
    vector<Edge> edges;
    edges.reserve(4 * n * m);
    for (int x = 0; x <= n; x++)
    {
        for (int y = 0; y <= m; y++)
        {
            // edge with right
            if (x + 1 <= n)
            {
                int bottom = (y - 1 >= 0 ? horizontal[y - 1] : 0);
                int top = (y == m ? b : horizontal[y]);
                edges.push_back({
                    (n + 1) * y + x,
                    (n + 1) * y + x + 1,
                    top - bottom
                });
            }
            // edge with top
            if (y + 1 <= m)
            {
                int left = (x - 1 >= 0 ? vertical[x - 1] : 0);
                int right = (x == n ? a : vertical[x]);
                edges.push_back({
                    (n + 1) * y + x,
                    (n + 1) * (y + 1) + x,
                    right - left
                });
            }
        }
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.weight < b.weight;
    });
    init((n + 1) * (m + 1));
    int num_regions = (n + 1) * (m + 1);
    long long ans = 0;
    for (Edge e : edges)
    {
        if (unite(e.from, e.to))
        {
            num_regions--;
            ans += e.weight;
        }
        if (num_regions == 1)
        {
            printf("%lld\n", ans);
            return 0;
        }
    }
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
    int roota = find(a), rootb = find(b);
    if (roota == rootb)
    {
        return false;
    }

    if (comp_size[roota] > comp_size[rootb])
    {
        swap(roota, rootb);
    }
    comp_size[rootb] += comp_size[roota];
    parent[roota] = rootb;
    return true;
}