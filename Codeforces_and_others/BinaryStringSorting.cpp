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
    // if (I == 580)
    //     cout << str << '+';
    vector<pair<ll, ll>> vp;
    ll cnt = 0;
    char cur = str[0];
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == cur)
        {
            cnt++;
        }
        else
        {
            vp.push_back({cur - '0', cnt});
            cur = str[i];
            cnt = 1;
        }
    }
    vp.push_back({cur - '0', cnt});
    ll ans = 0;
    ll sw = 0;
    ll rmzero = 0;
    for (i = 0; i < vp.size() - 1; i++)
    {
        // cout << "St" << endl;
        // for (auto x : vp)
        //     cout << x.first << gap << x.second << endl;
        if (vp[i].first > vp[i + 1].first)
        {
            if (vp[i].second == vp[i + 1].second)
            {
                if (vp[i].second == 1)
                {
                    ans += 1e12;
                    swap(vp[i], vp[i + 1]);
                    sw++;
                }
                else
                {
                    ans += vp[i].second * (1e12 + 1);
                    ans -= sw * 1e12;
                    ans -= rmzero * (1e12 + 1);
                    sw = 0;
                    rmzero = 0;
                }
            }
            else if (vp[i].second > vp[i + 1].second)
            {
                if (vp[i].second * (1e12 + 1) > (vp[i + 1].second * (1e12 + 1) + sw * 1e12 + rmzero * (1e12 + 1)))
                {
                    ans += vp[i + 1].second * (1e12 + 1);
                    rmzero += vp[i + 1].second;
                    swap(vp[i], vp[i + 1]);
                }
                else
                {
                    ans += vp[i].second * (1e12 + 1);
                    ans -= sw * 1e12;
                    ans -= rmzero * (1e12 + 1);
                    sw = 0;
                    rmzero = 0;
                }
            }
            else
            {
                ans += vp[i].second * (1e12 + 1);
                ans -= sw * 1e12;
                ans -= rmzero * (1e12 + 1);
                sw = 0;
                rmzero = 0;
            }
        }
        else if (vp[i].first == vp[i + 1].first)
        {
            vp[i + 1].second += vp[i].second;
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