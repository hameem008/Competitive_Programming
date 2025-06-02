#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

ll shortest_distance[27][27];
void floydwarshall(ll n)
{
    for (ll i = 1; i <= n; i++)
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
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str1, str2;
    cin >> str1 >> str2;
    n = 26;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i != j)
                shortest_distance[i][j] = infinite;
    cin >> k;
    while (k--)
    {
        char u, v;
        ll w;
        cin >> u >> v >> w;
        shortest_distance[u - 'a' + 1][v - 'a' + 1] = min(shortest_distance[u - 'a' + 1][v - 'a' + 1], w);
    }
    floydwarshall(n);
    if (str1.size() != str2.size())
    {
        cout << -1 << endl;
        return;
    }
    ll ans = 0;
    n = str1.size();
    for (i = 0; i < n; i++)
    {
        if (str1[i] != str2[i])
        {
            a = str1[i] - 'a' + 1;
            b = str2[i] - 'a' + 1;
            ll ch;
            ll add = INT64_MAX;
            for (j = 1; j <= 26; j++)
            {
                if (add > shortest_distance[a][j] + shortest_distance[b][j])
                {
                    ch = j;
                    add = shortest_distance[a][j] + shortest_distance[b][j];
                }
            }
            str1[i] = ch + 'a' - 1;
            ans += add;
        }
    }
    if (ans >= infinite)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
        cout << str1 << endl;
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