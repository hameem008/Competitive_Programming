#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll all_xor;
vector<ll> cnt;
vector<ll> subtree_xor;
vector<ll> v;
void govire_jao(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    ll node_xor = v[vertex];
    ll node_cnt = 0;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            govire_jao(x, graph, isVisited);
            node_xor ^= subtree_xor[x];
            node_cnt += cnt[x];
            if (subtree_xor[x] == all_xor)
                node_cnt++;
        }
    }
    cnt[vertex] = node_cnt;
    subtree_xor[vertex] = node_xor;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag = false;
    // solve starts
    cin >> n >> k;
    cnt.clear();
    cnt.assign(n + 1, 0);
    subtree_xor.clear();
    subtree_xor.assign(n + 1, 0);
    v.clear();
    v.assign(n + 1, 0);
    all_xor = 0;
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
        all_xor ^= v[i];
    }
    vector<vector<ll>> graph(n + 1);
    for (i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if (all_xor == 0)
    {
        cout << "YES" << endl;
    }
    else if (k == 2)
    {
        cout << "NO" << endl;
    }
    else
    {
        vector<bool> isVisited(n + 1, false);
        govire_jao(1, graph, isVisited);
        ll cut_node;
        for (i = 1; i <= n; i++)
        {
            if (subtree_xor[i] == all_xor && cnt[i] == 0)
                cut_node = i;
        }
        isVisited.clear();
        isVisited.assign(n + 1, false);
        isVisited[cut_node] = true;
        v[cut_node] = 0;
        cnt.clear();
        cnt.assign(n + 1, 0);
        subtree_xor.clear();
        subtree_xor.assign(n + 1, 0);
        govire_jao(1, graph, isVisited);
        for (i = 1; i <= n; i++)
        {
            if (subtree_xor[i] == all_xor && cnt[i] == 0)
                flag = true;
        }
        flag ? cout << "YES" << endl : cout << "NO" << endl;
    }
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