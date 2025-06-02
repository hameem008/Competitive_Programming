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
    ll cnt = 0;
    for (auto x : str)
        if (x == '1')
            cnt++;
    if (cnt % 2 != 0)
    {
        cout << "NO" << endl;
        return;
    }
    if (cnt == 2)
    {
        for (i = 0; i < n - 1; i++)
        {
            if (str[i] == '1' && str[i + 1] == '1')
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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