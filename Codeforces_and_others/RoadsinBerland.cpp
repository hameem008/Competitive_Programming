#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

ll shortest_distance[301][301];
void floydwarshall(ll n, ll i)
{
    for (ll u = 1; u <= n; u++)
    {
        if (u == i)
            continue;
        for (ll v = 1; v <= n; v++)
        {
            if (v == i)
                continue;
            shortest_distance[u][v] = min(shortest_distance[u][v], shortest_distance[u][i] + shortest_distance[i][v]);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> shortest_distance[i][j];
        }
    }
    cin >> k;
    while (k--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        if (shortest_distance[u][v] > w)
        {
            shortest_distance[u][v] = w;
            shortest_distance[v][u] = w;
            floydwarshall(n, u);
            floydwarshall(n, v);
        }
        ll ans = 0;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                ans += shortest_distance[i][j];
            }
        }
        cout << ans / 2 << gap;
    }
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