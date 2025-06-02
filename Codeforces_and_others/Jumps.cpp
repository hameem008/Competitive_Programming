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
    cin >> k;
    n = (sqrt(8 * k + 1) - 1) / 2;
    if ((n * (n + 1)) / 2 == k)
    {
        cout << n << endl;
    }
    else
    {
        n++;
        if (k == (n * (n + 1)) / 2 - 1)
        {
            cout << n + 1 << endl;
        }
        else
        {
            cout << n << endl;
        }
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