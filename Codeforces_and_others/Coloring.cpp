#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n >> m >> k;
    vector<ll> v(m);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    ll part = (n % k == 0) ? n / k : (n / k + 1);
    ll cnt = count(v.begin(), v.end(), v.back());
    if (n % k == 0)
    {
        if (part >= v.back())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        if (part > v.back())
            cout << "YES" << endl;
        else if (part == v.back() && cnt <= n % k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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