#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, m, n, p;
    // solve stars
    cin >> n;
    vector<ll> a, b;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        a.push_back(p);
    }
    for (i = 0; i < n; i++)
    {
        cin >> p;
        b.push_back(p);
    }
    vector<ll> ans_min, ans_max;
    for (i = 0; i < n; i++)
    {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        ans_min.push_back(*it - a[i]);
    }
    ans_max.push_back(b.back() - a[n - 1]);
    ll current_high = b.back();
    for (i = n - 2; i >= 0; i--)
    {
        if (a[i + 1] <= b[i])
            ans_max.push_back(current_high - a[i]);
        else
        {
            current_high = b[i];
            ans_max.push_back(current_high - a[i]);
        }
    }
    reverse(ans_max.begin(), ans_max.end());
    for (auto x : ans_min)
        cout << x << gap;
    cout << endl;
    for (auto x : ans_max)
        cout << x << gap;
    cout << endl;
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