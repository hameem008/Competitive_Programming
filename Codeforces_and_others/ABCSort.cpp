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
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    if (v.size() == 1)
    {
        cout << "YES" << endl;
        return;
    }
    if (n % 2 == 0)
    {
        for (i = 0; i < n - 1; i += 2)
        {
            if (v[i] > v[i + 1])
                swap(v[i], v[i + 1]);
        }
        for (i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }
    else
    {
        for (i = 1; i < n - 1; i += 2)
        {
            if (v[i] > v[i + 1])
                swap(v[i], v[i + 1]);
        }
        for (i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
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