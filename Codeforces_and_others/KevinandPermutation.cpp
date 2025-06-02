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
    ll subt = n / 2;
    vector<ll> v;
    if (n % 2 == 0)
    {
        for (i = 0; i < subt; i++)
        {
            v.push_back(n - subt);
            v.push_back(n);
            n--;
        }
    }
    else
    {
        for (i = 0; i <= subt; i++)
        {
            v.push_back(n - subt);
            v.push_back(n);
            n--;
        }
        v.pop_back();
    }
    for (i = 0; i < v.size(); i++)
    {
        cout << v[i] << gap;
    }
    cout << endl;
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