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
    bool pf(int mid, vector<int> &nums)
    {
        return nums[mid] < nums.front();
    }
    bool pf2(int mid, vector<int> &nums, int target)
    {
        return nums[mid] >= target;
    }
    int bin_search(vector<int> &nums, int target, int low, int high)
    {
        int ans;
        int hi = high, lo = low, mid;
        while (hi - lo > 1) // FFFFTTT find first true
        {
            mid = (hi + lo) / 2;
            if (pf2(mid, nums, target))
                hi = mid;
            else
                lo = mid + 1;
        }
        if (pf2(lo, nums, target))
            ans = lo;
        else
            ans = hi;
        if (nums[ans] != target)
            ans = -1;
        return ans;
    }
    int search(vector<int> &nums, int target)
    {
        if (nums.front() <= nums.back())
        {
            int ans = bin_search(nums, target, 0, nums.size() - 1);
            return ans;
        }
        else
        {
            int min_ind, ans;
            int hi = nums.size() - 1, lo = 0, mid;
            while (hi - lo > 1) // FFFFTTT find first true
            {
                mid = (hi + lo) / 2;
                if (pf(mid, nums))
                    hi = mid;
                else
                    lo = mid + 1;
            }
            if (pf(lo, nums))
                min_ind = lo;
            else
                min_ind = hi;
            if (nums[min_ind] <= target && nums.back() >= target)
                ans = bin_search(nums, target, min_ind, nums.size() - 1);
            else
                ans = bin_search(nums, target, 0, min_ind - 1);
            return ans;
        }
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<int> nums = {3, 5, 6, 0, 1, 2};
    int target = 4;
    Solution sl;
    cout << sl.search(nums, target) << endl;
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