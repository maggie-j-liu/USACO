// CF Round 714 Div 2 D
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
void init(int n);
bool unite(int a, int b);

const int MAX_N = 200000;
int parent[MAX_N];
int comp_size[MAX_N];
void solve()
{
    int n, p;
    scanf("%d %d", &n, &p);
    int nums[MAX_N];
    pair<int, int> sorted_nums[MAX_N];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
        sorted_nums[i].first = nums[i];
        sorted_nums[i].second = i;
    }
    sort(sorted_nums, sorted_nums + n);
    init(n);
    long long ans = 0;
    int num_components = n;
    for (int j = 0; j < n; j++)
    {
        int curr_min = sorted_nums[j].first, idx = sorted_nums[j].second;
        // if weight is >= p
        // we can just connect the components with edges of weight p
        if (curr_min >= p)
        {
            break;
        }
        for (int di : {-1, 1})
        {
            for (int i = idx + di; i >= 0 && i < n; i += di)
            {
                /*
                 * curr_min is the current gcd
                 * we want gcd(curr_min, nums[i]) == curr_min
                 * so we need curr_min to divide nums[i]
                 */
                if (nums[i] % curr_min)
                {
                    break;
                }
                if (unite(idx, i))
                {
                    ans += curr_min;
                    num_components--;
                }
                else // found a cycle
                {
                    break;
                }
            }
        }
    }
    // connect remaining components with edges of weight p
    ans += (num_components - 1) * (long long)p;
    printf("%lld\n", ans);
}

// standard DSU operations
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

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}