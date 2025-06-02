#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    string str;
    cin >> str;
    deque<ll> d;
    for (i = 0; i < n; i++)
    {
        if (str[i] == '0')
            d.push_back(0);
        else
            d.push_back(1);
    }
    while (1)
    {
        if (d.size() == 0)
            break;
        if (d.front() == 0)
            d.pop_front();
        else
            break;
    }
    while (1)
    {
        if (d.size() == 0)
            break;
        if (d.front() == 1)
            d.pop_front();
        else
            break;
    }
    if (d.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (d.size() == 1)
    {
        cout << 1 << endl;
        return;
    }
    ll seg = 0;
    for (i = 0; i < d.size() - 1; i++)
    {
        if (d[i] != d[i + 1])
            seg++;
    }
    seg++;
    cout << seg << endl;
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