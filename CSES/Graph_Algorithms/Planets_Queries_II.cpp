#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll time_ = 0;
vector<ll> start_t, end_t;
void scc_dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    time_++;
    start_t[vertex] = time_;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            scc_dfs(x, graph, isVisited);
        }
    }
    time_++;
    end_t[vertex] = time_;
}
vector<ll> nodes;
void scc_dfs_2(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    nodes.push_back(vertex);
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            scc_dfs_2(x, graph, isVisited);
        }
    }
}
vector<vector<ll>> all_scc;
vector<ll> map_scc_index;
vector<ll> index_in_scc;
void strongly_connnected_components(ll n, vector<pair<ll, ll>> &edge_list)
{
    ll i, j;
    start_t.assign(n + 1, 0);
    end_t.assign(n + 1, 0);
    map_scc_index.assign(n + 1, 0);
    index_in_scc.assign(n + 1, 0);
    vector<vector<ll>> graph(n + 1), graph_t(n + 1);
    for (auto x : edge_list)
    {
        graph[x.first].push_back(x.second);
        graph_t[x.second].push_back(x.first);
    }
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            scc_dfs(i, graph, isVisited);
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
    all_scc.push_back(vector<ll>(0));
    i = 1;
    for (auto x : vp)
    {
        if (!isVisited[x.second])
        {
            nodes.clear();
            scc_dfs_2(x.second, graph_t, isVisited);
            reverse(nodes.begin(), nodes.end());
            all_scc.push_back(nodes);
            for (j = 0; j < nodes.size(); j++)
            {
                map_scc_index[nodes[j]] = i;
                index_in_scc[nodes[j]] = j;
            }
            i++;
        }
    }
}

vector<ll> nearest_door;
ll time_tt = 0;
vector<ll> start_tt, end_tt;
vector<ll> level_of;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, ll level)
{
    isVisited[vertex] = true;
    time_tt++;
    start_tt[vertex] = time_tt;
    level_of[vertex] = level;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            nearest_door[x] = nearest_door[vertex];
            dfs(x, graph, isVisited, level + 1);
        }
    }
    time_tt++;
    end_tt[vertex] = time_tt;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    nearest_door.assign(n + 1, 0);
    vector<ll> parrent(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        nearest_door[i] = i;
        parrent[i] = i;
    }
    start_tt.assign(n + 1, 0);
    end_tt.assign(n + 1, 0);
    level_of.assign(n + 1, 0);
    vector<pair<ll, ll>> edge_list;
    for (a = 1; a <= n; a++)
    {
        cin >> b;
        if (a != b)
            edge_list.push_back({a, b});
    }
    strongly_connnected_components(n, edge_list);
    vector<vector<ll>> graph(n + 1);
    for (auto x : edge_list)
    {
        graph[x.second].push_back(x.first);
        parrent[x.first] = x.second;
    }
    vector<bool> isVisited(n + 1, false);
    for (auto x : all_scc)
    {
        for (auto y : x)
            if (x.size() > 1)
                isVisited[y] = true;
    }
    for (i = 1; i <= n; i++)
    {
        c = map_scc_index[i];
        if (all_scc[c].size() > 1)
        {
            nearest_door[i] = i;
            dfs(i, graph, isVisited, 0);
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            if (i == parrent[i] && graph[i].size() > 0)
            {
                nearest_door[i] = i;
                dfs(i, graph, isVisited, 0);
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (start_tt[i] == 0 && end_tt[i] == 0)
        {
            isVisited[i] = true;
            time_tt++;
            start_tt[i] = time_tt;
            time_tt++;
            end_tt[i] = time_tt;
        }
    }
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        ll qr = -1;
        if (map_scc_index[a] == map_scc_index[b])
        {
            ll ind_a = index_in_scc[a], ind_b = index_in_scc[b];
            if (ind_a < ind_b)
            {
                qr = ind_b - ind_a;
            }
            else if (ind_a > ind_b)
            {
                qr = ind_b - ind_a + all_scc[map_scc_index[a]].size();
            }
            else
            {
                qr = 0;
            }
        }
        else if (map_scc_index[b] == map_scc_index[nearest_door[a]])
        {
            ll lv = level_of[a];
            a = nearest_door[a];
            ll ind_a = index_in_scc[a], ind_b = index_in_scc[b];
            if (ind_a < ind_b)
            {
                qr = ind_b - ind_a;
            }
            else if (ind_a > ind_b)
            {
                qr = ind_b - ind_a + all_scc[map_scc_index[a]].size();
            }
            else
            {
                qr = 0;
            }
            qr += lv;
        }
        else if (start_tt[b] <= start_tt[a] && end_tt[a] <= end_tt[b])
        {
            qr = level_of[a] - level_of[b];
        }
        cout << qr << endl;
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