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
    bool exist(vector<vector<char>> &board, string word)
    {
        bool ret = false;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!ret)
                    rec(board, i, j, word, 0, ret);
        return ret;
    }
    void rec(vector<vector<char>> &board, int r, int c, string &word, int ind, bool &ret)
    {
        if (ret)
            return;
        if (ind == word.size())
        {
            ret = true;
            return;
        }
        if (r == board.size() || c == board[0].size() || r == -1 || c == -1)
            return;

        if (board[r][c] != word[ind])
            return;
        else
        {
            board[r][c] = '!';
            rec(board, r + 1, c, word, ind + 1, ret);
            rec(board, r - 1, c, word, ind + 1, ret);
            rec(board, r, c + 1, word, ind + 1, ret);
            rec(board, r, c - 1, word, ind + 1, ret);
            board[r][c] = word[ind];
        }
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