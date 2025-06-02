#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    int v[n][n];
    bool flag = true;
    ll first = 1, last = n * n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (flag)
            {
                v[i][j] = first;
                first++;
                flag = false;
            }
            else
            {
                v[i][j] = last;
                last--;
                flag = true;
            }
        }
    }
    if (n % 2 == 0)
    {
        for (i = 1; i < n; i += 2)
        {
            reverse(v[i], v[i] + n);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << v[i][j] << gap;
        }
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}