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
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    vector<ll> va, vb;
    va.push_back(0);
    vb.push_back(0);
    n++;
    for (i = 0; i < n; i += 2)
    {
        va.push_back(v[i]);
        va.push_back(0);
    }
    for (i = 1; i < n; i += 2)
    {
        vb.push_back(0);
        vb.push_back(v[i]);
    }
    if (n % 2 != 0)
    {
        va.pop_back();
        vb.push_back(0);
    }
    for (i = 1; i < va.size(); i++)
    {
        va[i] = va[i - 1] + va[i];
    }
    for (i = 1; i < vb.size(); i++)
    {
        vb[i] = vb[i - 1] + vb[i];
    }
    set<ll> dif;
    for (i = 0; i < n; i++)
    {
        dif.insert(va[i] - vb[i]);
    }
    if (dif.size() < n)
        cout << "YES" << endl;
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}