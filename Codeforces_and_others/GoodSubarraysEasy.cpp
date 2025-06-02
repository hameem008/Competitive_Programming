#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    vector<ll> v(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    ll con = 0, add;
    for (i = 1; i <= n; i++)
    {
        if (v[i] >= i)
            con++;
        else
            break;
    }
    ll sum = con * (con + 1) / 2;
    for (; i <= n; i++)
    {
        if (con == v[i])
            add = con;
        else if (con < v[i])
            add = con + 1;
        else
            add = v[i];
        sum += add * (add + 1) / 2 - add * (add - 1) / 2;
        con = add;
    }
    cout << sum << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}