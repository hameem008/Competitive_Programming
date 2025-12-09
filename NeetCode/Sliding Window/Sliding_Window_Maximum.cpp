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
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int alfange = 0, enden = k - 1;
        vector<int> ans;
        multiset<int> ms;
        for (int i = alfange; i <= enden; i++)
            ms.insert(nums[i]);
        while (1)
        {
            ans.push_back(*ms.rbegin());
            ms.erase(ms.find(nums[alfange]));
            alfange++, enden++;
            if (enden == nums.size())
                break;
            ms.insert(nums[enden]);
        }
        return ans;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    Solution sl;
    for (auto x : sl.maxSlidingWindow(v, k))
        cout << x << gap;
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