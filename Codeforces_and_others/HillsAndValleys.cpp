#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll hill_or_valley(vector<ll> &v, ll i, ll n)
{
    if (i + 1 > n || i - 1 < 1)
        return 0;
    else if (v[i] > v[i + 1] && v[i] > v[i - 1])
        return 1;
    else if (v[i] < v[i + 1] && v[i] < v[i - 1])
        return 1;
    else
        return 0;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    ll total_initimi = 0;
    for (i = 1; i <= n; i++)
    {
        total_initimi += hill_or_valley(v, i, n);
    }
    if (n < 3)
    {
        cout << 0 << endl;
    }
    else
    {
        ll ans = 0;
        for (i = 1; i <= n; i++)
        {
            if (i == 1 || i == n)
            {
                if (i == 1)
                {
                    ll previous = hill_or_valley(v, 2, n);
                    ll old = v[1];
                    v[1] = v[2] - 1;
                    ll now = hill_or_valley(v, 2, n);
                    ans = max(ans, previous - now);
                    v[1] = v[2];
                    now = hill_or_valley(v, 2, n);
                    ans = max(ans, previous - now);
                    v[1] = v[2] + 1;
                    now = hill_or_valley(v, 2, n);
                    ans = max(ans, previous - now);
                    v[1] = old;
                }
                else if (i == n)
                {
                    ll previos = hill_or_valley(v, n - 1, n);
                    ll old = v[n];
                    v[n] = v[n - 1] - 1;
                    ll now = hill_or_valley(v, n - 1, n);
                    ans = max(ans, previos - now);
                    v[n] = v[n - 1];
                    now = hill_or_valley(v, n - 1, n);
                    ans = max(ans, previos - now);
                    v[n] = v[n - 1] + 1;
                    now = hill_or_valley(v, n - 1, n);
                    ans = max(ans, previos - now);
                    v[n] = old;
                }
            }
            else if (i == 2 || i == n - 1)
            {
                if (i == 2)
                {
                    ll previous = hill_or_valley(v, 2, n) + hill_or_valley(v, 3, n);
                    ll old = v[2];
                    v[2] = v[3] - 1;
                    ll now = hill_or_valley(v, 2, n) + hill_or_valley(v, 3, n);
                    ans = max(ans, previous - now);
                    v[2] = v[3];
                    now = hill_or_valley(v, 2, n) + hill_or_valley(v, 3, n);
                    ans = max(ans, previous - now);
                    v[2] = v[3] + 1;
                    now = hill_or_valley(v, 2, n) + hill_or_valley(v, 3, n);
                    ans = max(ans, previous - now);
                    v[2] = old;
                }
                else if (i == n - 1)
                {
                    ll previos = hill_or_valley(v, n - 1, n) + hill_or_valley(v, n - 2, n);
                    ll old = v[n - 1];
                    v[n - 1] = v[n - 2] - 1;
                    ll now = hill_or_valley(v, n - 1, n) + hill_or_valley(v, n - 2, n);
                    ans = max(ans, previos - now);
                    v[n - 1] = v[n - 2];
                    now = hill_or_valley(v, n - 1, n) + hill_or_valley(v, n - 2, n);
                    ans = max(ans, previos - now);
                    v[n - 1] = v[n - 2] + 1;
                    now = hill_or_valley(v, n - 1, n) + hill_or_valley(v, n - 2, n);
                    ans = max(ans, previos - now);
                    v[n - 1] = old;
                }
            }
            else
            {
                ll previous = hill_or_valley(v, i - 1, n) + hill_or_valley(v, i, n) + hill_or_valley(v, i + 1, n);
                ll old = v[i];
                v[i] = v[i - 1] - 1;
                ll now = hill_or_valley(v, i - 1, n) + hill_or_valley(v, i, n) + hill_or_valley(v, i + 1, n);
                ans = max(ans, previous - now);
                v[i] = v[i - 1];
                now = hill_or_valley(v, i - 1, n) + hill_or_valley(v, i, n) + hill_or_valley(v, i + 1, n);
                ans = max(ans, previous - now);
                v[i] = v[i - 1] + 1;
                now = hill_or_valley(v, i - 1, n) + hill_or_valley(v, i, n) + hill_or_valley(v, i + 1, n);
                ans = max(ans, previous - now);
                v[i] = v[i + 1] - 1;
                now = hill_or_valley(v, i - 1, n) + hill_or_valley(v, i, n) + hill_or_valley(v, i + 1, n);
                ans = max(ans, previous - now);
                v[i] = v[i + 1];
                now = hill_or_valley(v, i - 1, n) + hill_or_valley(v, i, n) + hill_or_valley(v, i + 1, n);
                ans = max(ans, previous - now);
                v[i] = v[i + 1] + 1;
                now = hill_or_valley(v, i - 1, n) + hill_or_valley(v, i, n) + hill_or_valley(v, i + 1, n);
                ans = max(ans, previous - now);
                v[i] = old;
            }
        }
        cout << total_initimi - ans << endl;
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