#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto x : nums)
        {
            mp[x]++;
        }
        for (auto x : mp)
        {
            if (x.second > 1)
                return true;
        }
        return false;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<int> v(n);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution sl;
    sl.hasDuplicate(v);
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