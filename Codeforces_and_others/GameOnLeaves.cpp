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
    for (i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    if (n == 1)
    {
        cout << "Ayush" << endl;
        return;
    }
    string winner = "Ayush";
    flag = true;
    ll limit = n + 1;
    while (limit--)
    {
        set<ll> leaves;
        bool ok = false;
        for (i = 1; i <= n; i++)
        {
            if (graph[i].size() == 1)
                leaves.insert(i);
        }
        if (leaves.find(k) != leaves.end())
        {
            flag ? winner = "Ayush" : winner = "Ashish";
            break;
        }
        if (leaves.size() % 2 == 0)
        {
            if (graph[k].size() == 2)
            {
                for (auto x : graph[k])
                    leaves.erase(x);
            }
            if (leaves.size() == 0)
            {
                flag ? winner = "Ashish" : winner = "Ayush";
                break;
            }
            else
            {
                for (auto x : leaves)
                {
                    ll par = *graph[x].begin();
                    if (graph[par].size() == 2)
                    {
                        graph[par].erase(x);
                        graph[x].erase(par);
                        ok = true;
                        break;
                    }
                }
                if (!ok)
                {
                    ll node = *leaves.begin();
                    ll par = *graph[node].begin();
                    graph[node].erase(par);
                    graph[par].erase(node);
                }
            }
        }
        else
        {
            for (auto x : leaves)
            {
                ll par = *graph[x].begin();
                if (graph[par].size() > 2)
                {
                    graph[par].erase(x);
                    graph[x].erase(par);
                    ok = true;
                    break;
                }
            }
            if (!ok)
            {
                ll node = *leaves.begin();
                ll par = *graph[node].begin();
                graph[node].erase(par);
                graph[par].erase(node);
            }
        }
        flag ? flag = false : flag = true;
    }
    cout << winner << endl;
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