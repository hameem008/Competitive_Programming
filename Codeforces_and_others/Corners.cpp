#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n >> m;
    char v[n][m];
    ll one_cnt = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == '1')
                one_cnt++;
        }
    }
    ll min_one = INT_MAX;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < m - 1; j++)
        {
            multiset<char> s;
            s.insert(v[i][j]);
            s.insert(v[i][j + 1]);
            s.insert(v[i + 1][j]);
            s.insert(v[i + 1][j + 1]);
            if (s.count('1') < min_one)
                min_one = s.count('1');
        }
    }
    if (min_one == 3)
        one_cnt--;
    else if (min_one == 4)
        one_cnt -= 2;
    cout << one_cnt << endl;
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