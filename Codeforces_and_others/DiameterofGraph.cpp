#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n >> m >> k;
    k -= 2;
    if (m < n - 1 || m > n * (n - 1) / 2)
    {
        cout << "NO" << endl;
    }
    else if (k < 1)
    {
        if (k == 0 && n == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else if (k > 1)
    {
        cout << "YES" << endl;
    }
    else if (k == 1 && m == n * (n - 1) / 2)
    {
        cout << "YES" << endl;
    }
    else
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