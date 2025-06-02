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
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll sum = 0;
    vector<ll> presum(n);
    for (i = 0; i < n; i++)
    {
        sum += v[i];
        presum[i] = sum;
    }
    if (presum.back() != 0)
    {
        cout << "No" << endl;
        return;
    }
    flag = true;
    for (i = 0; i < n; i++)
        if (presum[i] < 0)
            flag = false;
    ll cnt = 0;
    for (i = 0; i < n; i++)
    {
        if (presum[i] == 0)
            cnt++;
        else if (cnt)
            flag = false;
    }
    flag ? cout << "Yes" << endl : cout << "No" << endl;
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