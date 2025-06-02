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
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    set<ll> s;
    for (i = 1; i <= n; i++)
    {
        if (s.find(v[i]) != s.end())
            continue;
        auto it = s.upper_bound(v[i]);
        if (it == s.end())
        {
            s.insert(v[i]);
        }
        else
        {
            s.erase(it);
            s.insert(v[i]);
        }
    }
    cout << s.size() << endl;
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