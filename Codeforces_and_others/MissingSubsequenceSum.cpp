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
    multiset<ll> seq;
    for (int i = 0; i <= 20; i++)
    {
        seq.insert(powl(2, i));
    }
    cin >> n >> k;
    ll rem;
    for (auto x : seq)
    {
        if (x <= k)
            rem = x;
    }
    seq.erase(rem);
    seq.insert(k - rem);
    seq.insert(k + 1);
    seq.insert(k + 1 + rem);
    seq.erase(0);
    cout << seq.size() << endl;
    for (auto x : seq)
        cout << x << gap;
    cout << endl;
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