#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '

vector<int> v(1e5 + 8);
vector<int> dp(1e5 + 8, -1);
int n;

int fun(int n)
{
    if (n == 0)
        return dp[0] = 1;
    if (dp[n] == -1)
    {
        int max = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v[n] > v[n - i] && max < fun(n - i))
                max = fun(n - i);
        }
        dp[n] = max + 1;
    }
    return dp[n];
}

void solve(int I, int T)
{
    int i, j, k, a, b, c, d, m, p, q;
    bool flag;
    // solve starts
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (i = 0; i < n; i++)
    {
        fun(i);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}