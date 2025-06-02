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
    vector<ll> v1(n), v2(n);
    for (auto &x : v1)
        cin >> x;
    for (auto &x : v2)
        cin >> x;
    vector<ll> hash1(n + 1), hash2(n + 1);
    for (i = 0; i < n; i++)
    {
        hash1[v1[i]] = i;
        hash2[v2[i]] = i;
    }
    ll ans = n - 1;
    for (i = n - 1; i > 0; i--)
    {
        if (hash1[v2[i]] > hash1[v2[i - 1]])
            ans--;
        else
            break;
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}