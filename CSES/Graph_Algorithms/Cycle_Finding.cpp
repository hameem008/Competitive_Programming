#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<ll> cycle;
bool isCyclePresent = false;
vector<ll> parrents_bellman_ford;
vector<ll> distance_bellman_ford;
void bellman_ford(vector<pair<pair<ll, ll>, ll>> &edge_list, ll source, ll n)
{
    parrents_bellman_ford.clear();
    distance_bellman_ford.clear();
    parrents_bellman_ford.assign(n + 1, -1);
    distance_bellman_ford.assign(n + 1, 99999999);
    parrents_bellman_ford[source] = source;
    distance_bellman_ford[source] = 0;
    ll limit = n - 1;
    while (limit--)
    {
        for (auto x : edge_list)
        {
            if (distance_bellman_ford[x.first.first] + x.second < distance_bellman_ford[x.first.second])
            {
                distance_bellman_ford[x.first.second] = distance_bellman_ford[x.first.first] + x.second;
                parrents_bellman_ford[x.first.second] = x.first.first;
            }
        }
    }
    vector<ll> check = distance_bellman_ford;
    for (auto x : edge_list)
    {
        if (distance_bellman_ford[x.first.first] + x.second < distance_bellman_ford[x.first.second])
        {
            distance_bellman_ford[x.first.second] = distance_bellman_ford[x.first.first] + x.second;
            parrents_bellman_ford[x.first.second] = x.first.first;
        }
    }
    if (check != distance_bellman_ford)
        isCyclePresent = true;
    if (isCyclePresent)
    {
        ll vertex;
        for (ll i = 1; i <= n; i++)
        {
            if (check[i] != distance_bellman_ford[i])
            {
                vertex = i;
                break;
            }
        }
        limit = 2 * n;
        while (limit--)
        {
            for (auto x : edge_list)
            {
                if (distance_bellman_ford[x.first.first] + x.second < distance_bellman_ford[x.first.second])
                {
                    distance_bellman_ford[x.first.second] = distance_bellman_ford[x.first.first] + x.second;
                    parrents_bellman_ford[x.first.second] = x.first.first;
                }
            }
        }
        vector<ll> path;
        vector<bool> isDone(n + 1, false);
        while (1)
        {
            path.push_back(vertex);
            if (isDone[vertex])
                break;
            isDone[vertex] = true;
            vertex = parrents_bellman_ford[vertex];
        }
        isDone.assign(n + 1, false);
        reverse(path.begin(), path.end());
        for (auto x : path)
        {
            cycle.push_back(x);
            if (isDone[x])
            {
                break;
            }
            isDone[x] = true;
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<pair<pair<ll, ll>, ll>> edge_list;
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b >> k;
        edge_list.push_back({{a, b}, k});
    }
    for (i = 1; i <= n; i++)
    {
        edge_list.push_back({{n + 1, i}, 0});
    }
    n++;
    bellman_ford(edge_list, n, n);
    if (isCyclePresent)
    {
        cout << "YES" << endl;
        for (auto x : cycle)
            cout << x << gap;
        cout << endl;
    }
    else
        cout << "NO" << endl;
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