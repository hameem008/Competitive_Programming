#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

pair<ll, ll> cnt_2_5(ll n)
{
    ll cnt2 = 0, cnt5 = 0;
    while (n % 2 == 0)
    {
        n /= 2;
        cnt2++;
    }
    while (n % 5 == 0)
    {
        n /= 5;
        cnt5++;
    }
    return {cnt2, cnt5};
}

ll mulby2(ll k, ll m, pair<ll, ll> cnt)
{
    while (cnt.first < cnt.second)
    {
        if (k * 2 <= m)
        {
            k *= 2;
            cnt.first++;
        }
        else
            break;
    }
    return k;
}

ll mulby5(ll k, ll m, pair<ll, ll> cnt)
{
    while (cnt.first > cnt.second)
    {
        if (k * 5 <= m)
        {
            k *= 5;
            cnt.second++;
        }
        else
            break;
    }
    return k;
}

ll mulbyany(ll k, ll m)
{
    while (1)
    {
        if (k * 10 <= m)
            k *= 10;
        else
        {
            for (ll i = 9; i >= 1; i--)
            {
                if (k * i <= m)
                {
                    k *= i;
                    break;
                }
            }
            break;
        }
    }
    return k;
}

void solve(int I, int T)
{
    ll i, j, k = 1, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    pair<ll, ll> cnt = cnt_2_5(n);
    if (cnt.first > cnt.second)
        k = mulby5(k, m, cnt);
    else if (cnt.first < cnt.second)
        k = mulby2(k, m, cnt);
    k = mulbyany(k, m);
    cout << n * k << endl;
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