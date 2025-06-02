#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

bool isPossible(vector<ll> &v, ll n)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (abs(v[i] - n) > abs(v[i + 1] - n))
        {
            return false;
        }
    }
    return true;
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll lowest = 0, highest = 1e8;
    for (i = 0; i < n - 1; i++)
    {
        ll a1 = v[i];
        ll a2 = v[i + 1];
        ll temp_lowest, temp_highest;
        if (a1 < a2)
        {
            temp_highest = (a1 + a2) / 2;
            highest = min(temp_highest, highest);
        }
        else if (a1 > a2)
        {
            temp_lowest = (a1 + a2) / 2;
            lowest = max(lowest, temp_lowest);
        }
    }
    ll ans = -1;
    for (i = lowest; i <= highest; i++)
    {
        if (isPossible(v, i))
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
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