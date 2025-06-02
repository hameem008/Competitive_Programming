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
    vector<char> v(n + 1);
    for (i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        v[i] = ch;
    }
    map<char, ll> odd, even;
    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            even[v[i]]++;
        else
            odd[v[i]]++;
    }
    if (n % 2 == 0)
    {
        ll mxev = -1, mxod = -1;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            mxod = max(mxod, odd[ch]);
        }
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            mxev = max(mxev, even[ch]);
        }
        cout << n - mxev - mxod << endl;
    }
    else
    {
        ll ans = infinite;
        map<char, ll> dum_odd, dum_even;
        for (i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                even[v[i]]--;

                ll mxev = -1, mxod = -1;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    mxod = max(mxod, odd[ch] + dum_even[ch]);
                }
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    mxev = max(mxev, even[ch] + dum_odd[ch]);
                }
                ans = min(ans, n - mxev - mxod - 1);

                dum_even[v[i]]++;
            }
            else
            {
                odd[v[i]]--;

                ll mxev = -1, mxod = -1;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    mxod = max(mxod, odd[ch] + dum_even[ch]);
                }
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    mxev = max(mxev, even[ch] + dum_odd[ch]);
                }
                ans = min(ans, n - mxev - mxod - 1);

                dum_odd[v[i]]++;
            }
        }
        ans++;
        cout << ans << endl;
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