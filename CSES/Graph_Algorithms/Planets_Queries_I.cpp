#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

map<ll, ll> mp;

ll time_ = 0;
vector<ll> start_t, end_t;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    time_++;
    start_t[vertex] = time_;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
        }
    }
    time_++;
    end_t[vertex] = time_;
}

vector<ll> nodes;
void dfs_2(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    nodes.push_back(vertex);
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs_2(x, graph, isVisited);
        }
    }
}

void prev_solve(ll n, vector<vector<ll>> &graph, vector<vector<ll>> &graph_t)
{
    ll i, j, k, a, b, c, d, m, p, q;
    bool flag;
    // solve starts
    start_t.assign(n + 1, 0);
    end_t.assign(n + 1, 0);
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            dfs(i, graph, isVisited);
        }
    }
    isVisited.assign(n + 1, false);
    vector<pair<ll, ll>> vp;
    for (i = 1; i <= n; i++)
    {
        vp.push_back({end_t[i], i});
    }
    sort(vp.begin(), vp.end());
    reverse(vp.begin(), vp.end());
    for (auto x : vp)
    {
        if (!isVisited[x.second])
        {
            nodes.clear();
            dfs_2(x.second, graph_t, isVisited);
            for (auto y : nodes)
            {
                mp[y] = nodes.size();
            }
        }
    }
    // solve ends
}

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
void bin_lift_func(ll n)
{
    for (ll j = 1; j <= 18; j++)
    {
        for (ll i = 1; i <= n; i++)
        {
            bin_lift[i][j] = bin_lift[bin_lift[i][j - 1]][j - 1];
        }
    }
}
ll get_kth_parrent(ll node, ll kth_parrent)
{
    if (kth_parrent == 0)
        return node;
    pair<ll, ll> pr = func(kth_parrent);
    ll pow_2 = pr.first;
    ll powl_ = pr.second;
    if (powl_ == kth_parrent && pow_2 < bin_lift[node].size())
        return bin_lift[node][pow_2];
    else if (pow_2 < bin_lift[node].size())
        return get_kth_parrent(bin_lift[node][pow_2], kth_parrent - powl_);
    else
        return -1;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> q;
    vector<ll> dumv(31);
    bin_lift.assign(n + 1, dumv);
    vector<vector<ll>> graph(n + 1), graph_t(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        bin_lift[i][0] = a;
        graph[i].push_back(a);
        graph_t[a].push_back(i);
    }
    prev_solve(n, graph, graph_t);
    bin_lift_func(n);
    for (i = 1; i <= q; i++)
    {
        cin >> a >> b;
        if (b > n)
        {
            a = get_kth_parrent(a, n);
            b -= n;
            b %= mp[a];
        }
        cout << get_kth_parrent(a, b) << endl;
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