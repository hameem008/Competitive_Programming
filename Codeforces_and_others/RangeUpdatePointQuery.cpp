#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

ll digit_sum(ll n)
{
    ll ans = 0;
    while (n > 0)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

ll digit(ll n)
{
    ll ans = 0;
    while (n > 0)
    {
        ans++;
        n /= 10;
    }
    return ans;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> q;
    set<ll> s;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
        if (v[i] >= 10)
            s.insert(i);
    }
    while (q--)
    {
        cin >> p;
        if (p == 1)
        {
            ll l, r;
            cin >> l >> r;
            auto it_begin = s.lower_bound(l);
            auto it_end = s.upper_bound(r);
            set<ll> del;
            for (; it_begin != it_end; it_begin++)
            {
                v[*it_begin] = digit_sum(v[*it_begin]);
                if (v[*it_begin] < 10)
                    del.insert(*it_begin);
            }
            for (auto x : del)
                s.erase(x);
        }
        else if (p == 2)
        {
            cin >> a;
            cout << v[a] << endl;
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