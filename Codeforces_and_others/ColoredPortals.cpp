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
    cin >> n >> q;
    vector<string> v(n + 1);
    for (i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        v[i] = str;
    }
    set<string> s = {"BG", "BR", "BY", "GR", "GY", "RY"};
    map<string, set<ll>> mp;
    for (i = 1; i <= n; i++)
    {
        mp[v[i]].insert(i);
    }
    for (i = 1; i <= q; i++)
    {
        cin >> a >> b;
        ll diya = infinite;
        if (v[a].front() == v[b].front() || v[a].front() == v[b].back() || v[a].back() == v[b].front() || v[a].back() == v[b].back())
        {
            cout << max(a, b) - min(a, b) << endl;
        }
        else
        {
            set<string> dum_s = s;
            dum_s.erase(v[a]);
            dum_s.erase(v[b]);
            for (auto x : dum_s)
            {
                auto it = mp[x].lower_bound(a);
                if (it != mp[x].end())
                {
                    diya = min(diya, abs(a - *it) + abs(b - *it));
                }
                if (it != mp[x].begin())
                {
                    it--;
                    diya = min(diya, abs(a - *it) + abs(b - *it));
                }
            }
            if (diya == infinite)
                diya = -1;
            cout << diya << endl;
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