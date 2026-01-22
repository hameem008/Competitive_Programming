#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, m;
    cin >> t;
    for (int K = 1; K <= t; K++)
    {
        cin >> n >> m;

        vector<vector<int>> inp(n, vector<int>(m, 0)), vl(n, vector<int>(m, 0)), vr(n, vector<int>(m, 0)), vu(n, vector<int>(m, 0)), vd(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> inp[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
            {
                if (inp[i][j] == inp[i][j - 1])
                    vl[i][j] = vl[i][j - 1];
                else
                    vl[i][j] = j;
            }

        for (int i = 0; i < n; i++)
            for (int j = m - 1; j >= 0; j--)
            {
                if (j == m - 1 || inp[i][j] != inp[i][j + 1])
                    vr[i][j] = j;
                else
                    vr[i][j] = vr[i][j + 1];
            }

        for (int j = 0; j < m; j++)
            for (int i = 1; i < n; i++)
            {
                if (inp[i][j] == inp[i - 1][j])
                    vu[i][j] = vu[i - 1][j];
                else
                    vu[i][j] = i;
            }

        for (int j = 0; j < m; j++)
            for (int i = n - 1; i >= 0; i--)
            {
                if (i == n - 1 || inp[i][j] != inp[i + 1][j])
                    vd[i][j] = i;
                else
                    vd[i][j] = vd[i + 1][j];
            }

        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (vd[i][j] == i || vu[i][j] == i || vl[i][j] == j || vr[i][j] == j)
                    continue;
                ans = max(ans, vd[i][j] - vu[i][j] + vr[i][j] - vl[i][j] + 1);
            }
        }
        cout << "Case " << K << ": " << ans << "\n";
    }
}