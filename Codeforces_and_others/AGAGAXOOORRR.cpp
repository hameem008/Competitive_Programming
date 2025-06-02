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
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    vector<ll> prefix_xor(n + 1, 0);
    for (i = 1; i <= n; i++)
        prefix_xor[i] = v[i] ^ prefix_xor[i - 1];
    flag = false;
    for (i = 1; i <= n - 1; i++)
    {
        a = prefix_xor[i] ^ prefix_xor[0];
        b = prefix_xor[i] ^ prefix_xor[n];
        if (a == b)
            flag = true;
    }
    for (i = 1; i <= n - 2; i++)
    {
        for (j = i + 1; j <= n - 1; j++)
        {
            a = prefix_xor[i] ^ prefix_xor[0];
            b = prefix_xor[j] ^ prefix_xor[i];
            c = prefix_xor[n] ^ prefix_xor[j];
            if (a == b && b == c)
                flag = true;
        }
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
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