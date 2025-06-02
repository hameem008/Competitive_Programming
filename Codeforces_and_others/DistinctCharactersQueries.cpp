#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str;
    cin >> str;
    cin >> q;
    vector<set<ll>> mp(26);
    for (i = 0; i < str.size(); i++)
    {
        mp[str[i] - 'a'].insert(i);
    }
    for (i = 0; i < q; i++)
    {
        ll op;
        cin >> op;
        if (op == 1)
        {
            ll ind;
            char ch;
            cin >> ind >> ch;
            ind--;
            mp[str[ind] - 'a'].erase(ind);
            str[ind] = ch;
            mp[str[ind] - 'a'].insert(ind);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            ll ans = 0;
            l--;
            r--;
            for (j = 0; j < 26; j++)
            {
                auto it = mp[j].lower_bound(l);
                if (it != mp[j].end() && *it <= r)
                {
                    ans++;
                }
            }
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}