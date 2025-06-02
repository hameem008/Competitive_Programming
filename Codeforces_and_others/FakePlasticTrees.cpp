#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<pair<ll, ll>> rangep;
vector<ll> num;
ll ans;

ll dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVIsited)
{
    isVIsited[vertex] = true;
    ll curr = rangep[vertex].second - num[vertex];
    ll sum_curr = 0;
    for (auto x : graph[vertex])
    {
        if (!isVIsited[x])
        {
            curr = dfs(x, graph, isVIsited);
            ll need = rangep[vertex].second - num[vertex];
            if (need <= curr)
            {
                num[vertex] += need;
                curr = need;
            }
            else
            {
                num[vertex] += curr;
            }
            sum_curr += curr;
        }
    }
    if (num[vertex] >= rangep[vertex].first && num[vertex] <= rangep[vertex].second)
    {
    }
    else
    {
        ans++;
        sum_curr += rangep[vertex].second - num[vertex];
    }
    return sum_curr;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    ans = 0;
    cin >> n;
    vector<vector<ll>> graph(n + 1);
    vector<bool> isVisited(n + 1, false);
    for (i = 2; i <= n; i++)
    {
        cin >> a;
        graph[a].push_back(i);
        graph[i].push_back(a);
    }
    rangep.clear();
    rangep.assign(n + 1, {0, 0});
    num.clear();
    num.assign(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> rangep[i].first >> rangep[i].second;
    }
    dfs(1, graph, isVisited);
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