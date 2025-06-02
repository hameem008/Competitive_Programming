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
    vector<ll> v(n + 1), color(n + 1), pos(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        color[i] = ch - '0';
    }
    vector<ll> ans(n + 1, 0);
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= n; i++)
    {
        if (isVisited[i])
            continue;
        set<ll> dum;
        ll add = v[i];
        while (1)
        {
            if (dum.find(add) != dum.end())
                break;
            dum.insert(add);
            isVisited[add] = true;
            add = v[add];
        }
        ll val = 0;
        for (auto x : dum)
            if (color[x] == 0)
                val++;
        for (auto x : dum)
            ans[x] = val;
    }
    for (i = 1; i <= n; i++)
        cout << ans[i] << gap;
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