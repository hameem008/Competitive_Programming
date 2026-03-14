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
    int sz;
    vector<int>  cols_occ;
    vector<pair<int, int>> queen_cord;
    vector<vector<string>> ret;
    vector<string> con;
    void rec(int n, int i)
    {
        if (n == 0)
        {
            ret.push_back(con);
            return;
        }

        for (int j = 0; j < sz; j++)
            if (cols_occ[j] == 0)
            {
                bool flag = true;
                for (auto x : queen_cord)
                    if (abs(x.first - i) == abs(x.second - j))
                        flag = false;
                if (flag)
                {
                    cols_occ[j] = 1;
                    queen_cord.push_back({i, j});
                    con[i][j] = 'Q';
                    rec(n - 1, i + 1);
                    con[i][j] = '.';
                    queen_cord.pop_back();
                    cols_occ[j] = 0;
                }
            }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        sz = n;
        cols_occ.assign(sz, 0);
        string str;
        for (int i = 0; i < sz; i++)
            str.push_back('.');
        for (int i = 0; i < sz; i++)
            con.push_back(str);
        rec(n, 0);
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