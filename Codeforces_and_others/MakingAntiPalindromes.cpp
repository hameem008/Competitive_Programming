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
    cin >> n;
    string str;
    cin >> str;
    if (n % 2 != 0)
        cout << -1 << endl;
    else
    {
        vector<ll> v(26, 0);
        for (auto x : str)
            v[x - 'a']++;
        sort(v.begin(), v.end());
        if (v.back() > n / 2)
            cout << -1 << endl;
        else
        {
            ll limit = n / 2;
            vector<ll> vp(26, 0);
            i = 0;
            while (limit--)
            {
                if (str[i] == str[n - 1 - i])
                {
                    vp[str[i] - 'a']++;
                }
                i++;
            }
            multiset<ll> ms;
            for (auto x : vp)
            {
                if (x != 0)
                    ms.insert(x);
            }
            ll ans = 0;
            while (ms.size() > 1)
            {
                auto it = ms.end();
                it--;
                ll high = *it;
                it--;
                ll low = *it;
                ms.erase(--ms.end());
                ms.erase(it);
                ans++;
                high--;
                low--;
                if (high)
                    ms.insert(high);
                if (low)
                    ms.insert(low);
            }
            if (ms.size() == 1)
                ans += *ms.begin();
            cout << ans << endl;
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