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
    map<ll, ll> mp;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        mp[a]++;
    }
    while (1)
    {
        auto it1 = mp.begin();
        auto it2 = mp.begin();
        it2++;
        if (it2 == mp.end())
        {
            ll add = it1->first + k / it1->second;
            ll rema = k % it1->second;
            ll cnt = it1->second - rema;
            mp.erase(it1);
            mp.insert({add, cnt});
            mp[add + 1] += rema;
            break;
        }
        else
        {
            ll dif = it2->first - it1->first;
            if (dif * it1->second <= k)
            {
                k -= dif * it1->second;
                it2->second += it1->second;
                mp.erase(it1);
            }
            else
            {
                ll add = it1->first + k / it1->second;
                ll rema = k % it1->second;
                ll cnt = it1->second - rema;
                mp.erase(it1);
                mp.insert({add, cnt});
                mp[add + 1] += rema;
                break;
            }
        }
    }
    ll ans = mp.begin()->first * n - n + 1;
    ans += n - mp.begin()->second;
    cout << ans << endl;
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