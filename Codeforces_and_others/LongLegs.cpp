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
    cin >> a >> b;
    ll limit = 2 * max(sqrt(a) + 1, sqrt(b) + 1);
    ll step = infinite;
    for (i = 1; i <= limit; i++)
    {
        step = min((lld)step, ceil((lld)a / i) + ceil((lld)b / i) + i - 1);
    }
    cout << step << endl;
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