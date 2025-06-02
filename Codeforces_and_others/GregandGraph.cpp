#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

ll graph[501][501];
ll shortest_distance[501][501];
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
            cin >> graph[i][j];
            if (i != j)
            {
                shortest_distance[i][j] = infinite;
            }
        }
    }
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    reverse(v.begin(), v.end());
    vector<ll> ans;
    vector<ll> vertices;
    for (i = 0; i < v.size(); i++)
    {
        vertices.push_back(v[i]);
        for (j = 1; j <= n; j++)
        {
            shortest_distance[j][v[i]] = min(shortest_distance[j][v[i]], graph[j][v[i]]);
            shortest_distance[v[i]][j] = min(shortest_distance[v[i]][j], graph[v[i]][j]);
        }
        floydwarshall(n, v[i]);
        ll ans_w = 0;
        for (auto x : vertices)
        {
            for (auto y : vertices)
            {
                ans_w += shortest_distance[x][y];
            }
        }
        ans.push_back(ans_w);
    }
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}