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
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        auto cmp = [](vector<int> a, vector<int> b)
        {
            return sqrt(a[0] * a[0] + a[1] * a[1]) > sqrt(b[0] * b[0] + b[1] * b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (auto x : points)
            pq.push(x);
        vector<vector<int>> ret;
        while (k--)
        {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
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