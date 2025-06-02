#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<vector<ll>> allSubset;
void subsetgen(vector<ll> &subset, ll ind, vector<ll> &v)
{
    if (ind == v.size())
    {
        allSubset.push_back(subset);
        return;
    }
    subsetgen(subset, ind + 1, v);
    subset.push_back(v[ind]);
    subsetgen(subset, ind + 1, v);
    subset.pop_back();
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n), dum;
    for (auto &x : v)
        cin >> x;
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    subsetgen(dum, 0, v);
    ll ans = infinite;
    for (auto x : allSubset)
    {
        ll temp = 0;
        for (auto y : x)
        {
            temp += y;
        }
        ans = min(ans, abs(sum - 2 * temp));
    }
    cout << ans << endl;
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