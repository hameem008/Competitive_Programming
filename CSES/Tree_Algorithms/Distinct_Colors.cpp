#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<set<ll>> vs;
vector<ll> ans;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
            if (vs[vertex].size() < vs[x].size())
            {
                for (auto x : vs[vertex])
                    vs[x].insert(x);
                swap(vs[vertex], vs[x]);
            }
            else
            {
                for (auto x : vs[x])
                    vs[vertex].insert(x);
            }
        }
    }
    ans[vertex] = vs[vertex].size();
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    set<ll> s;
    vs.assign(n + 1, s);
    ans.assign(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        vs[i].insert(a);
    }
    vector<vector<ll>> graph(n + 1);
    for (i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> isVisited(n + 1, false);
    dfs(1, graph, isVisited);
    for (i = 1; i <= n; i++)
    {
        cout << ans[i] << gap;
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