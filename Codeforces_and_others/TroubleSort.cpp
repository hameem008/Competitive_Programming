#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll zeros = 0, ones = 0;
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        if (a == 0)
            zeros++;
        else if (a == 1)
            ones++;
    }
    if (zeros == 0 || ones == 0)
    {
        flag = true;
        for (i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
                flag = false;
        }
        flag ? cout << "Yes" << endl : cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
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