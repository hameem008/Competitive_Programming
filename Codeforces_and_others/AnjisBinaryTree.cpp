#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

ll dfs(ll vertex, vector<pair<ll, ll>> &graph, vector<char> &signs)
{
    ll ans1 = infinite, ans2 = infinite;
    if (graph[vertex].first == 0 && graph[vertex].second == 0)
    {
        ans1 = ans2 = 0;
    }
    if (graph[vertex].first != 0)
    {
        ans1 = dfs(graph[vertex].first, graph, signs);
        if (signs[vertex] != 'R')
        {
            ans1++;
        }
    }
    if (graph[vertex].second != 0)
    {
        ans2 = dfs(graph[vertex].second, graph, signs);
        if (signs[vertex] != 'L')
        {
            ans2++;
        }
    }
    return min(ans1, ans2);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<char> signs(n + 1);
    for (i = 1; i <= n; i++)
        cin >> signs[i];
    vector<pair<ll, ll>> graph(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> a >> b;
        swap(a, b);
        graph[i].first = a;
        graph[i].second = b;
    }
    cout << dfs(1, graph, signs) << endl;
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