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
        unordered_map<int, int> mp;
        for (auto x : nums)
            mp[x]++;
        set<pair<int, int>> s;
        for (auto x : mp)
        {
            s.insert({x.second, x.first});
            if (s.size() > k)
                s.erase(s.begin());
        }
        for (auto x : s)
            ans.push_back(x.second);
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