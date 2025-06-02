#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll dp[2][2][1000000];
ll n;
ll dfs(ll vertex, vector<vector<pair<ll, ll>>> &graph, ll currState, ll direction)
{
    if (dp[direction][currState][vertex] != 0)
        return dp[direction][currState][vertex];
    ll sum = 1;
    if (graph[vertex].size() == 1)
    {
        pair<ll, ll> pa = graph[vertex][0];
        if (pa.first < vertex && direction == 0 && pa.second == currState)
        {
            sum += dfs(pa.first, graph, currState ? 0 : 1, direction);
        }
        else if (pa.first > vertex && direction == 1 && pa.second == currState)
        {
            sum += dfs(pa.first, graph, currState ? 0 : 1, direction);
        }
    }
    else if (graph[vertex].size() == 2)
    {
        pair<ll, ll> pa = graph[vertex][0], pb = graph[vertex][1];
        if (pa.first < vertex && direction == 0 && pa.second == currState)
        {
            sum += dfs(pa.first, graph, currState ? 0 : 1, direction);
        }
        else if (pa.first > vertex && direction == 1 && pa.second == currState)
        {
            sum += dfs(pa.first, graph, currState ? 0 : 1, direction);
        }

        if (pb.first < vertex && direction == 0 && pb.second == currState)
        {
            sum += dfs(pb.first, graph, currState ? 0 : 1, direction);
        }
        else if (pb.first > vertex && direction == 1 && pb.second == currState)
        {
            sum += dfs(pb.first, graph, currState ? 0 : 1, direction);
        }
    }
    return dp[direction][currState][vertex] = sum;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, p, q;
    bool flag;
    // solve starts
    cin >> n;
    string str;
    str.push_back('a');
    for (i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;
        str.push_back(ch);
    }
    vector<vector<pair<ll, ll>>> graph(n + 1);
    i = 0;
    dp[0][0][i] = dp[0][1][i] = dp[1][0][i] = dp[1][1][i] = 0;
    for (i = 1; i <= n; i++)
    {
        dp[0][0][i] = dp[0][1][i] = dp[1][0][i] = dp[1][1][i] = 0;
        if (str[i] == 'L')
        {
            graph[i].push_back({i - 1, 1});
            graph[i - 1].push_back({i, 0});
        }
        else if (str[i] == 'R')
        {
            graph[i - 1].push_back({i, 1});
            graph[i].push_back({i - 1, 0});
        }
    }
    for (i = 0; i <= n; i++)
    {
        if (dp[0][1][i] == 0)
            dfs(i, graph, 1, 0);
        if (dp[1][1][i] == 0)
            dfs(i, graph, 1, 1);
    }
    for (i = 0; i <= n; i++)
    {
        ll out = dp[0][1][i] + dp[1][1][i] - 1;
        cout << out << gap;
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}