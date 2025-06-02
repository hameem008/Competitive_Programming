#include <bits/stdc++.h>
using namespace std;
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
    vector<ll> ans(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
        {
            ll start, ind;
            ll curr = 0;
            cout << "?" << gap << i << endl;
            cin >> start;
            ind = start;
            while (start != curr)
            {
                cout << "?" << gap << i << endl;
                cin >> curr;
                ans[ind] = curr;
                ind = curr;
            }
        }
    }
    cout << "!" << gap;
    for (i = 1; i <= n; i++)
    {
        cout << ans[i] << gap;
    }
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