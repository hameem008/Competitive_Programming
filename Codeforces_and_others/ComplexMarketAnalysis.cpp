#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

const ll N = 1e6 + 1;
vector<bool> isPrime(N, true);
void calculateSieve()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, e, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> e;
    vector<ll> primeIndex;
    vector<ll> oneIndex(n + 1, false);
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        if (a == 1)
            oneIndex[i] = true;
        else if (isPrime[a])
            primeIndex.push_back(i);
    }
    vector<ll> dp_left(n + 1, 0), dp_right(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        ll add = 0;
        if (oneIndex[i])
        {
            if (i - e >= 1)
                add = dp_left[i - e];
            dp_left[i] = 1 + add;
        }
    }
    for (i = n; i >= 1; i--)
    {
        ll add = 0;
        if (oneIndex[i])
        {
            if (i + e <= n)
                add += dp_right[i + e];
            dp_right[i] = 1 + add;
        }
    }
    ll ans = 0;
    for (i = 0; i < primeIndex.size(); i++)
    {
        if (primeIndex[i] - e >= 1)
            ans += dp_left[primeIndex[i] - e];
        if (primeIndex[i] + e <= n)
            ans += dp_right[primeIndex[i] + e];
        if (primeIndex[i] - e >= 1 && primeIndex[i] + e <= n)
            ans += dp_left[primeIndex[i] - e] * dp_right[primeIndex[i] + e];
    }
    cout << ans << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    calculateSieve();
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}