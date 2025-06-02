#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

pair<ll, ll> func(ll n)
{
    pair<ll, ll> ret;
    for (int i = 31; i >= 0; i--)
    {
        if (n & (1 << i))
        {
            ret.first = i;
            ret.second = n & (1 << i);
            break;
        }
    }
    return ret;
}
vector<vector<ll>> bin_lift;
vector<ll> next_child;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<ll> parv, ll level)
{
    isVisited[vertex] = true;
    if (level > 0)
    {
        for (auto x : parv)
            bin_lift[vertex].push_back(next_child[x]);
        pair<ll, ll> pr = func(level);
        if (pr.second == level)
            bin_lift[vertex].push_back(1);
    }
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            next_child[vertex] = x;
            dfs(x, graph, isVisited, bin_lift[vertex], level + 1);
        }
    }
}
ll query(ll node, ll k_parrent)
{
    pair<ll, ll> pr = func(k_parrent);
    ll pow_2 = pr.first;
    ll powl_ = pr.second;
    if (powl_ == k_parrent && pow_2 < bin_lift[node].size())
        return bin_lift[node][pow_2];
    else if (pow_2 < bin_lift[node].size())
        return query(bin_lift[node][pow_2], k_parrent - powl_);
    else
        return -1;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> q;
    vector<ll> v;
    bin_lift.assign(n + 1, v);
    next_child.assign(n + 1, 0);
    vector<vector<ll>> graph(n + 1);
    for (i = 2; i <= n; i++)
    {
        cin >> a;
        graph[a].push_back(i);
        graph[i].push_back(a);
    }
    vector<bool> isVisited(n + 1, false);
    dfs(1, graph, isVisited, bin_lift[0], 0);
    for (i = 1; i <= q; i++)
    {
        cin >> a >> b;
        cout << query(a, b) << endl;
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