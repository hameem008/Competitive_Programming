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
    bool pf(int mid, vector<int> &piles, int h)
    {
        int h_calc = 0;
        for (auto x : piles)
        {
            h_calc += ceil(x * 1.0 / mid);
        }
        return h >= h_calc;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int ans;
        int hi = 1e9, lo = 1, mid;
        while (hi - lo > 1) // FFFFTTT find first true
        {
            mid = (hi + lo) / 2;
            if (pf(mid, piles, h))
                hi = mid;
            else
                lo = mid + 1;
        }
        if (pf(lo, piles, h))
            ans = lo;
        else
            ans = hi;
        return ans;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<int> piles = {1, 4, 3, 2};
    int h = 9;
    Solution sl;
    cout << sl.minEatingSpeed(piles, h) << endl;
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