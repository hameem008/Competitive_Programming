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
    int findMin(vector<int> &nums)
    {
        int ans;
        if (nums.front() < nums.back())
            return nums.front();
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
            ans = lo;
        else
            ans = hi;
        return nums[ans];
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<int> nums = {2, 1};
    Solution sl;
    cout << sl.findMin(nums) << endl;
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