#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll arr[19][(ll)2e5 + 1];
void fun()
{
    for (ll i = 0; i < 19; i++)
    {
        for (ll j = 1; j < 2e5 + 1; j++)
        {
            if ((j & (1 << i)) == 0)
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }
    for (ll i = 0; i < 19; i++)
    {
        for (ll j = 2; j < 2e5 + 1; j++)
        {
            arr[i][j] = arr[i][j] + arr[i][j - 1];
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    ll l, r;
    cin >> l >> r;
    ll ans = infinite;
    for (i = 0; i < 19; i++)
    {
        ans = min(ans, arr[i][r] - arr[i][l - 1]);
    }
    cout << ans << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fun();
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}