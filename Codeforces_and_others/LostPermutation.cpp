#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, s, k, a, b, m, n, p;
    // solve stars
    cin >> n >> s;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll sum = accumulate(v.begin(), v.end(), 0);
    ll max = *max_element(v.begin(), v.end());
    for (i = max; i <= 70; i++)
    {
        if (sum + s == i * (i + 1) / 2)
        {
            cout << "YES" << endl;
            return;
        }
        else if (sum + s < i * (i + 1) / 2)
        {
            cout << "NO" << endl;
            return;
        }
    }
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