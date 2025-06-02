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
    vector<ll> v(n + 1, 0);
    set<ll> s;
    for (i = 1; i <= n; i++)
        s.insert(i);
    ll mid;
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else if (n == 2)
    {
        cout << 1 << gap << 2 << endl;
    }
    else if (n == 3)
    {
        cout << 2 << gap << 1 << gap << 3 << endl;
    }
    else
    {
        if (n % 2 == 0)
        {
            mid = n / 2;
        }
        else
        {
            mid = n / 2 + 1;
        }
        v[mid] = 1;
        v[1] = 2;
        v[n] = 3;
        s.erase(1);
        s.erase(2);
        s.erase(3);
        for (i = 1; i <= n; i++)
        {
            if (v[i] == 0)
            {
                v[i] = *s.begin();
                s.erase(v[i]);
            }
        }
        for (i = 1; i <= n; i++)
        {
            cout << v[i] << gap;
        }
        cout << endl;
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