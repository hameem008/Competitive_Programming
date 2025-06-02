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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, i, j, k, a, b, m, n, p;
    cin >> t;
    while (t--)
    {
        // solve starts
        cin >> n;
        vector<string> v(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i][0] > v[i][1])
                swap(v[i][0], v[i][1]);
        }
        multimap<char, char> m;
        for (i = 0; i < n; i++)
        {
            m.insert(make_pair(v[i][0], v[i][1]));
        }
        for(auto itt=m.begin();itt!=m.end();itt++) debug(itt->first,itt->second);
        ll ans = 0;
        for (char ch = 'a'; ch < 'l'; ch++)
        {
            auto it = m.lower_bound(ch);

            if (it == m.end())
                continue;
            cout << ch << line;
            ll N = m.count(ch);
            set<char> s;
            for (i = 0; i < N; i++)
            {
                s.insert(it->second);
                it++;
            }
            ans = ans + (s.size() - 2) * (s.size() - 1) / 2 + s.size() - 1;
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
