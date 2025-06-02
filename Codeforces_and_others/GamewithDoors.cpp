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
    cin >> m >> n;
    cin >> p >> q;
    ll max_lower = max(m, p), min_lower = min(m, p);
    ll max_upper = max(n, q), min_upper = min(n, q);
    if (max_lower > min_upper)
        cout << 1 << endl;
    else if (m == p && n == q)
        cout << min_upper - max_lower << endl;
    else if (m == p || n == q)
    {
        cout << min_upper - max_lower + 1 << endl;
    }
    else
    {
        cout << min_upper - max_lower + 2 << endl;
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