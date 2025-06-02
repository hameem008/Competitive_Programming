#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    ll val = v[k];
    ll diya = 0;
    ll ind = -1;
    for (i = 1; i <= n; i++)
    {
        if (v[i] <= val)
            diya++;
        else
            break;
    }
    diya--;
    if (i < k)
    {
        ll cnt;
        i == 1 ? cnt = 0 : cnt = 1;
        i++;
        for (; i <= n; i++)
        {
            if (v[i] < val)
                cnt++;
            else
                break;
        }
        diya = max(diya, cnt);
    }
    cout << max((ll)0, diya) << endl;
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