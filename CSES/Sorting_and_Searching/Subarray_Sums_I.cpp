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
    cin >> n >> k;
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (i = 1; i <= n; i++)
        v[i] += v[i - 1];
    ll start_ind = 0, end_ind = 1;
    ll ans = 0;
    while (end_ind <= n)
    {
        ll sum = v[end_ind] - v[start_ind];
        if (sum == k)
        {
            ans++;
            start_ind++;
            end_ind++;
        }
        else if (sum < k)
        {
            end_ind++;
        }
        else if (sum > k)
        {
            start_ind++;
        }
    }
    cout << ans << endl;
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