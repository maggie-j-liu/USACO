#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int beauty[1000][1000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> beauty[i][j];
        }
    }
    vector<int> sum;
    int altcols = 0, altrows = 0;
    for (int i = 0; i < n; i++)
    {
        sum.assign(2, 0);
        for (int j = 0; j < n; j++)
        {
            sum[j % 2] += beauty[i][j];
        }
        altcols += max(sum[0], sum[1]);
    }
    for (int i = 0; i < n; i++)
    {
       sum.assign(2, 0);
       for (int j = 0; j < n; j++)
       {
           sum[j % 2] += beauty[j][i];
       }
       altrows += max(sum[0], sum[1]);
    }
    
    cout << max(altcols, altrows) << endl;
    return 0;
}
