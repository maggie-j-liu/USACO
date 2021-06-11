#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int grid[1000][1000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int rows_alternate = 0, cols_alternate = 0;
    // each row has an alternating pattern of cow and no cow
    for (int i = 0; i < n; i++)
    {
        int sum[2]{};
        // there are two ways to alternate, odd index and even index
        for (int j = 0; j < n; j++)
        {
            sum[j % 2] += grid[i][j];
        }
        // add the best way to the answer for alternating rows
        rows_alternate += max(sum[0], sum[1]);
    }

    // each column has an alternating pattern of cow and no cow
    for (int i = 0; i < n; i++)
    {
        int sum[2]{};
        // two ways to alternate
        for (int j = 0; j < n; j++)
        {
            sum[j % 2] += grid[j][i];
        }
        // add the best way to the answer for alternating columns
        cols_alternate += max(sum[0], sum[1]);
    }
    
    cout << max(rows_alternate, cols_alternate) << endl;
    return 0;
}
