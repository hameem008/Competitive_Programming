#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag = false;
    // solve starts
    cin >> n >> a >> b;
    if (a == 1)
    {
        if ((n - 1) % b == 0)
            flag = true;
    }
    else
    {
        for (i = 0; (ll)pow(a, i) <= n; i++)
        {
            if ((n - (ll)pow(a, i)) % b == 0)
            {
                flag = true;
                break;
            }
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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