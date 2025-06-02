#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

ll v[200008];
ll allx[200008];
ll ally[200008];
ll dpx[200008];
ll dpy[200008];

ll kop(ll i, ll div)
{
    if (i == 1)
        return v[1] * div;
    if (dpx[i] == -1)
        dpx[i] = kop(i - 1, allx[i]);
    if (dpy[i] == -1)
        dpy[i] = kop(i - 1, ally[i]);
    return min(dpx[i] + ally[i] * div, dpy[i] + allx[i] * div);
}

void solve(int I, int T)
{
    ll i, j, k, a, s, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> s;
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
        dpx[i] = -1;
        dpy[i] = -1;
    }
    for (i = 1; i <= n; i++)
    {
        if (v[i] > s)
        {
            allx[i] = s;
            ally[i] = v[i] - s;
        }
        else
        {
            allx[i] = v[i];
            ally[i] = 0;
        }
    }
    cout << kop(n - 1, v[n]) << endl;
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