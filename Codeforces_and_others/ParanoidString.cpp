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
    string str;
    cin >> str;
    ll ans = 0;
    for (i = n - 1; i > 0; i--)
    {
        if (str[i] == '0' && str[i - 1] == '1')
        {
            ans += i;
        }
        else if (str[i] == '1' && str[i - 1] == '0')
        {
            ans += i;
        }
    }
    cout << ans + n << endl;
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