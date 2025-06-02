#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, b, c, d, m, n;
    // solve starts
    cin >> n;
    vector<ll> a(n + 1), p(n + 1, 0), q(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    set<ll> ps, qs;
    for (i = 1; i <= n; i++)
    {
        ps.insert(i);
        qs.insert(i);
    }
    for (i = 1; i <= n; i++)
    {
        if (ps.find(a[i]) != ps.end())
        {
            p[i] = a[i];
            ps.erase(a[i]);
        }
        else if (qs.find(a[i]) != qs.end())
        {
            q[i] = a[i];
            qs.erase(a[i]);
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (p[i] == 0)
        {
            auto it = ps.lower_bound(q[i]);
            if (it == ps.end())
            {
                if (ps.size() == 0)
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                {
                    it--;
                    p[i] = *it;
                    ps.erase(it);
                }
            }
            else if (it == ps.begin())
            {
                if (*it > q[i])
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                {
                    p[i] = *it;
                    ps.erase(it);
                }
            }
            else
            {
                if (*it > q[i])
                    it--;
                p[i] = *it;
                ps.erase(it);
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (q[i] == 0)
        {
            auto it = qs.lower_bound(p[i]);
            if (it == qs.end())
            {
                if (qs.size() == 0)
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                {
                    it--;
                    q[i] = *it;
                    qs.erase(it);
                }
            }
            else if (it == qs.begin())
            {
                if (*it > p[i])
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                {
                    q[i] = *it;
                    qs.erase(it);
                }
            }
            else
            {
                if (*it > p[i])
                    it--;
                q[i] = *it;
                qs.erase(it);
            }
        }
    }
    cout << "YES" << endl;
    for (i = 1; i <= n; i++)
    {
        cout << p[i] << gap;
    }
    cout << endl;
    for (i = 1; i <= n; i++)
    {
        cout << q[i] << gap;
    }
    cout << endl;
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