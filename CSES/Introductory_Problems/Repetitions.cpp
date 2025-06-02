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
    string str;
    cin >> str;
    ll ans = 0;
    ll cnt = 0;
    char curr = str[0];
    for (i = 0; i < str.size(); i++)
    {
        if (curr == str[i])
        {
            cnt++;
        }
        else
        {
            ans = max(ans, cnt);
            cnt = 1;
            curr = str[i];
        }
    }
    ans = max(ans, cnt);
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