// USACO 2019 US Open Gold Problem 2
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    cout << 2019201997 - 84 * (k - 1) - 48 * n << endl;
    return 0;
}