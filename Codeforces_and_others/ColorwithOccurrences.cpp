#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll fun(ll start, ll end, string &str, vector<string> &vstr)
{
    ll ans = -1;
    for (ll i = 0; i < vstr.size(); i++)
    {
        if (vstr[i].size() > end || vstr[i].size() < (end - start))
            continue;
        bool flag = true;
        for (ll j = end - 1, k = vstr[i].size() - 1; k >= 0; j--, k--)
        {
            if (str[j] != vstr[i][k])
                flag = false;
        }
        if (flag)
            ans = i + 1;
    }
    return ans;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str;
    cin >> str;
    cin >> n;
    vector<string> vstr(n);
    for (auto &x : vstr)
        cin >> x;
    ll wi = -1, pi = -1, forwa = 0;
    n = str.size();
    vector<pair<ll, ll>> ansvp;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j <= 10; j++)
        {
            ll pos = fun(i, min(i + j, n), str, vstr);
            if (pos != -1)
            {
                wi = pos;
                pi = min(i + j, n) - vstr[pos - 1].size();
                forwa = min(i + j, n) - i;
            }
        }
        if (wi == -1 && pi == -1)
        {
            cout << -1 << endl;
            return;
        }
        i += forwa;
        i--;
        ansvp.push_back({wi, pi + 1});
        wi = pi = -1;
        forwa = 0;
    }
    cout << ansvp.size() << endl;
    for (auto x : ansvp)
    {
        cout << x.first << gap << x.second << endl;
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