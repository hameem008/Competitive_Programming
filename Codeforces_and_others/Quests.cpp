#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

vector<ll> v;

bool func(ll c, ll d, ll k)
{
    vector<ll> dummy;
    if (v.size() > k)
    {
        for (int i = 0; i < k + 1; i++)
        {
            dummy.push_back(v[i]);
        }
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            dummy.push_back(v[i]);
        }
        for (int i = 0; i < k - v.size() + 1; i++)
        {
            dummy.push_back(0);
        }
    }
    ll sum = 0;
    if (dummy.size() < d)
    {
        for (int i = 0; i < dummy.size(); i++)
        {
            sum += dummy[i];
        }
        sum = (d / dummy.size()) * sum;
        for (int i = 0; i < d % dummy.size(); i++)
        {
            sum += dummy[i];
        }
    }
    else
    {
        for (int i = 0; i < d; i++)
        {
            sum += dummy[i];
        }
    }
    if (sum >= c)
        return true;
    else
        return false;
}

void solve(int I)
{
    ll i, j, k, a, c, d, b, m, n, p;
    // solve stars
    v.clear();

    cin >> n >> c >> d;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        v.push_back(p);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    if (func(c, d, d + 1))
    {
        cout << "Infinity" << endl;
        return;
    }
    if (func(c, d, 0) == false)
    {
        cout << "Impossible" << endl;
        return;
    }
    ll high = d + 1, low = 0;
    while (high - low > 1)
    {
        ll mid = (high + low) / 2;
        if (func(c, d, mid) == false)
        {
            high = mid - 1;
        }
        else
        {
            low = mid;
        }
    }
    if (func(c, d, high))
    {
        cout << high << endl;
        return;
    }
    else if (func(c, d, low))
    {
        cout << low << endl;
        return;
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