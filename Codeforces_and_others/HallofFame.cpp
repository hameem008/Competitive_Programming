#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    string str;
    cin >> n;
    cin >> str;
    ll ind_firstR = n, ind_lastL = -1;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == 'L')
        {
            if (i > ind_lastL)
                ind_lastL = i;
        }
        if (str[i] == 'R')
        {
            if (i < ind_firstR)
                ind_firstR = i;
        }
    }
    if (ind_firstR == n || ind_lastL == -1)
    {
        cout << -1 << endl;
    }
    else
        cout << ind_firstR << endl;
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