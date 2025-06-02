#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<pair<ll, ll>> ans;
void precalc()
{
    ans.push_back({1, 1});
    ans.push_back({1, 2});
    ans.push_back({3, 1});
    for (int i = 4; i <= 1000; i++)
    {
        ans.push_back({i, i});
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    for (auto x : ans)
    {
        if (x.first <= n && x.second <= n)
        {
            cout << x.first << gap << x.second << endl;
        }
    }
    cout << endl;
    //  solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precalc();
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}