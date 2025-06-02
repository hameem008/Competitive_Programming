#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n >> k;
    vector<pair<ll, ll>> vp(n);
    for (auto &x : vp)
        cin >> x.second;
    for (auto &x : vp)
        cin >> x.first;
    sort(vp.begin(), vp.end());
    ll maxHealth = 0;
    for (i = 0; i < n; i++)
    {
        if (maxHealth < vp[i].second)
            maxHealth = vp[i].second;
    }
    j = 0;
    ll healthDeduction = 0;
    maxHealth -= k;
    healthDeduction += k;
    bool result;
    while (1)
    {
        if (maxHealth <= 0)
        {
            result = true;
            break;
        }
        if (k <= 0)
        {
            result = false;
            break;
        }
        if (vp[j].second - healthDeduction > 0)
        {
            k -= vp[j].first;
            maxHealth -= k;
            healthDeduction += k;
        }
        else
            j++;
    }
    if (result)
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

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}