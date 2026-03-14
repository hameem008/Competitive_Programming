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
    void rec(vector<int> &nums, int index, vector<int> &cnt)
    {
        if (index == nums.size())
        {
            ret.push_back(container);
            return;
        }

        rec(nums, index + 1, cnt);
        if (cnt[index])
        {
            cnt[index]--;
            container.push_back(nums[index]);
            rec(nums, index, cnt);
            container.pop_back();
            cnt[index]++;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        multiset<int> ms(nums.begin(), nums.end());
        vector<int> v_nums, cnt;
        while (ms.size())
        {
            auto it = ms.begin();
            v_nums.push_back(*it);
            cnt.push_back(ms.count(*it));
            ms.erase(*it);
        }
        rec(v_nums, 0, cnt);
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