#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<vector<ll>> mat(n + 1, vector<ll>(m + 1));
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            cin >> mat[i][j];
    flag = false;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (flag == false)
            {
                mat[i][j] += mat[i][j] % 2;
            }
            else if (flag == true)
            {
                mat[i][j] += 1 - mat[i][j] % 2;
            }
            flag ? flag = false : flag = true;
        }
        if (m % 2 == 0)
            flag ? flag = false : flag = true;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            cout << mat[i][j] << gap;
        cout << endl;
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}