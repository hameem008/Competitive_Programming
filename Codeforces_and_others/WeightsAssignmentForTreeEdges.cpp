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
    vector<ll> ancestor(n + 1);
    ll root;
    for (i = 1; i <= n; i++)
    {
        cin >> ancestor[i];
        if (i == ancestor[i])
            root = i;
    }
    vector<ll> permutation(n);
    for (auto &x : permutation)
    {
        cin >> x;
    }
    vector<ll> sum_weight(n + 1, 0);
    vector<ll> ans(n + 1, -1);
    ll max_weighted_path = 0;
    for (auto x : permutation)
    {
        if (ans[ancestor[x]] != -1 || x == root)
        {
            ans[x] = max_weighted_path - sum_weight[ancestor[x]] + 1;
            max_weighted_path++;
            sum_weight[x] = sum_weight[ancestor[x]] + ans[x];
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
    ans[root] = 0;
    for (i = 1; i <= n; i++)
        cout << ans[i] << gap;
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