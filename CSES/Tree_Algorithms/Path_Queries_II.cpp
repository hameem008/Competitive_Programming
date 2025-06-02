#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef int ll;
typedef long double lld;

template <class T>
class segment_tree
{
private:
    ll N = 0;
    vector<T> t;
    ll root = 1;
    ll tla = 0, tra = 0;
    T combine(T a, T b)
    {
        return max(a, b);
    }
    void build(vector<T> &a, ll v, ll tl, ll tr)
    {
        if (tl == tr)
            t[v] = a[tl];
        else
        {
            ll tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    T query(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (l > r)
            return INT32_MIN;
        if (l == tl && r == tr)
            return t[v];
        ll tm = (tl + tr) / 2;
        T a = query(v * 2, tl, tm, l, min(r, tm));
        T b = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(a, b);
    }
    void update(ll v, ll tl, ll tr, ll pos, T new_val)
    {
        if (tl == tr)
            t[v] = new_val;
        else
        {
            ll tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }

public:
    segment_tree()
    {
    }
    segment_tree(vector<T> &a)
    {
        build(a);
    }
    void build(vector<T> &a)
    {
        if (N)
            clear();
        N = a.size() + 1;
        tla = 0, tra = a.size() - 1;
        t.assign(4 * N, 0);
        build(a, 1, tla, tra);
    }
    T query(ll l, ll r)
    {
        return query(root, tla, tra, l, r);
    }
    void update(ll pos, T new_val)
    {
        update(root, tla, tra, pos, new_val);
    }
    void clear()
    {
        N = 0, tra = 0, tla = 0;
    }
    ~segment_tree()
    {
        if (N)
            clear();
    }
};

pair<ll, ll> func(ll n)
{
    ll k;
    k = log2(n);
    pair<ll, ll> ret = {k, powl(2, k)};
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
    while (1)
    {
        pair<ll, ll> pr = func(kth_parrent);
        ll pow_2 = pr.first;
        ll powl_ = pr.second;
        if (powl_ == kth_parrent && pow_2 < bin_lift[node].size())
            return bin_lift[node][pow_2];
        else if (pow_2 < bin_lift[node].size())
        {
            node = bin_lift[node][pow_2];
            kth_parrent -= powl_;
        }
        else
            return -1;
    }
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

vector<ll> subtree_size;
vector<ll> parrent;
vector<ll> max_subtree_size;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    ll mx_subtree_sz = 0;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
            subtree_size[vertex] += subtree_size[x];
            parrent[x] = vertex;
            if (mx_subtree_sz < subtree_size[x])
            {
                max_subtree_size[vertex] = x;
                mx_subtree_sz = subtree_size[x];
            }
        }
    }
}
vector<vector<ll>> sgv;
vector<pair<ll, ll>> info;
void dfs_2(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, ll &ind)
{
    isVisited[vertex] = true;
    ll max_sbtreenode = max_subtree_size[vertex];
    if (max_sbtreenode)
    {
        info[max_sbtreenode].first = ind;
        info[max_sbtreenode].second = sgv[ind].size();
        sgv[ind].push_back(max_sbtreenode);
        dfs_2(max_sbtreenode, graph, isVisited, ind);
    }
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            info[x].first = ind;
            info[x].second = sgv[ind].size();
            sgv[ind].push_back(x);
            dfs_2(x, graph, isVisited, ind);
        }
    }
    if (graph[vertex].size() == 1 && graph[vertex].front() == parrent[vertex])
    {
        ind++;
    }
}
vector<segment_tree<ll>> vec_of_sg;
void HLD_preprocessing(vector<vector<ll>> &graph, vector<ll> &valv, ll n, ll root)
{
    sgv.assign(n + 1, vector<ll>(0));
    subtree_size.assign(n + 1, 1);
    max_subtree_size.assign(n + 1, 0);
    parrent.assign(n + 1, 0);
    info.assign(n + 1, make_pair(0, 0));
    vector<bool> isVisited(n + 1, false);
    dfs(root, graph, isVisited);
    isVisited.assign(n + 1, false);
    ll ind = 0;
    sgv[ind].push_back(root);
    dfs_2(root, graph, isVisited, ind);
    for (auto x : sgv)
    {
        if (x.size() == 0)
            continue;
        vector<ll> vec = x;
        for (ll i = 0; i < vec.size(); i++)
        {
            vec[i] = valv[vec[i]];
        }
        segment_tree<ll> sg(vec);
        vec_of_sg.push_back(sg);
    }
}
ll HLD_query(ll a, ll b)
{
    ll lca = least_common_ancestor(a, b);
    ll qr = 0;
    bool flag_a = true, flag_b = true;
    while (flag_a || flag_b)
    {
        if (flag_a)
        {
            ll sg_a = info[a].first, sg_lca = info[lca].first;
            if (sg_a == sg_lca)
            {
                qr = max(qr, vec_of_sg[sg_a].query(info[lca].second, info[a].second));
                flag_a = false;
            }
            else
            {
                qr = max(qr, vec_of_sg[sg_a].query(0, info[a].second));
                a = parrent[sgv[sg_a][0]];
            }
        }
        if (flag_b)
        {
            ll sg_b = info[b].first, sg_lca = info[lca].first;
            if (sg_b == sg_lca)
            {
                qr = max(qr, vec_of_sg[sg_b].query(info[lca].second, info[b].second));
                flag_b = false;
            }
            else
            {
                qr = max(qr, vec_of_sg[sg_b].query(0, info[b].second));
                b = parrent[sgv[sg_b][0]];
            }
        }
    }
    return qr;
}

void HLD_update(ll node, ll val)
{
    ll sg_node = info[node].first;
    ll pos = info[node].second;
    vec_of_sg[sg_node].update(pos, val);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    vector<vector<ll>> graph(n + 1), graph_2(n + 1);
    for (i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    pre_processing(n, graph, 1);
    HLD_preprocessing(graph, v, n, 1);
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            HLD_update(b, c);
        }
        else if (a == 2)
        {
            cout << HLD_query(b, c) << gap;
        }
    }
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