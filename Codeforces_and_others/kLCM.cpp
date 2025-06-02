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
    vector<ll> ans;
    while (k > 3)
    {
        ans.push_back(1);
        k--, n--;
    }
    if (n % 2 != 0)
    {
        ans.push_back(1);
        ans.push_back((n - 1) / 2);
        ans.push_back((n - 1) / 2);
    }
    else if (n % 4 != 0)
    {
        ans.push_back(2);
        ans.push_back((n - 2) / 2);
        ans.push_back((n - 2) / 2);
    }
    else
    {
        ans.push_back(n / 2);
        ans.push_back(n / 4);
        ans.push_back(n / 4);
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