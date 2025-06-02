#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

pair<ll, ll> countDigit(ll n)
{
    int cnt = 0;
    ll lastDigit;
    while (n != 0)
    {
        lastDigit = n;
        cnt++;
        n /= 10;
    }
    pair<ll, ll> p = {cnt, lastDigit};
    return p;
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    pair<ll, ll> ans = countDigit(n);
    cout << 10 + (ans.first - 2) * 9 + (ans.second - 1) << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}