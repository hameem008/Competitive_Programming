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
    vector<ll> vx, vy;
    for (i = 1; i <= n; i++)
    {
        cin >> a >> b;
        vx.push_back(a);
        vy.push_back(b);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    if (vx.front() >= 0)
    {
        cout << "YES" << endl;
        return;
    }
    else if (vx.back() <= 0)
    {
        cout << "YES" << endl;
        return;
    }
    else if (vy.front() >= 0)
    {
        cout << "YES" << endl;
        return;
    }
    else if (vy.back() <= 0)
    {
        cout << "YES" << endl;
        return;
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