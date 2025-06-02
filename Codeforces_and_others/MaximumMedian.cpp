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
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    map<ll, ll> mp;
    for (i = n / 2; i < n; i++)
    {
        mp[v[i]]++;
    }
    while (1)
    {
        auto it = mp.begin();
        auto it1 = it;
        it1++;
        if (it1 != mp.end())
        {
            ll in = it1->first - it->first;
            if (it->second * in < k)
            {
                k -= it->second * in;
                it1->second += it->second;
                mp.erase(it);
            }
            else if (it->second * in == k)
            {
                cout << it1->first << endl;
                return;
            }
            else if (it->second * in > k)
            {
                in = k / it->second;
                cout << it->first + in << endl;
                return;
            }
        }
        else
        {
            ll in = k / it->second;
            cout << it->first + in << endl;
            return;
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}