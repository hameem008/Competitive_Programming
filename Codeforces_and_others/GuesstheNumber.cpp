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
    string str;
    ll hi = 1000000, lo = 1, mid;
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        cout << mid << endl;
        cin >> str;
        if (str == ">=")
            lo = mid;
        else
            hi = mid - 1;
    }
    cout << hi << endl;
    cin >> str;
    if (str == ">=")
        cout << "! " << hi << endl;
    else
        cout << "! " << lo << endl;
    // solve ends
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}