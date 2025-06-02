#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

vector<ll> twoPower;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    if (n == 2)
    {
        cout << -1 << endl;
    }
    else if (n % 2 == 1)
    {
        cout << 2 << endl;
    }
    else
    {
        ll ans;
        for (i = 0; i < twoPower.size(); i++)
        {
            if (n % twoPower[i] == 0)
            {
                ans = n / twoPower[i];
            }
            else
            {
                if (ans > twoPower[i])
                {
                    cout << twoPower[i] << endl;
                    return;
                }
                break;
            }
        }
        if (ans != 1)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    for (int i = 1; i <= 59; i++)
        twoPower.push_back(pow(2, i));
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}