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
void bin_lift_func(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<ll> parv, ll level)
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
            bin_lift_func(x, graph, isVisited, bin_lift[vertex], level + 1);
        }
    }
}
ll get_kth_parrent(ll node, ll kth_parrent)
{
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
vector<ll> start_time, end_time, level_of;
ll time_ = 0;
void calc_time(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, ll level)
{
    isVisited[vertex] = true;
    level_of[vertex] = level;
    time_++;
    start_time[vertex] = time_;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            calc_time(x, graph, isVisited, level + 1);
        }
    }
    time_++;
    end_time[vertex] = time_;
}
ll least_common_ancestor(ll u, ll v)
{
    if (start_time[u] <= start_time[v] && end_time[u] >= end_time[v])
        return u;
    else if (start_time[v] <= start_time[u] && end_time[v] >= end_time[u])
        return v;
    ll lca;
    lca = u;
    while (1)
    {
        ll dum;
        for (int i = 0; i < bin_lift[lca].size(); i++)
        {
            ll k = bin_lift[lca][i];
            if (start_time[k] < start_time[v] && end_time[k] > end_time[v])
            {
                if (i == 0)
                {
                    return k;
                }
                else
                {
                    break;
                }
            }
            else
                dum = k;
        }
        lca = dum;
    }
    return lca;
}
void init(ll n)
{
    vector<ll> v;
    bin_lift.assign(n + 1, v);
    next_child.assign(n + 1, 0);
    start_time.assign(n + 1, 0);
    end_time.assign(n + 1, 0);
    level_of.assign(n + 1, 0);
}
void pre_processing(ll number_of_nodes, vector<vector<ll>> &graph, ll root)
{
    init(number_of_nodes);
    vector<bool> isVIsited(number_of_nodes + 1, false);
    vector<ll> v;
    bin_lift_func(root, graph, isVIsited, v, 0);
    isVIsited.assign(number_of_nodes + 1, false);
    calc_time(root, graph, isVIsited, 0);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> q;
    vector<vector<ll>> graph(n + 1);
    for (i = 2; i <= n; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    pre_processing(n, graph, 1);
    for (i = 1; i <= q; i++)
    {
        cin >> a >> b;
        ll lca = least_common_ancestor(a, b);
        cout << level_of[a] + level_of[b] - 2 * level_of[lca] << endl;
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