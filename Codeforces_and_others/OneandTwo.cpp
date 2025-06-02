#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    ll twos = 0;
    for (i = 1; i <= n; i++)
    {
        if (v[i] == 2)
            twos++;
    }
    if (twos == 0)
        cout << 1 << endl;
    else if (twos % 2 != 0)
        cout << -1 << endl;
    else
    {
        ll cur_twos = 0;
        for (i = 1; i <= n; i++)
        {
            if (v[i] == 2)
                cur_twos++;
            if (cur_twos * 2 == twos)
                break;
        }
        cout << i << endl;
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