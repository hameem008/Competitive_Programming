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
    ll x = 0, y = 0;
    for (auto ch : str)
    {
        if (ch == '1')
            x++;
        else if (ch == '0')
            y++;
    }
    for (i = pow(2, x); i <= pow(2, n) - pow(2, y) + 1; i++)
    {
        cout << i << gap;
    }
    cout << endl;
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