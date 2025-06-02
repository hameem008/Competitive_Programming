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
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll avi = 0, ravi = 0, gp = 0;
    for (auto x : v)
    {
        if (x == 1)
        {
            gp++;
            if (ravi > 0)
            {
                ravi--;
            }
            else
            {
                avi++;
            }
        }
        else if (x == 2)
        {
            ll need = gp / 2 + 1;
            ravi = avi - need;
        }
    }
    cout << avi << endl;
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