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
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int goal = n - 1;
        for (int i = n - 2; i >= 0; i--)
            if (i + nums[i] >= goal)
                goal = i;
        if (goal == 0)
            return true;
        else
            return false;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<int> nums = {1, 2, 0, 1, 0};
    Solution sl;
    sl.canJump(nums);
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