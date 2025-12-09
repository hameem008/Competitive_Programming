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
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans;
        map<int, int> mp;
        for (auto x : nums)
            mp[x]++;
        vector<pair<int, int>> vp;
        for (auto x : mp)
        {
            vp.push_back({x.second, x.first});
        }
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        for (int i = 0; i < k; i++)
        {
            ans.push_back(vp[i].second);
        }
        return ans;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<int> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];
    Solution sl;
    vector<int> ans = sl.topKFrequent(v, k);
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}