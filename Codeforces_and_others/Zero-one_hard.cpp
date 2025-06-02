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

    ll t, i, j, k, a, b, m, x, y, n;
    cin >> t;
    while (t--)
    {
        string stra, strb;
        cin >> n >> x >> y;
        cin >> stra;
        cin >> strb;
        vector<ll> v;
        for (i = 0; i < n; i++)
        {
            if (stra[i] != strb[i])
                v.push_back(i);
        }
        if (v.size() % 2 != 0)
        {
            cout << -1 << line;
            continue;
        }
        if (v.size() == 0)
        {
            cout << 0 << line;
            continue;
        }
        ll cost = 0;
        if (x >= y)
        {
            if (v.size() == 2 && (v[1] - v[0] == 1))
            {
                a = x;
                b = 2 * y;
                if (a < b)
                    cost = cost + a;
                else
                    cost = cost + b;
            }
            else
            {
                cost = (v.size() / 2) * y;
            }
            cout << cost << line;
        }
        else
        {

            vector<ll> v2;
            set<ll> s;
            for (i = 0; i < v.size(); i++)
            {
                s.insert(v[i]);
            }
            for (i = 0; i < v.size() - 1; i++)
            {
                if (v[i + 1] - v[i] == 1)
                {
                    v2.push_back(v[i]);
                    v2.push_back(v[i + 1]);
                    i++;
                }
            }

            for (i = 0; i < v2.size(); i++)
            {
                s.erase(v2[i]);
            }

            vector<ll> v3;
            for (auto it = s.begin(); it != s.end(); it++)
            {
                v3.push_back(*it);
            }

            ll temp_cost = 0;
            if (v3.size() != 0)
            {
                for (i = 0; i < v3.size() - 1; i++)
                {
                    ll p = v3[i + 1] - v3[i];
                    if (p * x < y)
                        temp_cost = temp_cost + p * x;
                    else
                        temp_cost = temp_cost + y;
                    i++;
                }
            }
            // for (i = 0; i < v3.size() - 1; i++)
            // {
            //     ll p = v3[i + 1] - v3[i];
            //     if (p * x < y)
            //         temp_cost = temp_cost + p * x;
            //     else
            //         temp_cost = temp_cost + y;
            // }
            // cout << "ok" << line;
            // cost = (v2.size() / 2) * x + ((v.size() - v2.size()) / 2) * y;
            cost = (v2.size() / 2) * x + temp_cost;
            cout << cost << line;
        }
    }
    return 0;
}
