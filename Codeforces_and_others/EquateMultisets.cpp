#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

ll red(ll n)
{
    while (n % 2 == 0)
    {
        n /= 2;
    }
    return n;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> va(n), vb(n);
    for (auto &x : va)
        cin >> x;
    for (auto &x : vb)
        cin >> x;
    for (i = 0; i < n; i++)
    {
        va[i] = red(va[i]);
    }
    multiset<ll> msa(va.begin(), va.end());
    for (i = n - 1; i >= 0; i--)
    {
        auto it = msa.find(vb[i]);
        while (it == msa.end() && vb[i] != 0)
        {
            vb[i] /= 2;
            it = msa.find(vb[i]);
        }
        if (it != msa.end())
        {
            msa.erase(it);
        }
    }
    msa.size() == 0 ? cout << "YES" << endl : cout << "NO" << endl;
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