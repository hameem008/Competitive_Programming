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
    int longestConsecutive(vector<int> &nums)
    {
        set<int> s;
        for (auto x : nums)
            s.insert(x);
        int exp_num = *s.begin();
        int ans = 0;
        int curr_ans = 0;
        for (auto x : s)
        {
            if (x == exp_num)
            {
                curr_ans++;
                exp_num++;
            }
            else
            {
                ans = max(curr_ans, ans);
                exp_num = x + 1;
                curr_ans = 1;
            }
        }
        ans = max(curr_ans, ans);
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