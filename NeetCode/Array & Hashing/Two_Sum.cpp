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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        map<int, set<int>> mp;
        for (int i = 1; i <= nums.size(); i++)
        {
            mp[nums[i - 1]].insert(i);
        }
        for (int i = 1; i <= nums.size(); i++)
        {
            mp[nums[i - 1]].erase(i);
            if (mp[target - nums[i - 1]].size())
            {
                ans.push_back(i - 1);
                ans.push_back(*mp[target - nums[i - 1]].begin() - 1);
                break;
            }
        }
        return ans;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<int> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];
    Solution sl;
    vector ans = sl.twoSum(v, m);
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