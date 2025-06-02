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
    {
        vector<ll> v;
        v.push_back(1);
        v.push_back(3);
        for (i = 2; i < n; i++)
        {
            v.push_back(2);
        }
        for (auto x : v)
            cout << x << gap;
        cout << endl;
    }
    else
    {
        vector<ll> v;
        for (i = 0; i < n; i++)
        {
            v.push_back(1);
        }
        for (auto x : v)
            cout << x << gap;
        cout << endl;
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