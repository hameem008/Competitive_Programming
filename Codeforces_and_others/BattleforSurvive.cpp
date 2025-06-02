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
    cin >> n;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    if (n == 2)
    {
        cout << v[2] - v[1] << endl;
    }
    else if (n == 3)
    {
        cout << v[3] - v[2] + v[1] << endl;
    }
    else
    {
        ll sum = 0;
        for (i = 1; i <= n - 2; i++)
        {
            sum += v[i];
        }
        cout << v[n] - v[n - 1] + sum << endl;
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