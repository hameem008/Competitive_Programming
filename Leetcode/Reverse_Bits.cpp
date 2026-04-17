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
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t mask = 00000000000000000000000000000001;
        uint32_t ret = 00000000000000000000000000000000;
        int limit = 32;
        while (1)
        {
            uint32_t temp;
            if (n & mask)
                temp = 00000000000000000000000000000001;
            else
                temp = 00000000000000000000000000000000;
            ret = ret | temp;
            limit--;
            if (limit == 0)
                break;
            n /= 2;
            ret *= 2;
        }
        return ret;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    uint32_t val = 00000000000000000000000000010101;
    Solution sl;
    val = 010101;
    cout << val << endl;
    cout << sl.reverseBits(val) << endl;
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