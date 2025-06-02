#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    sort(v.begin(), v.end());
    for (auto &x : v)
        cin >> x;
    flag = false;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i; j < n; j++)
        {
            if (__gcd(v[i], v[j]) <= 2)
                flag = true;
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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