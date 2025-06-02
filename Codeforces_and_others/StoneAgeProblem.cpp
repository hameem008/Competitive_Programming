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
    cin >> n >> q;
    map<ll, ll> mp;
    ll allele = 0, sum = 0, ind, value;
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        sum += a;
        mp.insert({i, a});
    }
    for (i = 1; i <= q; i++)
    {
        cin >> c;
        if (c == 1)
        {
            cin >> ind >> value;
            auto it = mp.find(ind);
            if (it == mp.end())
            {
                mp.insert({ind, value});
                sum -= allele;
                sum += value;
            }
            else
            {
                sum -= mp[ind];
                sum += value;
                mp[ind] = value;
            }
        }
        else if (c == 2)
        {
            mp.clear();
            cin >> allele;
            sum = allele * n;
        }
        cout << sum << endl;
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