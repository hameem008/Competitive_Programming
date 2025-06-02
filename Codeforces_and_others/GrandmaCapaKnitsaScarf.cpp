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
    string str;
    cin >> str;
    ll ans = infinite;
    for (i = 0; i <= 25; i++)
    {
        ll dum_ans = 0;
        char ch = 'a' + i;
        ll l = 0, r = n - 1;
        while (l <= r)
        {
            if (str[l] != str[r])
            {
                if (str[l] == ch)
                {
                    l++, dum_ans++;
                }
                else if (str[r] == ch)
                {
                    r--, dum_ans++;
                }
                else
                {
                    dum_ans = infinite;
                    break;
                }
            }
            else
            {
                l++, r--;
            }
        }
        ans = min(ans, dum_ans);
    }
    ans == infinite ? cout << -1 << endl : cout << ans << endl;
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