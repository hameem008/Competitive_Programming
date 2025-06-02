#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<ll> v(2 * n + 1);
    for (i = 1; i <= 2 * n; i++)
        cin >> v[i];
    vector<ll> trac(n + 1, 0);
    multiset<ll> ms;
    for (i = 1; i <= n; i++)
    {
        ms.insert(v[i]);
    }
    for (i = 1; i <= n; i++)
    {
        if (ms.count(i) == 2)
        {
            trac[i] = 1;
        }
        else if (ms.count(i) == 0)
        {
            trac[i] = 2;
        }
    }
    vector<ll> ans1, ans2;
    for (i = 1; i <= n; i++)
    {
        if (trac[i] == 1)
        {
            ans1.push_back(i);
            ans1.push_back(i);
            if (ans1.size() > 2 * k)
            {
                ans1.pop_back();
                ans1.pop_back();
            }
        }
        else if (trac[i] == 2)
        {
            ans2.push_back(i);
            ans2.push_back(i);
            if (ans2.size() > 2 * k)
            {
                ans2.pop_back();
                ans2.pop_back();
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (trac[i] == 0)
        {
            ans1.push_back(i);
            if (ans1.size() > 2 * k)
                ans1.pop_back();
            ans2.push_back(i);
            if (ans2.size() > 2 * k)
                ans2.pop_back();
        }
    }
    for (auto x : ans1)
        cout << x << gap;
    cout << endl;
    for (auto x : ans2)
        cout << x << gap;
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