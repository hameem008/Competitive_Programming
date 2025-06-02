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
    string str;
    cin >> str;
    ll ans1 = 0;
    for (i = str.size() - 1; i > 0; i--)
    {
        ll limit = (i + 1) / 2;
        m = i, n = 0;
        while (limit--)
        {
            if (str[m] != str[n])
            {
                ans1 = i + 1;
                break;
            }
            n++, m--;
        }
        if (ans1)
            break;
    }
    ll ans2 = 0;
    for (i = 0; i < str.size(); i++)
    {
        ll limit = (str.size() - i) / 2;
        m = i, n = str.size() - 1;
        while (limit--)
        {
            if (str[m] != str[n])
            {
                ans2 = str.size() - i;
                break;
            }
            m++, n--;
        }
        if (ans2)
            break;
    }
    max(ans1, ans2) == 0 ? cout << -1 << endl : cout << max(ans1, ans2) << endl;
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