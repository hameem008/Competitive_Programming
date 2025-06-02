#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<ll> num;

ll ones(ll n)
{
    ll ans = 0;
    for (ll mask = 0; mask < 64; mask++)
    {
        if (n & (1LL << mask))
            ans++;
    }
    return ans;
}

ll rec(ll n, ll index)
{
    if (index == -1)
        return ones(n);
    if (n < num[index])
        return rec(n, index - 1);
    else
        return min(rec(n, index - 1), rec(n - num[index], index - 1) + 1);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    cout << rec(n, num.size() - 1) << endl;
    //  solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll fact = 2;
    num.push_back(fact);
    for (ll i = 3; i <= 14; i++)
    {
        fact *= i;
        num.push_back(fact);
    }

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}