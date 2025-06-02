#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n >> k;
    if (n % 2 == 0)
    {
        vector<ll> v1, v2;
        int flag = 1;
        for (i = 1, j = n; i <= n / 2; i++, j--)
        {
            if (flag == 1)
            {
                v1.push_back(j);
                v1.push_back(i);
                flag = 2;
            }
            else
            {
                v2.push_back(j);
                v2.push_back(i);
                flag = 1;
            }
        }
        reverse(v2.begin(), v2.end());
        for (auto x : v1)
            cout << x << gap;
        for (auto x : v2)
            cout << x << gap;
        cout << endl;
    }
    else
    {
        vector<ll> v1, v2;
        int flag = 1;
        for (i = 1, j = n; i <= n / 2; i++, j--)
        {
            if (flag == 1)
            {
                v1.push_back(j);
                v1.push_back(i);
                flag = 2;
            }
            else
            {
                v2.push_back(j);
                v2.push_back(i);
                flag = 1;
            }
        }
        v1.push_back(n / 2 + 1);
        reverse(v2.begin(), v2.end());
        for (auto x : v1)
            cout << x << gap;
        for (auto x : v2)
            cout << x << gap;
        cout << endl;
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