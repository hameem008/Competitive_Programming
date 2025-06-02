#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n >> m >> k;
    deque<ll> color;
    for (i = 0; i < k; i++)
    {
        cin >> a;
        color.push_back(a);
    }
    sort(color.begin(), color.end());
    reverse(color.begin(), color.end());
    bool flag = false;
    if (color.front() >= m * n)
    {
        flag = true;
    }
    else
    {
        if (m % 2 == 0)
        {
            ll ans = 0;
            deque<ll> dum;
            for (auto x : color)
            {
                if (x >= 2 * n)
                {
                    dum.push_back(x - 2 * n);
                    ans += 2;
                }
            }
            sort(dum.begin(), dum.end());
            for (auto x : dum)
            {
                ans += x / n;
            }
            if (ans >= m)
                flag = true;
        }
        else
        {
            ll ans = 0;
            deque<ll> dum;
            for (auto x : color)
            {
                if (x >= 2 * n)
                {
                    dum.push_back(x - 2 * n);
                    ans += 2;
                }
                if (ans == m - 1)
                    break;
            }
            sort(dum.begin(), dum.end());
            for (auto x : dum)
            {
                ans += x / n;
            }
            if (ans >= m)
                flag = true;
        }

        if (n % 2 == 0)
        {
            ll ans = 0;
            deque<ll> dum;
            for (auto x : color)
            {
                if (x >= 2 * m)
                {
                    dum.push_back(x - 2 * m);
                    ans += 2;
                }
            }
            sort(dum.begin(), dum.end());
            for (auto x : dum)
            {
                ans += x / m;
            }
            if (ans >= n)
                flag = true;
        }
        else
        {
            ll ans = 0;
            deque<ll> dum;
            for (auto x : color)
            {
                if (x >= 2 * m)
                {
                    dum.push_back(x - 2 * m);
                    ans += 2;
                }
                if (ans == n - 1)
                    break;
            }
            sort(dum.begin(), dum.end());
            for (auto x : dum)
            {
                ans += x / m;
            }
            if (ans >= n)
                flag = true;
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}