#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

ll keyFinder(ll n, ll m)
{
    if (n == 1)
        return n;
    if (n % m != 0)
        return n;
    while (n % m == 0)
        n = n / m;
    return n;
}

void solve(int I)
{
    ll i, j, k, m, n, p;
    // solve stars
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    cin >> k;
    vector<ll> b(k);
    for (auto &x : b)
        cin >> x;
    vector<pair<ll, ll>> ap;
    ll current_key = keyFinder(a.front(), m);
    ll previous_key = keyFinder(a.front(), m);
    ll value = 0;
    for (i = 0; i < n; i++)
    {
        current_key = keyFinder(a[i], m);
        if (current_key == previous_key)
        {
            value += a[i] / current_key;
            if (i == n - 1)
            {
                ap.push_back({previous_key, value});
            }
        }
        else
        {
            ap.push_back({previous_key, value});
            value = 0;
            previous_key = current_key;
            value += a[i] / current_key;
            if (i == n - 1)
            {
                ap.push_back({previous_key, value});
            }
        }
    }
    vector<pair<ll, ll>> bp;
    current_key = keyFinder(b.front(), m);
    previous_key = keyFinder(b.front(), m);
    value = 0;
    for (i = 0; i < k; i++)
    {
        current_key = keyFinder(b[i], m);
        if (current_key == previous_key)
        {
            value += b[i] / current_key;
            if (i == k - 1)
            {
                bp.push_back({previous_key, value});
            }
        }
        else
        {
            bp.push_back({previous_key, value});
            value = 0;
            previous_key = current_key;
            value += b[i] / current_key;
            if (i == k - 1)
            {
                bp.push_back({previous_key, value});
            }
        }
    }
    if (ap.size() != bp.size())
    {
        cout << "No" << endl;
        return;
    }
    for (i = 0; i < ap.size(); i++)
    {
        if (ap[i].first != bp[i].first)
        {
            cout << "No" << endl;
            return;
        }
        if (ap[i].second != bp[i].second)
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
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}