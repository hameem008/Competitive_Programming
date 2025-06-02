/*
        "I would never fall in love again until I found her"
        I said, "I would never fall, unless it's you I fall into"
        I was lost within the darkness, but then I found her
        I found you
                                            ---Until I Found You
        lyrics from my favourite song
*/

#include <bits/stdc++.h>
#define line '\n'
using namespace std;
typedef long long ll;

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    ll t, i, j, k, a, b, m, n, p, h;
    cin >> t;
    while (t--)
    {
        // solve starts
        cin >> n >> h;
        vector<ll> v(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (n >= h)
        {
            cout << 1 << line;
            continue;
        }
        if (n == 1)
        {
            cout << h << line;
            continue;
        }
        multiset<ll> ms;
        for (i = 0; i < n - 1; i++)
        {
            ms.insert(v[i + 1] - v[i]);
        }
        ll ans = ceil(h / ((long double)ms.size() + 1));
        for (i = 0; i < n; i++)
        {
            auto it = ms.begin();
            if (ans > *it)
            {
                h = h - *it;
                ms.erase(it);
                ans = ceil((h / ((long double)ms.size() + 1)));
                if (ms.size() == 0)
                    break;
            }
            else
            {
                break;
            }
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
