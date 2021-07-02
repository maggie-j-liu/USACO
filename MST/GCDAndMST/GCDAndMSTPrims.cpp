// CF Round 714 Div 2 D
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 200000;
void solve()
{
    int n, p;
    cin >> n >> p;
    int nums[MAX_N];
    pair<int, int> sorted_nums[MAX_N]; //number, idx
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sorted_nums[i] = {nums[i], i};
    }
    sort(sorted_nums, sorted_nums + n);
    bool visited[MAX_N]{};
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int curr_min = sorted_nums[i].first, curr_idx = sorted_nums[i].second;
        if (curr_min >= p) break;
        // go right or left
        for (int j = curr_idx - 1; j >= 0; j--)
        {
            if (!visited[j] && nums[j] % curr_min == 0)
            {
                visited[j] = true;
                ans += curr_min;
            }
            else
            {
                break;
            }
        }
        for (int j = curr_idx + 1; j < n; j++)
        {
            if (!visited[j - 1] && nums[j] % curr_min == 0)
            {
                visited[j - 1] = true;
                ans += curr_min;
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (!visited[i])
        {
            ans += p;
        }
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}