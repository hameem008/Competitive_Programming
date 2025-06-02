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

    ll t, i, j, k, a, b, c, m, n;
    cin >> t;
    while (t--)
    {
        // solve starts
        cin >> n >> c;
        multiset<ll> ms;
        for (i = 0; i < n; i++)
        {
            cin >> a;
            ms.insert(a);
        }
        vector<ll> v;
        for (i = 1; i <= 100; i++)
        {
            ll cnt = ms.count(i);
            if (cnt != 0)
                v.push_back(cnt);
        }
        ll ans = 0;
        for (i = 0; i < v.size(); i++)
        {
            if (c < v[i])
                ans = ans + c;
            else
                ans = ans + v[i];
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
