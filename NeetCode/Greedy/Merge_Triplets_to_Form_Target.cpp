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
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        int cnt = 0;
        for (int ind = 0; ind <= 2; ind++)
            for (auto x : triplets)
            {
                vector<int> v = {max(target[0], x[0]), max(target[1], x[1]), max(target[2], x[2])};
                if (x[ind] == target[ind] && v == target)
                {
                    cnt++;
                    break;
                }
            }
        return cnt == 3;
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