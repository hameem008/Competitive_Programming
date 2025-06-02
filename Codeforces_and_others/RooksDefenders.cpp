#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n >> q;
    vector<ll> freeRowsCheck(n + 1, 0);
    vector<ll> freeColumsCheck(n + 1, 0);
    set<ll> freeRows, freeColums;
    for (i = 1; i <= n; i++)
    {
        freeRows.insert(i);
        freeColums.insert(i);
    }
    while (q--)
    {
        cin >> c;
        if (c == 1)
        {
            ll x, y;
            cin >> x >> y;
            freeRows.erase(x);
            freeColums.erase(y);
            freeRowsCheck[x]++;
            freeColumsCheck[y]++;
        }
        else if (c == 2)
        {
            ll x, y;
            cin >> x >> y;
            freeRowsCheck[x]--;
            freeColumsCheck[y]--;
            if (!freeRowsCheck[x])
                freeRows.insert(x);
            if (!freeColumsCheck[y])
                freeColums.insert(y);
        }
        else if (c == 3)
        {
            ll x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            auto itx1 = freeRows.lower_bound(x1);
            auto itx2 = freeRows.upper_bound(x2);
            auto ity1 = freeColums.lower_bound(y1);
            auto ity2 = freeColums.upper_bound(y2);
            bool flag = false;
            if (itx1 == itx2)
                flag = true;
            if (ity1 == ity2)
                flag = true;
            if (flag)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
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