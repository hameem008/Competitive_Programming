#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

ll MEX(vector<ll> &v)
{
    set<ll> s(v.begin(), v.end());
    ll mex = 0;
    for (auto x : s)
    {
        if (x == mex)
            mex++;
    }
    return mex;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    set<ll> s(v.begin(), v.end());
    ll cur_mex = MEX(v);
    ll nxt_mex_stind = -1, nxt_mex_edind = n;
    for (i = 0; i < n; i++)
    {
        if (v[i] == cur_mex + 1)
        {
            nxt_mex_stind = i;
            break;
        }
    }
    for (i = n - 1; i >= 0; i--)
    {
        if (v[i] == cur_mex + 1)
        {
            nxt_mex_edind = i;
            break;
        }
    }
    if (nxt_mex_stind == -1 && nxt_mex_edind == n)
    {
        if (v.size() == s.size() && *(--s.end()) < cur_mex)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    else
    {
        for (i = nxt_mex_stind; i <= nxt_mex_edind; i++)
        {
            v[i] = cur_mex;
        }
        if (cur_mex + 1 == MEX(v))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
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