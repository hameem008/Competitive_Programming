/*
        Make sure to keep my distance
        Say, "I love you," when you're not listening
        How long 'til we call this love, love, love?
        ---Distance

        lyrics from my favourite song
*/
#include <bits/stdc++.h>
#define line '\n'
using namespace std;
typedef long long ll;

// #define debugging(...) __f(#__VA_ARGS__, __VA_ARGS__)
// template <typename Arg1>
// void __f(const char *name, Arg1 arg1)
// {
//     cout << name << " : " << arg1 << endl;
// }
// template <typename Arg1, typename... Args>
// void __f(const char *names, Arg1 arg1, Args... args)
// {
//     const char *comma = strchr(names + 1, ',');
//     cout.write(names, comma - names) << " : " << arg1 << " | ";
//     __f(comma + 1, args...);
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, i, j, k, a, b, m, n, x, p;
    cin >> t;
    while (t--)
    {
        // solve starts
        cin >> n >> x;
        multiset<ll> ms;
        ll sum = 0;
        for (i = 0; i < n; i++)
        {
            cin >> p;
            sum = sum + p;
            ms.insert(p);
        }
        ll ans = 0;
        ll N = x - *ms.begin() + 1;
        ll r = 1;
        for (i = 0; i <= N;)
        {
            if (x >= sum)
            {
                ans = ans + ms.size() * r;
                r = floor((x - sum) / ms.size());
                ll q = sum + ms.size() * r;
                if (x >= q && r > 0)
                {
                    // ans = ans + ms.size() * r;
                    sum = sum + ms.size() * r;
                    i = i + r;
                }
                else
                {
                    sum = sum + ms.size() * 1;
                    i++;
                    r = 1;
                }
            }
            else
            {
                auto it = ms.end();
                it--;
                sum = sum - *it - i;
                ms.erase(it);
            }

            if (ms.size() == 0)
                break;
        }
        cout << ans << line;
        // solve ends
    }
    return 0;
}
/*
    Ha Meem
    from BUET CSE-20
    hameem812@gmail.com
*/
