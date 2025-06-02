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
    cin >> n >> k;
    string str;
    cin >> str;
    str += str;
    ll len;
    for (len = 1; len <= n; len++)
    {
        string dum1, dum2;
        for (i = 0; i < len; i++)
        {
            dum1.push_back(str[i]);
        }
        for (i = len; i < 2 * len; i++)
        {
            dum2.push_back(str[i]);
        }
        if (dum1 < dum2)
        {
            break;
        }
    }
    len = min(len, n);
    string inistr;
    for (i = 0; i < len; i++)
    {
        inistr.push_back(str[i]);
    }
    string ans;
    while (ans.size() < k)
    {
        for (auto x : inistr)
            ans.push_back(x);
    }
    while (ans.size() != k)
        ans.pop_back();
    cout << ans << endl;
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