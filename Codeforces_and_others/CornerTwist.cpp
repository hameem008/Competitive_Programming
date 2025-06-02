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
    vector<vector<ll>> given(n + 1, vector<ll>(m + 1)), need;
    need = given;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            given[i][j] = ch - '0';
        }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            need[i][j] = ch - '0';
        }
    vector<vector<pair<ll, ll>>> hehe(n + 1, vector<pair<ll, ll>>(m + 1));
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (given[i][j] == need[i][j])
                hehe[i][j] = {0, 0};
            else if (given[i][j] > need[i][j])
            {
                if (given[i][j] - need[i][j] == 1)
                {
                    hehe[i][j] = {2, 1};
                }
                else if (given[i][j] - need[i][j] == 2)
                {
                    hehe[i][j] = {1, 2};
                }
            }
            else if (given[i][j] < need[i][j])
            {
                if (need[i][j] - given[i][j] == 1)
                {
                    hehe[i][j] = {1, 2};
                }
                else if (need[i][j] - given[i][j] == 2)
                {
                    hehe[i][j] = {2, 1};
                }
            }
        }
    }
    for (i = 1; i <= n - 1; i++)
    {
        for (j = 1; j <= m - 1; j++)
        {
            if (hehe[i][j].first == 0)
                continue;
            else if (hehe[i][j].first == 1)
            {
                hehe[i][j] = {(hehe[i][j].first - 1 + 3) % 3, (hehe[i][j].second + 1) % 3};
                hehe[i + 1][j + 1] = {(hehe[i + 1][j + 1].first - 1 + 3) % 3, (hehe[i + 1][j + 1].second + 1) % 3};
                hehe[i + 1][j] = {(hehe[i + 1][j].first + 1) % 3, (hehe[i + 1][j].second - 1 + 3) % 3};
                hehe[i][j + 1] = {(hehe[i][j + 1].first + 1) % 3, (hehe[i][j + 1].second - 1 + 3) % 3};
            }
            else if (hehe[i][j].first == 2)
            {
                hehe[i][j] = {(hehe[i][j].first - 2 + 3) % 3, (hehe[i][j].second + 2) % 3};
                hehe[i + 1][j + 1] = {(hehe[i + 1][j + 1].first - 2 + 3) % 3, (hehe[i + 1][j + 1].second + 2) % 3};
                hehe[i + 1][j] = {(hehe[i + 1][j].first + 2) % 3, (hehe[i + 1][j].second - 2 + 3) % 3};
                hehe[i][j + 1] = {(hehe[i][j + 1].first + 2) % 3, (hehe[i][j + 1].second - 2 + 3) % 3};
            }
        }
    }
    flag = true;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (hehe[i][j].first != 0)
                flag = false;
        }
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
    // for (p = 1; p <= n; p++)
    // {
    //     for (q = 1; q <= m; q++)
    //         cout << hehe[p][q].first << "," << hehe[p][q].second << gap;
    //     cout << endl;
    // }
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