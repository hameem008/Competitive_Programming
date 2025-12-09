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
    bool check(vector<char> v)
    {
        bool ans = true;
        map<char, int> mp;
        for (auto x : v)
            if (x != '.')
                mp[x]++;
        for (auto x : mp)
            if (x.second > 1)
                ans = false;
        return ans;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool ans = true;
        vector<int> corner_val = {0, 3, 6};
        for (int i = 0; i < 9; i++)
        {
            vector<char> v;
            for (int j = 0; j < 9; j++)
                v.push_back(board[i][j]);
            if (!check(v))
                ans = false;
        }
        for (int i = 0; i < 9; i++)
        {
            vector<char> v;
            for (int j = 0; j < 9; j++)
                v.push_back(board[j][i]);
            if (!check(v))
                ans = false;
        }
        for (auto x : corner_val)
        {
            for (auto y : corner_val)
            {
                vector<char> v;
                for (int i = x; i < x + 3; i++)
                {
                    for (int j = y; j < y + 3; j++)
                    {
                        v.push_back(board[i][j]);
                    }
                }
                if (!check(v))
                    ans = false;
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