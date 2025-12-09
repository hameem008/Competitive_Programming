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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        map<int, set<pair<int, int>>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j)
                {
                    mp[nums[i] + nums[j]].insert({min(i, j), max(i, j)});
                }
            }
        }
        set<vector<int>> s_ans;
        for (int i = 0; i < nums.size(); i++)
        {
            for (auto x : mp[nums[i] * (-1)])
            {
                set<int> temp = {i, x.first, x.second};
                if (temp.size() == 3)
                {
                    vector<int> v;
                    for (auto y : temp)
                    {
                        v.push_back(nums[y]);
                    }
                    sort(v.begin(), v.end());
                    s_ans.insert(v);
                }
            }
        }
        vector<vector<int>> ans(s_ans.begin(), s_ans.end());
        return ans;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts

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