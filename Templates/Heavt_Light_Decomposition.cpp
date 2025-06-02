// add segment tree and least common ancestor
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