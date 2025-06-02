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
    if (str.size() == 1)
    {
        if (str[0] == '^')
            cout << 1 << endl;
        else
            cout << 2 << endl;
        return;
    }
    ll ans = 0;
    if (str[0] == '_')
        ans++;
    if (str[str.size() - 1] == '_')
        ans++;
    for (i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == '_' && str[i + 1] == '_')
        {
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