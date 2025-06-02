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
    vector<ll> ans;
    if (n % 2 == 0)
    {
        cout << -1 << endl;
        return;
    }
    while (n != 1)
    {
        if (((n - 1) / 2) % 2 != 0)
        {
            n = (n - 1) / 2;
            ans.push_back(2);
        }
        else
        {
            n = (n + 1) / 2;
            ans.push_back(1);
        }
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << gap;
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