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
    cin >> n >> k;
    string str;
    cin >> str;
    vector<ll> v(26, 0);
    for (auto x : str)
    {
        v[x - 'a']++;
    }
    ll odd_cnt = 0;
    for (auto x : v)
    {
        if (x % 2 != 0)
            odd_cnt++;
    }
    if (odd_cnt - 1 > k)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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