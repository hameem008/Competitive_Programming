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
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    set<ll> mex_set;
    for (i = 0; i <= n + 1; i++)
        mex_set.insert(i);
    vector<ll> sufix_mex(n);
    for (i = n - 1; i >= 0; i--)
    {
        mex_set.erase(v[i]);
        sufix_mex[i] = *mex_set.begin();
    }
    for (i = 0; i <= n + 1; i++)
        mex_set.insert(i);
    vector<ll> ans;
    set<ll> cur_set;
    ll cur_mex, cur_m;
    flag = true;
    for (i = 0; i < n; i++)
    {
        if (flag)
        {
            cur_mex = sufix_mex[i];
            for (auto x : cur_set)
                mex_set.insert(x);
            cur_set.clear();
            flag = false;
            i--;
        }
        else
        {
            mex_set.erase(v[i]);
            cur_set.insert(v[i]);
            cur_m = *mex_set.begin();
            if (cur_m == cur_mex)
            {
                ans.push_back(cur_m);
                flag = true;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << gap;
    cout << endl;
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