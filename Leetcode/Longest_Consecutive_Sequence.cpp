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
        unordered_set<int> us;
        for (auto x : nums)
            us.insert(x);
        int ans = 0;
        while (us.size())
        {
            int num = *us.begin(), len = 1;
            int curr_num = num;
            while (1)
            {
                curr_num--;
                if (us.count(curr_num))
                {
                    len++;
                    us.erase(curr_num);
                }
                else
                    break;
            }
            curr_num = num;
            while (1)
            {
                curr_num++;
                if (us.count(curr_num))
                {
                    len++;
                    us.erase(curr_num);
                }
                else
                    break;
            }
            us.erase(num);
            ans = max(len, ans);
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