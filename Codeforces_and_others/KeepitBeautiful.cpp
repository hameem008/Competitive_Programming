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
    bool flag = true;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll first = v.front();
    ll num1 = 0, num2 = 0;
    vector<ll> ans(n, 0);
    for (i = 0; i < n; i++)
    {
        if (v[i] >= num1 && flag)
        {
            num1 = v[i];
            ans[i] = 1;
        }
        else if (v[i] <= first && v[i] >= num2)
        {
            num2 = v[i];
            flag = false;
            ans[i] = 1;
        }
    }
    for (auto x : ans)
        cout << x;
    cout << endl;
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