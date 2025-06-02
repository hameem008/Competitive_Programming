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
    cin >> n;
    vector<ll> v, index;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
        if (a == 0)
            index.push_back(i);
    }
    index.push_back(n);
    ll sum = 0;
    vector<ll> prefix(n);
    for (i = 0; i < n; i++)
    {
        sum += v[i];
        prefix[i] = sum;
    }
    ll ans = 0;
    if (index.size() >= 2)
    {
        ll temp = 0;
        for (i = 0; i < index.size() - 1; i++)
        {
            multimap<ll, ll> mp;
            for (j = index[i]; j < index[i + 1]; j++)
            {
                auto it = mp.find(prefix[j]);
                if (it == mp.end())
                {
                    mp.insert({prefix[j], 1});
                }
                else
                {
                    it->second++;
                }
            }
            ll max = INT32_MIN;
            ll an;
            for (auto x : mp)
            {
                if (x.second > max)
                {
                    max = x.second;
                    an = x.first;
                }
            }
            v[index[i]] = -an + temp;
            temp = an;
        }
        sum = 0;
        for (i = 0; i < n; i++)
        {
            sum += v[i];
            prefix[i] = sum;
        }
        for (auto x : prefix)
        {
            if (x == 0)
                ans++;
        }
    }
    else
    {
        for (auto x : prefix)
        {
            if (x == 0)
                ans++;
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

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}