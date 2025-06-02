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
    cin >> p;
    set<pair<ll, ll>> s;
    s.insert({1, 6});
    s.insert({2, 5});
    s.insert({3, 4});
    set<pair<ll, ll>> check;
    for (i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (a == 1 || a == 6)
            s.erase({1, 6});
        else if (a == 2 || a == 5)
            s.erase({2, 5});
        else if (a == 3 || a == 4)
            s.erase({3, 4});
        if (b == 1 || b == 6)
            s.erase({1, 6});
        else if (b == 2 || b == 5)
            s.erase({2, 5});
        else if (b == 3 || b == 4)
            s.erase({3, 4});
        check.insert(*s.begin());
        s.insert({1, 6});
        s.insert({2, 5});
        s.insert({3, 4});
    }
    if (check.size() == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}