#include <bits/stdc++.h>
#define line '\n'
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

    ll t, i, j, k, a, b, m, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        multiset<ll> ms;
        set<ll> s;
        for (i = 0; i < n; i++)
        {
            cin >> a;
            ll count = ms.count(a % 10);
            if (count < 3)
                ms.insert(a % 10);
        }
        vector<ll> v;
        for (auto it = ms.begin(); it != ms.end(); it++)
        {
            v.push_back(*it);
        }
        bool ans = false;
        for (i = 0; i < v.size(); i++)
        {
            for (j = i + 1; j < v.size(); j++)
            {
                for (k = j + 1; k < v.size(); k++)
                {
                    ll sum = v[i] + v[j] + v[k];
                    if (sum == 3 || sum == 13 || sum == 23)
                        ans = true;
                }
            }
        }
        if (ans)
            cout << "YES" << line;
        else
            cout << "NO" << line;
    }
    return 0;
}
