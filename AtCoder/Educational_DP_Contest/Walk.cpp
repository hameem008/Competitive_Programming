#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
const ll mod = 1e9 + 7;

vector<vector<ll>> matrix_multiplication(vector<vector<ll>> a, vector<vector<ll>> b)
{
    ll n = a.size();
    vector<vector<ll>> ret;
    ret.assign(n, vector<ll>(n, 0));
    n--;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            ll var = 0;
            for (ll k = 1; k <= n; k++)
            {
                var += ((a[i][k] % mod) * (b[k][j] % mod)) % mod;
                var %= mod;
            }
            ret[i][j] = var;
        }
    }
    return ret;
}

vector<vector<ll>> binExp(vector<vector<ll>> a, ll b)
{
    if (b == 1)
        return a;
    vector<vector<ll>> rec = binExp(a, b / 2);
    if (b % 2 != 0)
        return matrix_multiplication(matrix_multiplication(rec, rec), a);
    else
        return matrix_multiplication(rec, rec);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<vector<ll>> mat(n + 1, vector<ll>(n + 1, 0));
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> mat[i][j];
    vector<vector<ll>> ans_mat = binExp(mat, k);
    ll ans = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            ans += ans_mat[i][j];
            ans %= mod;
        }
    }
    cout << ans << endl;
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