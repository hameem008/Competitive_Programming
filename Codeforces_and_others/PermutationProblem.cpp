#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll N = 5e5;
vector<vector<ll>> divisors(N + 1);
void func()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j * i <= N; j++)
        {
            divisors[i * j].push_back(i);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c = 0, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1, 0);
    vector<vector<ll>> lob(n + 1), hor(n + 1);
    vector<ll> divisible(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        if (a % i == 0)
        {
            divisible[a / i]++;
            c++;
        }
        else
        {
            ll g = __gcd(a, i);
            lob[a / g].push_back(i / g);
            hor[i / g].push_back(a / g);
        }
    }
    vector<ll> cnt(n + 1, 0);
    ll ans = 0, ans2 = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; i * j <= n; j++)
        {
            for (auto x : lob[i * j])
            {
                cnt[x]++;
            }
            ans2 += hor[i].size() * divisible[i * j];
        }
        for (auto x : hor[i])
        {
            for (auto y : divisors[x])
            {
                ans += cnt[y];
            }
        }
        for (j = 1; i * j <= n; j++)
        {
            for (auto x : lob[i * j])
            {
                cnt[x] = 0;
            }
        }
    }
    ans /= 2;
    ans += c * (c - 1) / 2;
    ans += ans2;
    cout << ans << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    func();
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}