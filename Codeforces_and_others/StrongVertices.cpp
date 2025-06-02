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
    vector<ll> va(n + 1), vb(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> va[i];
    }
    for (i = 1; i <= n; i++)
    {
        cin >> vb[i];
    }
    vector<ll> sub(n + 1);
    ll test = -infinite;
    for (i = 1; i <= n; i++)
    {
        sub[i] = va[i] - vb[i];
        test = max(test, sub[i]);
    }
    vector<ll> ans;
    for (i = 1; i <= n; i++)
    {
        if (sub[i] == test)
            ans.push_back(i);
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