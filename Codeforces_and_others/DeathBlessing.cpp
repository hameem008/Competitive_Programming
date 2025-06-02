#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, n, p;
    // solve stars
    cin >> n;
    multimap<ll, pair<ll, ll>> m;
    vector<ll> v1(n), v2(n);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> v2[i];
    }
    ll sum1 = 0, sum2 = 0;
    sort(v2.begin(), v2.end());
    v2.pop_back();
    for (i = 0; i < n; i++)
    {
        sum1 += v1[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        sum2 += v2[i];
    }
    cout << sum1 + sum2 << endl;
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