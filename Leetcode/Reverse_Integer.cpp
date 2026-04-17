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
    int reverse(int x)
    {
        int ret = 0;
        while (1)
        {
            ret = ret * 10 + (x % 10);
            x /= 10;
            if (x == 0)
                break;
            if (ret > INT32_MAX / 10 || ret < INT32_MIN / 10)
                return 0;
            else if (ret == INT32_MAX / 10)
            {
                if (x % 10 > INT32_MAX % 10)
                    return 0;
            }
            else if (ret == INT32_MIN / 10)
            {
                if (x % 10 < INT32_MIN % 10)
                    return 0;
            }
        }
        return ret;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cout << -101 % 10 << endl;
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