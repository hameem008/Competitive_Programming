#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    ll sub = v.back() - v.front();
    for (i = 0; i < n; i++)
    {
        if (v[i] < sub)
            v[i] = sub;
    }
    cout << accumulate(v.begin(), v.end(), 0LL) << endl;
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