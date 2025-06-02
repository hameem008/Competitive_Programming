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
    set<ll> divisors;
    ll limit = sqrt(n) + 1;
    for (i = 1; i <= limit; i++)
    {
        if (n % i == 0)
        {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }
    divisors.erase(n);
    pair<ll, ll> ans;
    for (auto x : divisors)
    {
        if ((n - x) % x == 0)
        {
            ans = {x, n - x};
        }
    }
    cout << ans.first << gap << ans.second << endl;
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