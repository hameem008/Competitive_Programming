#include <bits/stdc++.h>
using namespace std;
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    ll dist, dist_r, dist_c;
    cin >> n >> m;

    cout << "?" << gap << 1 << gap << 1 << endl;
    cin >> dist;
    dist++;
    cout << "?" << gap << min(dist, n) << gap << 1 << endl;
    cin >> dist_r;
    cout << "?" << gap << 1 << gap << min(dist, m) << endl;
    cin >> dist_c;

    if (dist_r == dist_c)
    {
        cout << "!" << gap << dist << gap << dist << endl;
    }
    else if (dist_r < dist_c)
    {
        cout << "!" << gap << min(dist, n) << gap << 1 + dist_r << endl;
    }
    else if (dist_r > dist_c)
    {
        cout << "!" << gap << 1 + dist_c << gap << min(dist, m) << endl;
    }
    // solve ends
}

int main()
{
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}