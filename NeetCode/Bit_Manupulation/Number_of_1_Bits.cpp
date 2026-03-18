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
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        uint32_t mask = 01;
        while (n)
        {
            if (n & mask)
                cnt++;
            n /= 2;
        }
        return cnt;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, p, q;
    bool flag;
    // solve starts
    uint32_t n = 00011011;
    Solution sl;
    cout << sl.hammingWeight(n) << endl;
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