#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll v[1000][1000];
bool isVisited[1000][1000];
ll volume;
ll max_volume;

void dfs(ll i, ll j, ll n, ll m)
{
    if (i < 0 || j < 0 || i >= n || j >= m || v[i][j] == 0 || isVisited[i][j])
        return;
    isVisited[i][j] = true;
    volume += v[i][j];
    dfs(i + 1, j, n, m);
    dfs(i - 1, j, n, m);
    dfs(i, j + 1, n, m);
    dfs(i, j - 1, n, m);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    max_volume = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> v[i][j];
            isVisited[i][j] = false;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            volume = 0;
            if (!isVisited[i][j] && v[i][j] != 0)
                dfs(i, j, n, m);
            max_volume = max(max_volume, volume);
        }
    }
    cout << max_volume << endl;
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