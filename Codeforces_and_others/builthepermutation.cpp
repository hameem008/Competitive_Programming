#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n >> a >> b;
    vector<ll> v;
    for (i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    if (abs(a - b) < 2 && (a + b) <= (n - 2))
    {
        if (a > b)
        {
            swap(v[n - 1], v[n - 2]);
            a--;
            j = n - 3;
            for (i = 0; i < a; i++)
            {
                swap(v[j], v[j - 1]);
                j -= 2;
            }
        }
        else if (a < b)
        {
            swap(v[0], v[1]);
            b--;
            j = 2;
            for (i = 0; i < b; i++)
            {
                swap(v[j], v[j + 1]);
                j += 2;
            }
        }
        else
        {
            j = 1;
            for (i = 0; i < a; i++)
            {
                swap(v[j], v[j + 1]);
                j += 2;
            }
        }
        for (auto x : v)
            cout << x << gap;
        cout << endl;
    }
    else
        cout << -1 << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}