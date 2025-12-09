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
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> pre = nums, suf = nums;
        for (int i = 1; i < pre.size(); i++)
        {
            pre[i] = pre[i] * pre[i - 1];
        }
        for (int i = suf.size() - 2; i >= 0; i--)
        {
            suf[i] = suf[i] * suf[i + 1];
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                ans.push_back(suf[i + 1]);
            }
            else if (i == nums.size() - 1)
            {
                ans.push_back(pre[i - 1]);
            }
            else
            {
                ans.push_back(pre[i - 1] * suf[i + 1]);
            }
        }
        return ans;
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