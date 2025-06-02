#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

ll allGCD(vector<ll> v)
{
    ll gcd = v[0];
    for (ll i = 0; i < v.size(); i++)
    {
        gcd = __gcd(gcd, v[i]);
    }
    return gcd;
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        v.push_back(p);
    }

    ll gcd = allGCD(v);
    if (gcd == 1)
    {
        cout << 0 << endl;
        return;
    }
    i = v.size() - 1;
    j = v.size();
    gcd = __gcd(j, v[i]);
    v.push_back(gcd);
    gcd = allGCD(v);
    if (gcd == 1)
    {
        cout << 1 << endl;
        return;
    }
    v.pop_back();
    i = v.size() - 2;
    j = v.size() - 1;
    gcd = __gcd(j, v[i]);
    v.push_back(gcd);
    gcd = allGCD(v);
    if (gcd == 1)
    {
        cout << 2 << endl;
        return;
    }
    cout << 3 << endl;
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