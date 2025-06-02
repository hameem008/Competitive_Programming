#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<ll> dis_node_cnt;
void node_cnt(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    dis_node_cnt[vertex] = 1;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            node_cnt(x, graph, isVisited);
            dis_node_cnt[vertex] += dis_node_cnt[x];
        }
    }
}

vector<vector<ll>> dp;
ll rec(ll i, ll sum, vector<ll> &v, vector<ll> &presum)
{
    if (i == 0)
        return 0;
    if (dp[i][sum] == -1)
    {
        ll ans = 0;
        for (ll j = max(0LL, sum - presum[i - 1]); j <= min(sum, v[i]); j++)
        {
            ans = max(ans, rec(i - 1, sum - j, v, presum) + (v[i] - j) * (sum - j) + j * (presum[i - 1] - (sum - j)));
        }
        dp[i][sum] = ans;
    }
    return dp[i][sum];
}

ll fun(vector<ll> &in)
{
    vector<ll> v;
    v.push_back(0);
    for (auto x : in)
        v.push_back(x);
    vector<ll> presum;
    ll ps = 0;
    for (auto x : v)
    {
        ps += x;
        presum.push_back(ps);
    }
    ll n = in.size();
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    dp.clear();
    dp.assign(n + 1, vector<ll>(sum + 1, -1));
    ll ans = 0;
    for (ll i = 0; i <= sum; i++)
    {
        ans = max(ans, rec(n, i, v, presum));
    }
    return ans;
}

vector<ll> ans;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    vector<ll> v;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
            v.push_back(dis_node_cnt[x]);
            ans[vertex] += ans[x];
        }
    }
    ans[vertex] += fun(v);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    dis_node_cnt.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    vector<vector<ll>> graph(n + 1);
    for (i = 2; i <= n; i++)
    {
        cin >> a;
        graph[a].push_back(i);
        graph[i].push_back(a);
    }
    vector<bool> isVisited(n + 1, false);
    node_cnt(1, graph, isVisited);
    isVisited.assign(n + 1, false);
    dfs(1, graph, isVisited);
    cout << ans[1] << endl;
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