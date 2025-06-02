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
    ll ans = 1;
    if (str[0] == '0')
    {
        cout << 0 << endl;
        return;
    }
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == '?')
        {
            if (i == 0)
            {
                ans *= 9;
            }
            else
            {
                ans *= 10;
            }
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