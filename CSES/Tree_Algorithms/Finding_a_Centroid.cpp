#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> max_cnt;
vector<ll> total_cnt;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
            total_cnt[vertex] += total_cnt[x];
            max_cnt[vertex] = max(max_cnt[vertex], total_cnt[x]);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    max_cnt.assign(n + 1, 0);
    total_cnt.assign(n + 1, 1);
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
        ll val = max(max_cnt[i], n - total_cnt[i]);
        if (val <= n / 2)
        {
            cout << i << endl;
            break;
        }
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    //  cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}