#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

bool isPossible(ll x, ll y)
{
    if (x * x - 4 * y < 0)
        return false;
    ll a = sqrt(x * x - 4 * y);
    if (a * a == x * x - 4 * y)
        return true;
    else
        return false;
}

void solve(int I, int T)
{
    ll i, j, k, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    map<lld, ll> mp;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        mp[p]++;
    }
    cin >> q;
    for (i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (isPossible(x, y))
        {
            lld a = 0, b = 0;
            a = (x + sqrt(x * x - 4 * y)) / 2;
            b = (x - sqrt(x * x - 4 * y)) / 2;
            if (a + b == x && a * b == y)
            {
                if (a == b)
                {
                    cout << mp[a] * (mp[a] - 1) / 2 << gap;
                }
                else
                    cout << mp[a] * mp[b] << gap;
            }
            else
            {
                cout << 0 << gap;
            }
        }
        else
        {
            cout << 0 << gap;
        }
    }
    cout << endl;
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