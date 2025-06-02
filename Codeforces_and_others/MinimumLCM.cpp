#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    if (n % 2 == 0)
        cout << n / 2 << gap << n / 2 << endl;
    else
    {
        ll max = 1;
        ll limit = sqrt(n) + 1;
        set<ll> s;
        for (i = 3; i < limit; i += 2)
        {
            if (n % i == 0)
            {
                s.insert(i);
                s.insert(n / i);
            }
        }
        if (s.size() != 0)
            max = *(--s.end());
        cout << max << gap << n - max << endl;
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}