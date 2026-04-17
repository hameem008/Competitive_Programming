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
        int sz = 1e5 + 8;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int zero_cnt = 0;
        vector<int> neg_num_cnt(sz, 0), pos_num_cnt(sz, 0);
        for (auto x : nums)
        {
            if (x == 0)
                zero_cnt++;
            else if (x > 0)
                pos_num_cnt[x]++;
            else if (x < 0)
                neg_num_cnt[-x]++;
        }
        vector<int> neg_nums, pos_nums;
        for (int i = 0; i < sz; i++)
        {
            if (neg_num_cnt[i] > 0)
                neg_nums.push_back(i);
            if (pos_num_cnt[i] > 0)
                pos_nums.push_back(i);
        }
        if (zero_cnt)
        {
            if (zero_cnt >= 3)
                ans.push_back({0, 0, 0});
            for (auto x : neg_nums)
                if (pos_num_cnt[x] > 0)
                    ans.push_back({x, 0, -x});
        }
        for (auto x : pos_nums)
            if (pos_num_cnt[x] >= 2 && 2 * x < sz && neg_num_cnt[2 * x] > 0)
                ans.push_back({-2 * x, x, x});
        for (auto x : neg_nums)
            if (neg_num_cnt[x] >= 2 && 2 * x < sz && pos_num_cnt[2 * x] > 0)
                ans.push_back({-x, -x, 2 * x});
        for (int i = 0; i < pos_nums.size(); i++)
        {
            for (int j = i + 1; j < pos_nums.size(); j++)
            {
                int sum = pos_nums[i] + pos_nums[j];
                if (sum < sz && neg_num_cnt[sum] > 0)
                    ans.push_back({-sum, pos_nums[i], pos_nums[j]});
            }
        }
        for (int i = 0; i < neg_nums.size(); i++)
        {
            for (int j = i + 1; j < neg_nums.size(); j++)
            {
                int sum = neg_nums[i] + neg_nums[j];
                if (sum < sz && pos_num_cnt[sum] > 0)
                    ans.push_back({-neg_nums[i], -neg_nums[j], sum});
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