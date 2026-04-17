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
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> st_ind, ans;
        int n = temperatures.size();
        st_ind.push_back(n - 1);
        ans.push_back(0);
        for (int i = n - 2; i >= 0; i--)
        {
            int val = st_ind.back();
            if (temperatures[i] < temperatures[val])
            {
                ans.push_back(val - i);
                st_ind.push_back(i);
            }
            else
            {
                while (1)
                {
                    if (st_ind.size())
                        st_ind.pop_back();
                    if (st_ind.size())
                    {
                        val = st_ind.back();
                        if (temperatures[i] < temperatures[val])
                        {
                            ans.push_back(val - i);
                            st_ind.push_back(i);
                            break;
                        }
                    }
                    else
                    {
                        st_ind.push_back(i);
                        ans.push_back(0);
                        break;
                    }
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<int> v = {30, 38, 30, 36, 35, 40, 28};
    Solution sl;
    for (auto x : sl.dailyTemperatures(v))
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