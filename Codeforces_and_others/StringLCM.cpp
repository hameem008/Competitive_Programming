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
    string s, t;
    cin >> s >> t;
    ll st_gcd_l = __gcd(s.size(), t.size());
    string gcd_str;
    for (i = 0; i < st_gcd_l; i++)
    {
        gcd_str.push_back(s[i]);
    }
    j = 0;
    flag = true;
    for (i = 0; i < s.size(); i++, j++)
    {
        if (j == st_gcd_l)
            j = 0;
        if (s[i] != gcd_str[j])
            flag = false;
    }
    j = 0;
    for (i = 0; i < t.size(); i++, j++)
    {
        if (j == st_gcd_l)
            j = 0;
        if (t[i] != gcd_str[j])
            flag = false;
    }
    if (!flag)
        cout << -1 << endl;
    else
    {
        ll st_lcm_l = s.size() * t.size() / st_gcd_l;
        string ans;
        j = 0;
        for (i = 0; i < st_lcm_l; i++, j++)
        {
            if (j == st_gcd_l)
                j = 0;
            ans.push_back(gcd_str[j]);
        }
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