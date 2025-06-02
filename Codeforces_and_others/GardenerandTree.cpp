#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<set<ll>> graph(n + 1);
    set<ll> trim, allNodes = {n};
    vector<pair<ll, ll>> vp;
    for (i = 0; i < n - 1; i++)
    {
        allNodes.insert(i + 1);
        cin >> p >> q;
        vp.push_back({p, q});
        graph[p].insert(q);
        graph[q].insert(p);
    }
    for (i = 1; i <= n; i++)
    {
        if (graph[i].size() == 1 || graph[i].size() == 0)
            trim.insert(i);
    }
    while (trim.size() != 0 && k--)
    {
        set<ll> temp_trim;
        for (auto x : trim)
        {
            allNodes.erase(x);
            auto it = graph[x].begin();
            if (it != graph[x].end())
            {
                temp_trim.insert(*it);
                graph[*it].erase(x);
            }
        }
        trim.clear();
        for (auto x : temp_trim)
        {
            if (graph[x].size() == 1 || graph[x].size() == 0)
                trim.insert(x);
        }
    }
    cout << allNodes.size() << endl;
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