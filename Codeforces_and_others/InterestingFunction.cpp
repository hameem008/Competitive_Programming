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
    ll l, r;
    cin >> l >> r;
    ll lcnt = 0, rcnt = 0;
    for (i = 0; i <= 11; i++)
    {
        lcnt += l / powl(10, i);
        rcnt += r / powl(10, i);
    }
    cout << rcnt - lcnt << endl;
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