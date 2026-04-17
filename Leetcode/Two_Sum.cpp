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
        unordered_set<int> us;
        int num_1, num_2;
        for (auto x : nums)
        {
            if (us.count(target - x))
            {
                num_1 = x, num_2 = target - x;
                break;
            }
            us.insert(x);
        }
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == num_1 || nums[i] == num_2)
                ret.push_back(i);
            if (ret.size() == 2)
                break;
        }
        return ret;
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