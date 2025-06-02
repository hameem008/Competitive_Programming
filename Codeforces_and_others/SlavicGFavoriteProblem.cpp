#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

set<ll> sw;
ll b;
bool flag;

void dfsb(ll vertex, vector<vector<pair<ll, ll>>> &graph, vector<bool> &isVIsited, ll x_var)
{
    isVIsited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVIsited[x.first])
        {
            sw.insert(x.second ^ x_var);
            dfsb(x.first, graph, isVIsited, x_var ^ x.second);
        }
    }
}

void dfsa(ll vertex, vector<vector<pair<ll, ll>>> &graph, vector<bool> &isVIsited, ll x_var)
{
    if (sw.find(x_var) != sw.end())
        flag = true;
    isVIsited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVIsited[x.first] && x.first != b)
        {
            dfsa(x.first, graph, isVIsited, x_var ^ x.second);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, c, d, m, n, p, q, w;
    sw.clear();
    flag = false;
    // solve starts
    cin >> n >> a >> b;
    vector<pair<ll, ll>> dum;
    vector<vector<pair<ll, ll>>> graph(n + 1, dum);
    vector<bool> isVisited(n + 1, false);
    for (i = 0; i < n - 1; i++)
    {
        cin >> p >> q >> w;
        graph[p].push_back({q, w});
        graph[q].push_back({p, w});
    }
    dfsb(b, graph, isVisited, 0);
    isVisited.clear();
    isVisited.assign(n + 1, false);
    dfsa(a, graph, isVisited, 0);
    flag ? cout << "YES" << endl : cout << "NO" << endl;
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