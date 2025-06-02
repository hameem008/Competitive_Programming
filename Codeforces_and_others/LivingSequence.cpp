#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

vector<ll> dp(13, 0);
ll rec(ll n)
{
    if (n == 0)
        return dp[0];
    if (dp[n] == 0)
        dp[n] = rec(n - 1) * 9 + pow(10, n - 1);
    return dp[n];
}

vector<ll> digits(ll n)
{
    vector<ll> ans;
    while (n > 0)
    {
        ans.push_back(n % 10);
        n /= 10;
    }
    return ans;
}

bool pf(ll n, ll k)
{
    vector<ll> digitsOfK = digits(n);
    for (auto &x : digitsOfK)
    {
        if (x == 4)
            x++;
    }
    n = 0;
    for (int i = 0; i < digitsOfK.size(); i++)
    {
        n += digitsOfK[i] * pow(10, i);
    }
    ll deduction = 0;
    for (int i = 0; i < digitsOfK.size(); i++)
    {
        if (digitsOfK[i] < 4)
        {
            deduction += dp[i] * digitsOfK[i];
        }
        else if (digitsOfK[i] > 4)
        {
            deduction += dp[i] * (digitsOfK[i] - 1) + pow(10, i);
        }
    }
    return (n - deduction) >= k;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> k;
    ll hi = 1e13, lo = 1, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (pf(mid, k))
            hi = mid;
        else
            lo = mid + 1;
    }
    if (pf(lo, k))
    {
        vector<ll> v = digits(lo);
        for (auto &x : v)
        {
            if (x == 4)
                x++;
        }
        reverse(v.begin(), v.end());
        for (auto x : v)
            cout << x;
        cout << endl;
    }
    else
    {
        vector<ll> v = digits(hi);
        for (auto &x : v)
        {
            if (x == 4)
                x++;
        }
        reverse(v.begin(), v.end());
        for (auto x : v)
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
    rec(12);
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}