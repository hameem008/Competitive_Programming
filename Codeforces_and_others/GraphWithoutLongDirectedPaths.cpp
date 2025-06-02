#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> color;
bool flag;
void bfs(ll source, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    queue<ll> q;
    isVisited[source] = true;
    q.push(source);
    color[source] = 0;
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
                if (color[vertex] == 0)
                    color[x] = 1;
                else if (color[vertex] == 1)
                    color[x] = 0;
            }
            else
            {
                if ((color[vertex] + color[x]) % 2 == 0)
                    flag = false;
            }
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    flag = true;
    cin >> n >> m;
    vector<vector<ll>> graph(n + 1);
    color.assign(n + 1, 0);
    vector<pair<ll, ll>> vp;
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b;
        vp.push_back({a, b});
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> isVisited(n + 1, false);
    bfs(1, graph, isVisited);
    if (flag)
    {
        cout << "YES" << endl;
        for (auto x : vp)
        {
            if (color[x.first] == 0 && color[x.second] == 1)
                cout << 0;
            else if (color[x.first] == 1 && color[x.second] == 0)
                cout << 1;
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
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