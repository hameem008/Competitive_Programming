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
    cin >> n >> k;
    ll diya = 0;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    while (v.size() > 1)
    {
        ll alice = v.back();
        v.pop_back();
        ll bob = v.back();
        v.pop_back();
        diya += alice - min(alice, bob + k);
        if (alice > bob + k)
        {
            k = 0;
        }
        else
        {
            k = bob + k - alice;
        }
    }
    if (v.size() == 1)
        diya += v[0];
    cout << diya << endl;
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