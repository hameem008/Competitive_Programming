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
    bool pf(int mid, vector<int> &nums, int target)
    {
        return nums[mid] >= target;
    }
    int search(vector<int> &nums, int target)
    {
        int ans = -1;
        int hi = nums.size() - 1, lo = 0, mid;
        while (hi - lo > 1) // FFFFTTT find first true
        {
            mid = (hi + lo) / 2;
            if (pf(mid, nums, target))
                hi = mid;
            else
                lo = mid + 1;
        }
        if (pf(lo, nums, target))
        {
            if (nums[lo] == target)
                ans = lo;
        }
        else if (pf(hi, nums, target))
        {
            if (nums[hi] == target)
                ans = hi;
        }
        return ans;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    int target;
    cin >> n >> target;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    Solution sl;
    cout << sl.search(v, target) << endl;
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