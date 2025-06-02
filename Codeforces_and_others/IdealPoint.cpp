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
    cin >> n >> k;
    vector<pair<ll, ll>> v;
    for (i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (k >= a && k <= b)
            v.push_back({a, b});
    }
    if (v.size() == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        vector<ll> hash(51, 0);
        for (auto x : v)
        {
            for (i = x.first; i <= x.second; i++)
            {
                hash[i]++;
            }
        }
        ll maX = *max_element(hash.begin(), hash.end());
        ll cnt = count(hash.begin(), hash.end(), maX);
        if (maX == hash[k] && cnt == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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