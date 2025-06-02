#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

bool isCycle = false;
void cycle(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<bool> &st)
{
    isVisited[vertex] = true;
    st[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            cycle(x, graph, isVisited, st);
        }
        else if (st[x] == true)
        {
            isCycle = true;
        }
    }
    st[vertex] = false;
}

vector<ll> end_time;
ll curr_time = 0;
void top_sort(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    curr_time++;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            top_sort(x, graph, isVisited);
        }
    }
    curr_time++;
    end_time[vertex] = curr_time;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag = false;
    // solve starts
    cin >> n >> k;
    end_time.assign(n + 1, 0);
    vector<vector<ll>> graph(n + 1);
    vector<bool> isVisited(n + 1, false);
    vector<bool> roots(n + 1, true);
    vector<bool> st(n + 1, false);
    for (i = 1; i <= k; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        roots[b] = false;
    }
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            cycle(i, graph, isVisited, st);
        }
    }
    isVisited.assign(n + 1, false);
    for (i = 1; i <= n; i++)
    {
        if (roots[i])
        {
            flag = true;
            if (!isVisited[i])
                top_sort(i, graph, isVisited);
        }
    }
    if (isCycle)
        flag = false;
    if (flag)
    {
        vector<pair<ll, ll>> vp;
        for (i = 1; i <= n; i++)
        {
            vp.push_back({end_time[i], i});
        }
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        for (auto x : vp)
        {
            cout << x.second << gap;
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
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