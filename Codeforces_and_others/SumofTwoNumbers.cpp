#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

ll sum(deque<ll> &v)
{
    ll ans = 0;
    for (auto x : v)
        ans += x;
    return ans;
}

deque<ll> digits(ll n)
{
    deque<ll> ans;
    while (n)
    {
        ans.push_back(n % 10);
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    deque<ll> ad = digits(n), bd(ad.size(), 0);
    i = 0;
    while (abs(sum(ad) - sum(bd)) > 1)
    {
        if (ad[i] != 0)
        {
            ad[i]--;
            bd[i]++;
        }
        else
            i++;
    }
    while (ad.front() == 0)
    {
        ad.pop_front();
    }
    for (auto x : ad)
        cout << x;
    cout << gap;
    if (sum(bd) == 0)
        cout << 0 << endl;
    else
    {
        for (auto x : bd)
            cout << x;
        cout << endl;
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