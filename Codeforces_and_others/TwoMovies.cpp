#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> va(n + 1), vb(n + 1);
    for (i = 1; i <= n; i++)
        cin >> va[i];
    for (i = 1; i <= n; i++)
        cin >> vb[i];
    ll mov1 = 0, mov2 = 0;
    for (i = 1; i <= n; i++)
    {
        if (va[i] == 1 && (vb[i] == -1 || vb[i] == 0))
        {
            mov1++;
        }
        else if (vb[i] == 1 && (va[i] == -1 || va[i] == 0))
        {
            mov2++;
        }
    }
    ll cntp = 0, cntm = 0;
    for (i = 1; i <= n; i++)
    {
        if (va[i] == -1 && vb[i] == -1)
        {
            cntm++;
        }
        else if (va[i] == 1 && vb[i] == 1)
        {
            cntp++;
        }
    }
    if (mov1 > mov2)
    {
        if (mov2 + cntp > mov1)
        {
            cntp -= (mov1 - mov2);
            mov2 = mov1;
        }
        else
        {
            mov2 += cntp;
            cntp = 0;
        }
    }
    else if (mov1 < mov2)
    {
        if (mov1 + cntp > mov2)
        {
            cntp -= (mov2 - mov1);
            mov1 = mov2;
        }
        else
        {
            mov1 += cntp;
            cntp = 0;
        }
    }

    if (mov1 > mov2)
    {
        if (mov1 - cntm > mov2)
        {
            mov1 -= cntm;
            cntm = 0;
        }
        else
        {
            cntm -= (mov1 - mov2);
            mov1 = mov2;
        }
    }
    else if (mov1 < mov2)
    {
        if (mov2 - cntm > mov1)
        {
            mov2 -= cntm;
            cntm = 0;
        }
        else
        {
            cntm -= (mov2 - mov1);
            mov2 = mov1;
        }
    }

    if (mov1 == mov2)
    {
        ll add = cntp - cntm;
        cout << floor((mov1 + mov2 + add) / 2.0) << endl;
    }
    else
    {
        cout << min(mov1, mov2) << endl;
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