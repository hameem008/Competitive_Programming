#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    string str;
    cin >> str;
    vector<ll> v(n + 1, true);
    ll ans = 0, rv = 0;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
        {
            v[i + 1] = false;
            rv++;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j += i)
        {
            if (str[j - 1] == '0')
            {
                if (v[j] == false)
                {
                    ans += i;
                    rv--;
                    v[j] = true;
                }
            }
            else
                break;
        }
        if (rv == 0)
            break;
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