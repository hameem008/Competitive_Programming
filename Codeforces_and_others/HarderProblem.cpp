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
    cin >> n;
    vector<bool> isP(2e5 + 8, false);
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        if (!isP[a])
        {
            v.push_back(a);
            isP[a] = true;
        }
    }
    vector<ll> ans;
    for (auto x : v)
        ans.push_back(x);
    i = 1;
    while (ans.size() < n)
    {
        if (!isP[i])
        {
            ans.push_back(i);
        }
        i++;
    }
    for (auto x : ans)
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