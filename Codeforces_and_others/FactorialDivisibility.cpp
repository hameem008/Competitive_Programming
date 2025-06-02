#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, x, b, m, n, p;
    // solve stars
    cin >> n >> k;
    vector<ll> v(k + 1);
    fill(v.begin(), v.end(), 0);
    for (i = 0; i < n; i++)
    {
        cin >> p;
        v[p]++;
    }
    for (i = 1; i < k; i++)
    {
        if (v[i] % (i + 1) == 0)
        {
            v[i + 1] += v[i] / (i + 1);
        }
        else
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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