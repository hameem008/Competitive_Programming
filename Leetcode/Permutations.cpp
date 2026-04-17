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
    void rec(deque<int> &dq, vector<vector<int>> &ret, vector<int> &con)
    {
        if (dq.size() == 0)
        {
            ret.push_back(con);
            return;
        }
        int limit = dq.size();
        while (limit--)
        {
            int val = dq.front();
            con.push_back(val);
            dq.pop_front();
            rec(dq, ret, con);
            dq.push_back(val);
            con.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ret;
        vector<int> con;
        deque<int> dq;
        for (auto x : nums)
            dq.push_back(x);
        rec(dq, ret, con);
        return ret;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<int> v = {1, 2, 3, 4};
    Solution sl;
    for (auto x : sl.permute(v))
    {
        for (auto y : x)
            cout << y << gap;
        cout << endl;
    }
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