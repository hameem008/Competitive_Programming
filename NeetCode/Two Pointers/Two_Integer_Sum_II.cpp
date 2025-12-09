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
    bool pf(int mid, vector<int> &numbers, int diff)
    {
        return numbers[mid] >= diff;
    }
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ans;
        for (int i = 0; i < numbers.size(); i++)
        {
            int diff = target - numbers[i];
            int hi = numbers.size() - 1, lo = i + 1, mid;
            while (hi - lo > 1)
            {
                mid = (hi + lo) / 2;
                if (pf(mid, numbers, diff))
                    hi = mid;
                else
                    lo = mid + 1;
            }
            if (numbers[lo] + numbers[i] == target)
            {
                ans.push_back(i + 1);
                ans.push_back(lo + 1);
                break;
            }
            else if (numbers[hi] + numbers[i] == target)
            {
                ans.push_back(i + 1);
                ans.push_back(hi + 1);
                break;
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
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    Solution sl;
    vector<int> ans = sl.twoSum(v, k);
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