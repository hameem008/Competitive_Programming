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
    vector<vector<int>> ret;
    vector<int> container;
    void rec(vector<int> &nums, vector<int> &cnt, int sum, int target, int index)
    {
        if (sum == target)
            ret.push_back(container);
        if (index == nums.size() || sum >= target)
            return;
        rec(nums, cnt, sum, target, index + 1);
        if (cnt[index])
        {
            cnt[index]--;
            sum += nums[index];
            container.push_back(nums[index]);
            rec(nums, cnt, sum, target, index);
            container.pop_back();
            sum -= nums[index];
            cnt[index]++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        multiset<int> ms(candidates.begin(), candidates.end());
        vector<int> v, cnt;
        while (ms.size())
        {
            auto it = ms.begin();
            v.push_back(*it);
            cnt.push_back(ms.count(*it));
            ms.erase(*it);
        }
        rec(v, cnt, 0, target, 0);
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