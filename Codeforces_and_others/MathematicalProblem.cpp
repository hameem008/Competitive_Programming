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
    cin >> n;
    string s;
    cin >> s;
    if (n == 2)
    {
        if (s[0] == '0')
            cout << s[1] << endl;
        else
            cout << s << endl;
    }
    else
    {
        ll ans = infinite;
        j = 0;
        ll limit = n - 1;
        while (limit--)
        {
            vector<ll> v;
            for (i = 0; i < n; i++)
            {
                if (i == j)
                {
                    v.push_back((s[i] - '0') * 10 + s[i + 1] - '0');
                    i++;
                }
                else
                {
                    v.push_back(s[i] - '0');
                }
            }
            flag = false;
            for (auto x : v)
            {
                if (x == 0)
                    flag = true;
            }
            if (flag)
            {
                ans = 0;
            }
            else
            {
                ll dum = 0;
                for (auto x : v)
                {
                    if (x != 1)
                        dum += x;
                }
                if (dum == 0)
                    dum++;
                ans = min(ans, dum);
            }
            j++;
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