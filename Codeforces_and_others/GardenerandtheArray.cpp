#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef int ll;
typedef long double lld;
// const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    map<ll, ll> mp;
    vector<vector<ll>> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> k;
        for (j = 0; j < k; j++)
        {
            cin >> a;
            mp[a]++;
            v[i].push_back(a);
        }
    }
    for (i = 0; i < n; i++)
    {
        flag = true;
        for (j = 0; j < v[i].size(); j++)
        {
            if (mp[v[i][j]] == 1)
                flag = false;
        }
        if (flag)
            break;
    }
    flag ? cout << "Yes" << endl : cout << "No" << endl;
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