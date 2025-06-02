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

    ll t, i, j, k, a, b, d, c, m, n;
    cin >> t;
    while (t--)
    {
        // solve starts
        cin >> n;
        vector<ll> v(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        a = v[2] + v[1] - 2 * v[0];
        b = v[2] - v[0];
        c = 2 * v[2] - v[1] - v[0];
        ll ans = min(a, min(b, c));
        for (i = 0; i < n - 2; i++)
        {
            a = v[i + 2] + v[i + 1] - 2 * v[i];
            b = v[i + 2] - v[i];
            c = 2 * v[i + 2] - v[i + 1] - v[i];
            d = min(a, min(b, c));
            if (ans > d)
                ans = d;
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
