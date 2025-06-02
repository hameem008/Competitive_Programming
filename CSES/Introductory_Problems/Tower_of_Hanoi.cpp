#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void toh(ll n, ll left, ll middle, ll right)
{
    if (n == 0)
        return;
    toh(n - 1, left, right, middle);
    cout << left << gap << right << endl;
    toh(n - 1, middle, left, right);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    cout << pow(2, n) - 1 << endl;
    toh(n, 1, 2, 3);
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