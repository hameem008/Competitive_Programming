#include <bits/stdc++.h>
#define line "\n"
using namespace std;
typedef long long ll;

#define debugging(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 arg1, Args... args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, i, j, k, a, b, m, n, q;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        map<ll, set<ll>> m;
        set<ll> s;
        ll ara[n + 1];
        ll max;
        cin >> max;
        ara[1] = max;
        for (i = 1; i < n; i++)
        {
            cin >> a;
            ara[i + 1] = a;
            if (max < a)
            {
                if (i != 1)
                {
                    m.insert(make_pair(max, s));
                    s.erase(s.begin(), s.end());
                }
                max = a;
                s.insert(i);
            }
            else
            {
                s.insert(i);
            }
            if (i == n - 1)
            {
                m.insert(make_pair(max, s));
                s.erase(s.begin(), s.end());
            }
        }
        for (j = 0; j < q; j++)
        {
            cin >> i >> k;
            auto it = m.find(ara[i]);
            if (it == m.end())
            {
                cout << 0 << line;
                continue;
            }
            auto it_low = it->second.begin();
            auto it_high = it->second.end();
            it_high--;
            if (k <= *it_high && k >= *it_low)
            {
                cout << k - *it_low + 1 << line;
            }
            else if (k < *it_low)
            {
                cout << 0 << line;
            }
            else if (k > *it_high && ara[i] == n)
            {
                cout << k - n + 1 + it->second.size() << line;
            }
            else if (k > *it_high && ara[i] != n)
            {
                cout << it->second.size() << line;
            }
        }
    }
    return 0;
}
