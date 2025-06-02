#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, c, b, m, n, p;
    // solve stars
    cin >> a >> b >> c;
    set<ll> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    auto it = s.begin();
    it++;
    cout << *it << endl;
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