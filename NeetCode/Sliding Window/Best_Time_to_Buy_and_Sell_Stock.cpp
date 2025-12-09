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
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        multiset<int> ms(prices.begin(), prices.end());
        for (auto x : prices)
        {
            ms.erase(ms.find(x));
            if (ms.size())
            {
                auto it = ms.end();
                it--;
                ans = max(ans, *it - x);
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