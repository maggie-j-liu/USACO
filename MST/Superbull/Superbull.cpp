// USACO 2015 February Silver Problem 3
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
void init(int n);
bool unite(int a, int b);

const int MAX_N = 2000;
int parent[MAX_N];
int comp_size[MAX_N];
struct Edge
{
    int from, to, weight;
};
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
    vector<Edge> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            edges.push_back({i, j, ids[i] ^ ids[j]});
        }
    }
    init(n);
    // sort edges in decreasing order of weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.weight > b.weight;
    });
    int eliminated = 0;
    long long ans = 0;
    for (Edge e : edges)
    {
        if (unite(e.from, e.to))
        {
            eliminated++;
            ans += e.weight;
            // if all but 1 team has been eliminated
            if (eliminated == n - 1)
            {
                cout << ans << endl;
                return 0;
            }
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
    parent[roota] = rootb;
    comp_size[rootb] += comp_size[roota];
    return true;
}