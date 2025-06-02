#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    set<ll> aa, bb;
    for (i = 0; i < 4; i++)
    {
        cin >> a >> b;
        aa.insert(a);
        bb.insert(b);
    }
    cout << (*aa.rbegin() - *aa.begin()) * (*bb.rbegin() - *bb.begin()) << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}