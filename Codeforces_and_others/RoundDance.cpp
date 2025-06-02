#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

bool bare_hand_flag;

void dfs(ll vertex, vector<set<ll>> &graph, vector<bool> &isVIsited)
{
    isVIsited[vertex] = true;
    if (graph[vertex].size() == 1)
        bare_hand_flag = true;
    for (auto x : graph[vertex])
    {
        if (!isVIsited[x])
        {
            dfs(x, graph, isVIsited);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<set<ll>> graph(n + 1);
    for (i = 1; i <= n; i++)
    {
        graph[i].insert(v[i]);
        graph[v[i]].insert(i);
    }
    ll comp_cnt = 0, bare_hand_cnt = 0;
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            comp_cnt++;
            bare_hand_flag = false;
            dfs(i, graph, isVisited);
            if (bare_hand_flag)
                bare_hand_cnt++;
        }
    }
    ll max_ans = comp_cnt, min_ans = comp_cnt;
    if (bare_hand_cnt)
        min_ans = comp_cnt - bare_hand_cnt + 1;
    cout << min_ans << gap << max_ans << endl;
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