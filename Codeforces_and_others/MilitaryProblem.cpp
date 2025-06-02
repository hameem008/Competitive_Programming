#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<ll> subCnt;
vector<ll> visitList;
void dfs(ll vertex, vector<set<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    visitList.push_back(vertex);
    ll cnt = 0;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
            cnt++;
            cnt += subCnt[x];
        }
    }
    subCnt[vertex] = cnt;
}

void solve(int I, int T)
{
    ll i, j, u, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> q;
    vector<set<ll>> graph(n + 1);
    subCnt.assign(n + 1, 0);
    visitList.clear();
    for (i = 2; i <= n; i++)
    {
        cin >> a;
        graph[a].insert(i);
    }
    vector<bool> isVIsited(n + 1, false);
    dfs(1, graph, isVIsited);
    vector<ll> pos(n + 1, 0);
    for (i = 0; i < visitList.size(); i++)
    {
        pos[visitList[i]] = i;
    }
    for (i = 1; i <= q; i++)
    {
        cin >> u >> k;
        if (subCnt[u] < k - 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << visitList[pos[u] + k - 1] << endl;
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}