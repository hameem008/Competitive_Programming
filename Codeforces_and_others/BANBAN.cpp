#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars //
    cin >> n;
    m = n;
    if (n == 1)
    {
        cout << 1 << endl;
        cout << "1 3" << endl;
        return;
    }
    if (n == 2)
    {
        cout << 1 << endl;
        cout << "1 6" << endl;
        return;
    }
    ll count = 0;
    if (n % 2 == 0)
        count = n / 2;
    else
        count = (n + 1) / 2;
    j = 1;
    k = 3 * m;
    vector<ll> vb, vn;
    for (i = 0; i < count; i++)
    {
        vb.push_back(j);
        j += 3;
        vn.push_back(k);
        k -= 3;
    }
    cout << count << endl;
    for (i = 0; i < count; i++)
    {
        cout << vb[i] << gap << vn[i] << endl;
    }
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