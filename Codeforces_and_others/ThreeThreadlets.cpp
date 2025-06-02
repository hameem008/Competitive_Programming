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
    bool flag = true;
    // solve starts
    vector<ll> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    if (v[0] == v[1] && v[1] == v[2])
    {
    }
    else if (v[0] == v[1] && 2 * v[0] == v[2])
    {
    }
    else if (v[0] * 2 == v[1] && v[0] * 2 == v[2])
    {
    }
    else if (v[0] == v[1] && v[0] * 3 == v[2])
    {
    }
    else if (v[0] == v[1] && v[0] * 4 == v[2])
    {
    }
    else if (v[0] * 2 == v[1] && v[0] * 3 == v[2])
    {
    }
    else
        flag = false;
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