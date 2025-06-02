#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<ll> nodes;
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    nodes.push_back(vertex);
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
        }
    }
}

ll func(vector<ll> bnodes, ll k, vector<ll> arr)
{
    ll b_max = 0;
    ll add = 0;
    for (int i = 0; i < bnodes.size(); i++)
    {
        ll mul = k - i;
        if (mul > 0)
        {
            ll ans = arr[bnodes[i]] * mul + add;
            b_max = max(b_max, ans);
        }
        add += arr[bnodes[i]];
    }
    return b_max;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    ll pb, ps;
    cin >> n >> k >> pb >> ps;
    vector<ll> perm(n + 1);
    for (i = 1; i <= n; i++)
        cin >> perm[i];
    vector<ll> arr(n + 1);
    for (i = 1; i <= n; i++)
        cin >> arr[i];
    vector<vector<ll>> grpah(n + 1);
    for (i = 1; i <= n; i++)
    {
        grpah[i].push_back(perm[i]);
    }
    vector<bool> isVisited(n + 1, false);
    nodes.clear();
    dfs(pb, grpah, isVisited);
    vector<ll> bnodes = nodes;
    nodes.clear();
    isVisited.assign(n + 1, false);
    dfs(ps, grpah, isVisited);
    vector<ll> snodes = nodes;
    ll b_max = func(bnodes, k, arr);
    ll s_max = func(snodes, k, arr);
    if (b_max > s_max)
        cout << "Bodya" << endl;
    else if (b_max < s_max)
        cout << "Sasha" << endl;
    else
        cout << "Draw" << endl;
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