#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void rec(ll n, vector<bool> &isPossible)
{
    isPossible[n] = true;
    if (n % 3 != 0)
        return;
    if (!isPossible[n / 3])
        rec(n / 3, isPossible);
    if (!isPossible[2 * n / 3])
        rec(2 * n / 3, isPossible);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<bool> isPossible(1e7 + 1, false);
    rec(n, isPossible);
    isPossible[m] ? cout << "YES" << endl : cout << "NO" << endl;
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