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
    multiset<ll> s;
    for (auto &x : v)
    {
        cin >> x;
        s.insert(x);
    }
    ll biggest, biggest2;
    if (s.size() == 1)
    {
        biggest = biggest2 = *s.begin();
    }
    else
    {
        auto it = s.end();
        it--;
        biggest = *it;
        it--;
        biggest2 = *it;
    }
    for (auto x : v)
    {
        if (x == biggest)
            cout << x - biggest2 << gap;
        else
            cout << x - biggest << gap;
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