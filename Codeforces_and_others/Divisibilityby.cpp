#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

ll twoPowerCount(ll a)
{
    ll n = log(a) / log(2);
    ll count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a % 2 != 0)
        {
            break;
        }
        else
        {
            count++;
            a = a / 2;
        }
    }
    return count;
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    vector<ll> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll count_power = 0;
    for (i = 0; i < n; i++)
    {
        count_power = count_power + twoPowerCount(v[i]);
    }
    if (count_power >= n)
    {
        cout << 0 << endl;
        return;
    }
    ll operation = 0;
    multiset<ll> ms;
    for (i = 2; i <= n; i = i + 2)
    {
        ms.insert(twoPowerCount(i));
    }
    for (auto it = ms.rbegin(); it != ms.rend(); it++)
    {
        count_power = count_power + *it;
        operation++;
        if (count_power >= n)
        {
            cout << operation << endl;
            return;
        }
    }
    cout << -1 << endl;
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