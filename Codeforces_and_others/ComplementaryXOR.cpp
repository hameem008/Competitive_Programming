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
    string stra, strb;
    cin >> stra >> strb;
    flag = true;
    ll zeros = 0, ones = 0;
    for (i = 0; i < n; i++)
    {
        if (stra[i] != strb[i])
            flag = false;
        if (stra[i] == '0')
            zeros++;
        else
            ones++;
    }
    if (flag)
    {
        vector<pair<ll, ll>> ans;
        if (zeros == 0)
        {
            ans.push_back({1, 1});
            ans.push_back({2, n});
        }
        else if (ones == 0)
        {
        }
        else
        {
            ans.push_back({1, n});
            for (i = 0; i < n; i++)
            {
                if (stra[i] == '0')
                {
                    ans.push_back({i + 1, i + 1});
                }
            }
        }
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (auto x : ans)
            cout << x.first << gap << x.second << endl;
        return;
    }
    flag = true;
    for (i = 0; i < n; i++)
    {
        if (stra[i] == strb[i])
            flag = false;
    }
    if (flag)
    {
        vector<pair<ll, ll>> ans;
        if (zeros == 0)
        {
            ans.push_back({1, n});
        }
        else if (ones == 0)
        {
            ans.push_back({1, n});
            ans.push_back({1, 1});
            ans.push_back({2, n});
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                if (stra[i] == '1')
                {
                    ans.push_back({i + 1, i + 1});
                }
            }
        }
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (auto x : ans)
            cout << x.first << gap << x.second << endl;
        return;
    }
    cout << "NO" << endl;
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