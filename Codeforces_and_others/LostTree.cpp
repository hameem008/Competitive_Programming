#include <bits/stdc++.h>
using namespace std;
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> dist(n + 1);
    set<pair<ll, ll>> edges;
    cout << "? 1" << endl;
    for (i = 1; i <= n; i++)
    {
        cin >> dist[i];
    }
    vector<ll> odd, even;
    for (i = 1; i <= n; i++)
    {
        if (dist[i] > 0 && dist[i] % 2 == 0)
        {
            even.push_back(i);
        }
        else if (dist[i] > 0 && dist[i] % 2 != 0)
        {
            odd.push_back(i);
        }
        if (dist[i] == 1 && i != 1)
        {
            edges.insert({1, i});
        }
    }
    if (odd.size() < even.size())
    {
        for (auto x : odd)
        {
            cout << "?" << gap << x << endl;
            for (i = 1; i <= n; i++)
            {
                cin >> a;
                if (a == 1)
                {
                    edges.insert({min(i, x), max(i, x)});
                }
            }
        }
    }
    else
    {
        for (auto x : even)
        {
            cout << "?" << gap << x << endl;
            for (i = 1; i <= n; i++)
            {
                cin >> a;
                if (a == 1)
                {
                    edges.insert({min(i, x), max(i, x)});
                }
            }
        }
    }
    cout << "!" << endl;
    for (auto x : edges)
        cout << x.first << gap << x.second << endl;
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