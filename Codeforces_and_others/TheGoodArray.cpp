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
    v[1] = v[n] = 1;
    ll sum = 0;
    for (i = 1; i <= n; i++)
    {
        sum += v[i];
        if (sum < ceil((lld)i / k))
        {
            v[i] = 1;
            sum++;
        }
    }
    reverse(v.begin(), v.end());
    sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum < ceil((lld)(i + 1) / k))
        {
            v[i] = 1;
            sum++;
        }
    }
    cout << accumulate(v.begin(), v.end(), 0LL) << endl;
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