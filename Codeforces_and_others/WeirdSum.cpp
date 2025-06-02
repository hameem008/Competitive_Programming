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
    ll mat[n + 1][m + 1];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
        }
    }
    map<ll, pair<vector<ll>, vector<ll>>> mp;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            mp[mat[i][j]].first.push_back(i);
            mp[mat[i][j]].second.push_back(j);
        }
    }
    ll ans = 0;
    for (auto x : mp)
    {
        vector<ll> row = x.second.first;
        vector<ll> colum = x.second.second;
        sort(row.begin(), row.end());
        sort(colum.begin(), colum.end());
        ll sum = accumulate(row.begin(), row.end(), 0LL);
        ll temp_sum = 0;
        for (i = 0; i < row.size(); i++)
        {
            temp_sum += row[i];
            ans += sum - temp_sum - (row.size() - i - 1) * row[i];
        }
        sum = accumulate(colum.begin(), colum.end(), 0LL);
        temp_sum = 0;
        for (i = 0; i < colum.size(); i++)
        {
            temp_sum += colum[i];
            ans += sum - temp_sum - (colum.size() - i - 1) * colum[i];
        }
    }
    cout << ans << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}