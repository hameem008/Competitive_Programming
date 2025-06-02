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
    multiset<ll> length;
    set<ll> points;
    cin >> n >> k;
    length.insert(n);
    for (i = 1; i <= k; i++)
    {
        cin >> a;
        points.insert(a);
        auto it = points.find(a);
        ll prev, nxt;
        if (it == points.begin())
        {
            prev = 0;
        }
        else
        {
            it--;
            prev = *it;
            it++;
        }
        it++;
        if (it == points.end())
        {
            nxt = n;
        }
        else
        {
            nxt = *it;
        }
        length.erase(length.find(nxt - prev));
        length.insert(a - prev);
        length.insert(nxt - a);
        cout << *length.rbegin() << gap;
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}