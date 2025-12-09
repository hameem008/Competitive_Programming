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
    int calc(vector<int> &v)
    {
        int water_height = min(v.front(), v.back());
        int ans = (v.size() - 2) * water_height;
        for (int i = 1; i < v.size() - 1; i++)
            ans -= v[i];
        return max(ans, 0);
    }
    int trap(vector<int> &height)
    {
        int ans = 0;
        vector<int> v;
        multiset<int> ms(height.begin(), height.end());
        int max_h;
        for (int i = 0; i < height.size(); i++)
        {
            if (height[i] >= max_h || i == height.size() - 1 || i == 0)
            {
                if (i == 0)
                {
                    v.push_back(height[i]);
                    ms.erase(ms.find(height[i]));
                }
                else
                {
                    v.push_back(height[i]);
                    ans += calc(v);
                    v.clear();
                    v.push_back(height[i]);
                    ms.erase(ms.find(height[i]));
                }
                if (ms.size())
                {
                    auto it = ms.lower_bound(height[i]);
                    if (it == ms.end())
                        it--;
                    max_h = *it;
                }
            }
            else
            {
                v.push_back(height[i]);
                ms.erase(ms.find(height[i]));
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
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    Solution sl;
    cout << sl.trap(v) << endl;
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