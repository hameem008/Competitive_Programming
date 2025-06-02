#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> height_big;
vector<ll> height_small;
void dfs_1(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs_1(x, graph, isVisited);
            if (height_big[x] + 1 >= height_big[vertex])
            {
                height_small[vertex] = height_big[vertex];
                height_big[vertex] = 1 + height_big[x];
            }
            else if (height_big[x] + 1 >= height_small[vertex])
            {
                height_small[vertex] = 1 + height_big[x];
            }
        }
    }
}

vector<ll> ans_same_subtree;
vector<ll> ans_diff_subtree;
vector<bool> done;

void dfs_2(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, ll parrent)
{
    isVisited[vertex] = true;
    if (!done[vertex])
    {
        ll a = 0, b = 0;
        if (height_big[vertex] + 1 == height_big[parrent])
        {
            a = 1 + height_small[parrent];
        }
        else
        {
            a = 1 + height_big[parrent];
        }
        b = 1 + ans_diff_subtree[parrent];
        ans_same_subtree[vertex] = height_big[vertex];
        ans_diff_subtree[vertex] = max(a, b);
        done[vertex] = true;
    }
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs_2(x, graph, isVisited, vertex);
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    height_big.assign(n + 1, 0);
    height_small.assign(n + 1, 0);
    vector<vector<ll>> graph(n + 1);
    for (i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> isVisited(n + 1, false);
    dfs_1(1, graph, isVisited);
    ans_same_subtree.assign(n + 1, 0);
    ans_diff_subtree.assign(n + 1, 0);
    done.assign(n + 1, false);
    ans_same_subtree[1] = height_big[1];
    done[1] = true;
    for (auto x : graph[1])
    {
        done[x] = true;
        ans_same_subtree[x] = height_big[x];
        if (height_big[x] + 1 == height_big[1])
        {
            ans_diff_subtree[x] = 1 + height_small[1];
        }
        else
        {
            ans_diff_subtree[x] = 1 + height_big[1];
        }
    }
    isVisited.clear();
    isVisited.assign(n + 1, false);
    dfs_2(1, graph, isVisited, 0);
    for (i = 1; i <= n; i++)
    {
        cout << max(ans_same_subtree[i], ans_diff_subtree[i]) << gap;
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