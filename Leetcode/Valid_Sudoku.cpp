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
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool ans = true;
        vector<int> corner_val = {0, 3, 6};
        for (int i = 0; i < 9; i++)
        {
            vector<int> mp(10, 0);
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                mp[board[i][j] - '1']++;
                if (mp[board[i][j] - '1'] > 1)
                    return false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            vector<int> mp(10, 0);
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.')
                    continue;
                mp[board[j][i] - '1']++;
                if (mp[board[j][i] - '1'] > 1)
                    return false;
            }
        }
        for (auto x : corner_val)
            for (auto y : corner_val)
            {
                vector<int> mp(10, 0);
                for (int i = x; i < x + 3; i++)
                    for (int j = y; j < y + 3; j++)
                    {
                        if (board[i][j] == '.')
                            continue;
                        mp[board[i][j] - '1']++;
                        if (mp[board[i][j] - '1'] > 1)
                            return false;
                    }
            }
        return true;
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