#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

bool check(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first == b.first && a.second == b.second)
        return true;
    else if (b.first >= a.first && b.first <= a.second)
        return false;
    else if (b.second >= a.first && b.second <= a.second)
        return false;
    else if (a.first <= b.first && a.second >= b.second)
        return false;
    else if (b.first <= a.first && b.second >= a.second)
        return false;
    return true;
}

bool fun(vector<pair<ll, ll>> &a, vector<pair<ll, ll>> &b)
{
    bool result = true;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            result &= check(a[i], b[j]);
        }
    }
    return result;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    ll v[n][m];
    vector<pair<ll, ll>> dum;
    vector<vector<pair<ll, ll>>> col(m, dum);
    vector<string> inv(n);
    for (i = 0; i < n; i++)
    {
        cin >> inv[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            v[i][j] = inv[i][j] - '0';
        }
    }
    for (i = 0; i < m; i++)
    {
        ll high = -1, low = -1;
        for (j = 0; j < n; j++)
        {
            if (v[j][i] == 1)
            {
                if (low == -1)
                {
                    low = j, high = j;
                }
                else
                {
                    high++;
                }
            }
            else
            {
                if (low != -1)
                    col[i].push_back({low, high});
                low = -1, high = -1;
            }
        }
        if (low != -1)
            col[i].push_back({low, high});
    }
    flag = true;
    for (i = 0; i < m - 1; i++)
    {
        flag &= fun(col[i], col[i + 1]);
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
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