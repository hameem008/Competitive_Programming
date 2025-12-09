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
    pair<int, int> get_pos_range(vector<int> &nums1, vector<int> &nums2, int val)
    {
        int low1 = lower_bound(nums1.begin(), nums1.end(), val) - nums1.begin();
        int low2 = lower_bound(nums2.begin(), nums2.end(), val) - nums2.begin();
        int high1 = upper_bound(nums1.begin(), nums1.end(), val) - nums1.begin();
        int high2 = upper_bound(nums2.begin(), nums2.end(), val) - nums2.begin();
        int low = low1 + low2;
        int high = high1 + high2 - 1;
        return {low + 1, high + 1};
    }
    bool pf(int mid, vector<int> &nums, int pos, vector<int> &nums1, vector<int> &nums2)
    {
        pair<int, int> pr = get_pos_range(nums1, nums2, nums[mid]);
        return pr.second >= pos;
    }
    int bin_search(vector<int> &nums, int pos, vector<int> &nums1, vector<int> &nums2)
    {
        int hi = nums.size() - 1, lo = 0, mid;
        while (hi - lo > 1) // FFFFTTT find first true
        {
            mid = (hi + lo) / 2;
            if (pf(mid, nums, pos, nums1, nums2))
                hi = mid;
            else
                lo = mid + 1;
        }
        int ind = -1;
        pair<int, int> pr = get_pos_range(nums1, nums2, nums[lo]);
        if (pos >= pr.first && pos <= pr.second)
        {
            ind = lo;
        }
        pr = get_pos_range(nums1, nums2, nums[hi]);
        if (pos >= pr.first && pos <= pr.second)
        {
            ind = hi;
        }
        return ind;
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() == 0)
            nums1 = nums2;
        else if (nums2.size() == 0)
            nums2 = nums1;
        int total_nums = nums1.size() + nums2.size();
        if (total_nums % 2 == 0)
        {
            int madien1_pos = total_nums / 2;
            int madien2_pos = total_nums / 2 + 1;

            int madien1 = 0, madien2 = 0;
            int pos = bin_search(nums1, madien1_pos, nums1, nums2);
            if (pos != -1)
                madien1 = nums1[pos];
            else
            {
                pos = bin_search(nums2, madien1_pos, nums1, nums2);
                madien1 = nums2[pos];
            }

            pos = bin_search(nums1, madien2_pos, nums1, nums2);
            if (pos != -1)
                madien2 = nums1[pos];
            else
            {
                pos = bin_search(nums2, madien2_pos, nums1, nums2);
                madien2 = nums2[pos];
            }
            return (madien1 + madien2) / 2.0;
        }
        else
        {
            int madien_pos = (total_nums + 1) / 2;
            int madien;
            int pos = bin_search(nums1, madien_pos, nums1, nums2);
            if (pos != -1)
                madien = nums1[pos];
            else
            {
                pos = bin_search(nums2, madien_pos, nums1, nums2);
                madien = nums2[pos];
            }
            return madien;
        }
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {1, 1};
    // 1 1 2 2 3 3 4 4
    Solution sl;
    cout << sl.findMedianSortedArrays(nums1, nums2) << endl;
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