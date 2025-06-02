#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n >> k;
    vector<ll> v(n);
    multimap<ll, ll> mp;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll low_index = n - 1 - k;
    ll high_index = k;
    low_index++;
    high_index--;
    if (low_index > high_index)
    {
        cout << "YES" << endl;
        return;
    }
    vector<ll> sortv(v.begin(), v.end());
    sort(sortv.begin(), sortv.end());
    for (i = low_index; i <= high_index; i++)
    {
        if (sortv[i] != v[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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