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
    map<char, ll> s, t;
    s.insert({'a', 1});
    t.insert({'a', 1});
    for (i = 0; i < n; i++)
    {
        string x;
        cin >> a >> k >> x;
        if (a == 1)
        {
            for (j = 0; j < x.size(); j++)
            {
                auto it = s.find(x[j]);
                if (it != s.end())
                    it->second += k;
                else
                    s.insert({x[j], k});
            }
        }
        else if (a == 2)
        {
            for (j = 0; j < x.size(); j++)
            {
                auto it = t.find(x[j]);
                if (it != t.end())
                    it->second += k;
                else
                    t.insert({x[j], k});
            }
        }
        auto s_it = s.begin();
        auto t_it = t.rbegin();
        if (t_it->first != 'a')
        {
            cout << "YES" << endl;
        }
        else
        {
            if (s_it->second > t_it->second)
            {
                cout << "NO" << endl;
            }
            else if (s_it->second == t_it->second)
            {
                cout << "NO" << endl;
            }
            else
            {
                s_it++;
                if (s_it == s.end())
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
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