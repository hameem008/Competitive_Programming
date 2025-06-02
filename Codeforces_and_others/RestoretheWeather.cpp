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
    vector<ll> va(n), vb(n);
    for (auto &x : va)
        cin >> x;
    for (auto &x : vb)
        cin >> x;
    vector<ll> dumva = va, dumvb = vb;
    sort(dumvb.begin(), dumvb.end());
    sort(dumva.begin(), dumva.end());
    multimap<ll, ll> mp;
    for (i = 0; i < n; i++)
    {
        mp.insert({dumva[i], dumvb[i]});
    }
    for (i = 0; i < n; i++)
    {
        auto it = mp.find(va[i]);
        cout << it->second << gap;
        mp.erase(it);
    }
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