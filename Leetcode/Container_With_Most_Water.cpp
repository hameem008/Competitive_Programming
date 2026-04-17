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
    int maxArea(vector<int> &heights)
    {
        int ans = 0;
        int i = 0, j = heights.size() - 1;
        while (1)
        {
            if (heights[i] > heights[j])
            {
                ans = max(ans, (j - i) * heights[j]);
                j--;
            }
            else if (heights[i] < heights[j])
            {
                ans = max(ans, (j - i) * heights[i]);
                i++;
            }
            else
            {
                ans = max(ans, (j - i) * heights[j]);
                i++, j--;
            }
            if (j - i <= 0)
                break;
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