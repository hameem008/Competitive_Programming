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
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() <= 3)
            return *max_element(nums.begin(), nums.end());
        int ret = 0;
        vector<vector<int>> vv;
        vector<int> dum_num;
        for (int i = 0; i < nums.size() - 1; i++)
            dum_num.push_back(nums[i]);
        vv.push_back(dum_num);
        dum_num.clear();
        for (int i = 1; i < nums.size(); i++)
            dum_num.push_back(nums[i]);
        vv.push_back(dum_num);
        for (auto x : vv)
        {
            nums = x;
            if (nums.size() == 3)
            {
                nums[2] += nums[0];
                int val = max(nums[1], nums[2]);
                ret = max(val, ret);
            }
            else
            {
                nums[2] += nums[0];
                for (int i = 3; i < nums.size(); i++)
                    nums[i] += max(nums[i - 2], nums[i - 3]);
                int val = *max_element(nums.begin(), nums.end());
                ret = max(val, ret);
            }
        }
        return ret;
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