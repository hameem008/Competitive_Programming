#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag = true;
    // solve starts
    cin >> n >> m;
    vector<ll> nul(m, 0);
    vector<vector<ll>> v(n, nul);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cin >> v[i][j];
    }
    set<pair<ll, ll>> s;
    s.insert({0, 0});
    for (i = 0; i < n; i++)
    {
        vector<ll> dum(v[i].begin(), v[i].end());
        vector<ll> cng;
        sort(dum.begin(), dum.end());
        for (j = 0; j < m; j++)
        {
            if (dum[j] != v[i][j])
                cng.push_back(j);
        }
        if (cng.size() == 2)
            s.insert({cng[0], cng[1]});
        else if (cng.size() > 2)
            flag = false;
    }
    if (s.size() == 2)
    {
        s.erase({0, 0});
        for (i = 0; i < n; i++)
        {
            swap(v[i][s.begin()->first], v[i][s.begin()->second]);
        }
        for (i = 0; i < n; i++)
        {
            vector<ll> dum(v[i].begin(), v[i].end());
            sort(dum.begin(), dum.end());
            for (j = 0; j < m; j++)
            {
                if (dum[j] != v[i][j])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
    }
    else if (s.size() > 2)
    {
        flag = false;
    }
    flag ? cout << s.begin()->first + 1 << gap << s.begin()->second + 1 << endl : cout << -1 << endl;
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