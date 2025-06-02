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
    ll sum = 0;
    for (auto &x : v)
    {
        cin >> x;
        sum += x;
    }
    sort(v.begin(), v.end());
    ll max = v.back();
    if (2 * max <= sum)
    {
        if (max == 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    else
        cout << 2 * max - sum << endl;
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