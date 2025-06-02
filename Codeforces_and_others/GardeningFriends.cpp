#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> dis;
void bfs(ll source, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    queue<ll> q;
    isVisited[source] = true;
    q.push(source);
    dis[source] = 0;
    while (q.size())
    {
        ll vertex = q.front();
        q.pop();
        for (auto x : graph[vertex])
        {
            if (!isVisited[x])
            {
                q.push(x);
                isVisited[x] = true;
                dis[x] = dis[vertex] + 1;
            }
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k >> c;
    vector<vector<ll>> graph(n + 1);
    vector<bool> isVisited(n + 1, false);
    for (i = 0; i < n - 1; i++)
    {
        cin >> p >> q;
        graph[p].push_back(q);
        graph[q].push_back(p);
    }
    dis.assign(n + 1, 0);
    bfs(1, graph, isVisited);
    vector<ll> dis_from_1(dis.begin(), dis.end());
    dis.clear();
    ll tro;
    ll max_dis = 0;
    for (i = 1; i <= n; i++)
    {
        if (dis_from_1[i] > max_dis)
        {
            max_dis = dis_from_1[i];
            tro = i;
        }
    }
    isVisited.clear();
    isVisited.assign(n + 1, false);
    dis.assign(n + 1, 0);
    bfs(tro, graph, isVisited);
    vector<ll> dis_from_tro(dis.begin(), dis.end());
    ll ans = 0;
    for (i = 1; i <= n; i++)
    {
        ans = max(ans, dis_from_tro[i] * k - dis_from_1[i] * c);
    }
    cout << ans << endl;
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