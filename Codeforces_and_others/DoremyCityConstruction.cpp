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
    multiset<ll> ms;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        ms.insert(a);
    }
    vector<ll> calc;
    while (ms.size() != 0)
    {
        calc.push_back(ms.count(*ms.begin()));
        ms.erase(*ms.begin());
    }
    if (calc.size() == 1)
    {
        cout << calc[0] / 2 << endl;
    }
    else
    {
        ll sum = 0;
        ll ans = 0;
        for (i = 0; i < calc.size(); i++)
        {
            sum += calc[i];
            if (ans < sum * (n - sum))
                ans = sum * (n - sum);
        }
        cout << ans << endl;
    }
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