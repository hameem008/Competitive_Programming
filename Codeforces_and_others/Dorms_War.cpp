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
        string str;
        cin >> str;
        cin >> k;
        set<char> s;
        for (i = 0; i < k; i++)
        {
            char q;
            cin >> q;
            s.insert(q);
        }
        vector<ll> v;
        v.push_back(0);
        v.push_back(0);
        for (i = 0; i < n; i++)
        {
            s.insert(str[i]);
            if (k != s.size())
            {
                s.erase(str[i]);
            }
            else
            {
                v.push_back(i);
            }
        }
        set<ll> si;
        for (i = 0; i < v.size() - 1; i++)
        {
            si.insert(v[i + 1] - v[i]);
        }
        cout << *si.rbegin() << line;
        // solve ends
    }
    return 0;
}

/*
    Ha Meem
    from BUET CSE-20
    hameem812@gmail.com
*/
