#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

vector<vector<ll>> ans;

void swapBit(set<ll> &big, set<ll> &small, ll avg, ll a, ll b)
{
    set<ll> dif;
    set_difference(big.begin(), big.end(), small.begin(), small.end(), inserter(dif, dif.end()));
    vector<ll> v;
    for (auto x : dif)
    {
        v.clear();
        if (small.size() == avg || big.size() == avg)
            break;
        v.push_back(a);
        v.push_back(b);
        v.push_back(x);
        ans.push_back(v);
        small.insert(x);
        big.erase(x);
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    ans.clear();
    cin >> n >> m;
    vector<set<ll>> v(n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a;
            if (a == 1)
                v[i].insert(j);
        }
    }
    ll total_one = 0;
    for (auto x : v)
        total_one += x.size();
    if (total_one % n != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        ll avg = total_one / n;
        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (v[i].size() > avg)
                {
                    if (v[j].size() >= avg)
                        continue;
                    else
                    {
                        swapBit(v[i], v[j], avg, i, j);
                    }
                }
                else if (v[i].size() < avg)
                {
                    if (v[j].size() <= avg)
                        continue;
                    else
                    {
                        swapBit(v[j], v[i], avg, i, j);
                    }
                }
                else
                    break;
            }
        }
        cout << ans.size() << endl;
        for (auto x : ans)
        {
            for (auto y : x)
                cout << y + 1 << gap;
            cout << endl;
        }
    }
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