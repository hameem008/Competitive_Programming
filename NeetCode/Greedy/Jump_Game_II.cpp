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
    int jump(vector<int> &nums)
    {
        int l = 0, r = 0, res = 0;
        while (r < nums.size() - 1)
        {
            int far = 0;
            res++;
            for (int i = l; i <= r; i++)
                far = max(far, i + nums[i]);
            l = r + 1;
            r = far;
        }
        return res;
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