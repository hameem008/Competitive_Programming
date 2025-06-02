#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n >> m;
    vector<ll> v(n + 1, 0);
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a]++;
        v[b]++;
    }
    ll two_count = 0, one_count = 0;
    for (i = 1; i <= n; i++)
    {
        if (v[i] == 2)
            two_count++;
        else if (v[i] == 1)
            one_count++;
    }
    ll max = *max_element(v.begin(), v.end());
    if (max == n - 1 && one_count == n - 1)
    {
        cout << "star topology" << endl;
        return;
    }
    if (two_count == n)
    {
        cout << "ring topology" << endl;
        return;
    }
    if (two_count == n - 2 && one_count == 2)
    {
        cout << "bus topology" << endl;
        return;
    }
    cout << "unknown topology" << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}