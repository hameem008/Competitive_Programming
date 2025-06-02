#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }
    ll count = 0, ans = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (v[i] / v[i + 1] < 2)
            count++;
        else
            count = 0;
        if (count == k)
        {
            ans++;
            count--;
        }
    }
    cout << ans << endl;
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