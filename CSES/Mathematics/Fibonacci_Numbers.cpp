#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll mod = 1e9 + 7;

// square matrix nXn
vector<vector<ll>> matrix_multiplication(vector<vector<ll>> &a, vector<vector<ll>> &b, ll n)
{
    vector<vector<ll>> ans(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ans[i][j] += (a[i][k] * b[k][j]) % mod;
                ans[i][j] %= mod;
            }
        }
    }
    return ans;
}
vector<vector<ll>> binExp(vector<vector<ll>> &a, ll b, ll n)
{
    if (b == 1)
        return a;
    vector<vector<ll>> ans = binExp(a, b / 2, n);
    if (b % 2 != 0)
    {
        vector<vector<ll>> v = matrix_multiplication(ans, ans, n);
        return matrix_multiplication(v, a, n);
    }
    else
    {
        return matrix_multiplication(ans, ans, n);
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<vector<ll>> v(2, vector<ll>(2, 0));
    v[0][0] = v[0][1] = v[1][0] = 1;
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    vector<vector<ll>> ans = binExp(v, n, 2);
    cout << ans[0][1] << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}