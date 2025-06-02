#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    v.push_back(1);
    ll cnt = 0;
    ll maxcnt = 0;
    for (auto x : v)
    {
        if (x == 0)
        {
            cnt++;
        }
        else
        {
            maxcnt = max(maxcnt, cnt);
            cnt = 0;
        }
    }
    cout << maxcnt << endl;
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