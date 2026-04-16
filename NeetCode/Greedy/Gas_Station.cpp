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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        for (int i = 0; i < n; i++)
            gas[i] -= cost[i];
        int l = 0, r = 0, sum = 0;
        int index = -1;
        while (l < n)
        {
            int ind;
            if (r >= n)
                ind = r - n;
            else
                ind = r;
            sum += gas[ind];
            if (sum < 0)
            {
                sum -= gas[l];
                if (ind != l)
                    sum -= gas[ind];
                l++;
                if (r < l)
                    r = l;
            }
            else
            {
                if (r - l + 1 == n)
                {
                    index = l;
                    break;
                }
                else
                    r++;
            }
        }
        return index;
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