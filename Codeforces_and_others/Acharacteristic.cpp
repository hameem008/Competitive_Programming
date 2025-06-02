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
    cin >> n >> k;
    a = 0;
    b = n;
    for (i = 0; i <= n; i++)
    {
        if (a * (a - 1) / 2 + b * (b - 1) / 2 == k)
        {
            cout << "YES" << endl;
            for (j = 0; j < a; j++)
                cout << 1 << gap;
            for (j = 0; j < b; j++)
                cout << -1 << gap;
            cout << endl;
            return;
        }
        a++;
        b--;
    }
    cout << "NO" << endl;
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