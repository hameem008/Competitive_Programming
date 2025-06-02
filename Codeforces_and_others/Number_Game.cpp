#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
#define ok "ok"
typedef long long ll;

bool isPossible(ll k, multiset<ll> ms)
{
    ll num;
    bool result = true;
    for (int i = 1; i <= k; i++)
    {
        num = k - i + 1;
        auto it1 = ms.upper_bound(num);
        if (it1 == ms.begin())
        {
            result = false;
            break;
        }
        it1--;
        ms.erase(it1);
        if (ms.size() == 0)
        {
            break;
        }
        auto it2 = ms.begin();
        ms.insert(*it2 + num);
        ms.erase(it2);
    }
    return result;
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    multiset<ll> ms;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        ms.insert(p);
    }
    ll ans = 0;
    for (i = 1; i <= n; i++)
    {
        if (isPossible(i, ms))
        {
            ans = i;
        }
    }
    cout << ans << endl;
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