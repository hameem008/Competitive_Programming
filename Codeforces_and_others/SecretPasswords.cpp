#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    if (isVisited[vertex])
        return;
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
        dfs(x, graph, isVisited);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<vector<ll>> graph(26);
    vector<bool> isVisited(26, false);
    vector<bool> isPresent(26, false);
    bool done[26][26];
    for (i = 0; i < 26; i++)
    {
        for (j = 0; j < 26; j++)
        {
            done[i][j] = false;
        }
    }
    string str;
    for (i = 0; i < n; i++)
    {
        cin >> str;
        for (auto x : str)
            for (auto y : str)
            {
                if (x != y && !done[x - 'a'][y - 'a'])
                {
                    graph[x - 'a'].push_back(y - 'a');
                    graph[y - 'a'].push_back(x - 'a');
                    isPresent[x - 'a'] = true;
                    isPresent[y - 'a'] = true;
                    done[x - 'a'][y - 'a'] = true;
                    done[y - 'a'][x - 'a'] = true;
                }
                else
                    isPresent[x - 'a'] = true;
            }
    }
    ll ans = 0;
    for (i = 0; i < 26; i++)
    {
        if (isPresent[i])
        {
            if (!isVisited[i])
            {
                ans++;
                dfs(i, graph, isVisited);
            }
        }
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}