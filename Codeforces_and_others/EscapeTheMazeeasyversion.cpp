#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p;
    bool flag;
    // solve starts
    cin >> n >> k;
    queue<ll> q;
    vector<ll> min_dist(n + 1);
    vector<vector<ll>> graph(n + 1);
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= k; i++)
    {
        cin >> a;
        q.push(a);
        min_dist[a] = 0;
        isVisited[a] = true;
    }
    for (i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    while (q.size())
    {
        ll vertex = q.front();
        q.pop();
        for (auto x : graph[vertex])
        {
            if (!isVisited[x])
            {
                min_dist[x] = min_dist[vertex] + 1;
                isVisited[x] = true;
                q.push(x);
            }
        }
    }
    isVisited.clear();
    isVisited.assign(n + 1, false);
    vector<ll> dist(n + 1);
    dist[1] = 0;
    q.push(1);
    isVisited[1] = true;
    while (q.size())
    {
        ll vertex = q.front();
        q.pop();
        for (auto x : graph[vertex])
        {
            if (!isVisited[x])
            {
                dist[x] = dist[vertex] + 1;
                isVisited[x] = true;
                q.push(x);
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (i != 1 && dist[i] < min_dist[i] && graph[i].size() == 1)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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