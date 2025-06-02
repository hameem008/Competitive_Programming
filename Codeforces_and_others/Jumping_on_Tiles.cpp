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
        string str;
        cin >> str;
        multimap<char, ll> mm;
        for (i = 0; i < str.size(); i++)
        {
            mm.insert(make_pair(str[i], i + 1));
        }
        char first = str[0], last = str[str.size() - 1];
        //multiset<pair<char, ll>> ms;
        multimap<char,ll>ms;
        if (first > last)
        {
            ms.insert(make_pair(str[str.size() - 1], str.size() - 1));
            for (i = 1; i < str.size() - 1; i++)
            {
                if (str[i] >= last && str[i] <= first)
                {
                    ms.insert(make_pair(str[i], i));
                }
            }
            ms.insert(make_pair(str[0], 0));
            cout << ms.rbegin()->first - ms.begin()->first << " " << ms.size() << line;
            for (auto it_1 = ms.rbegin(); it_1 != ms.rend(); it_1++)
            {
                cout << it_1->second + 1 << " ";
            }
            cout << line;
        }
        else if (first <= last)
        {
            ms.insert(make_pair(str[0], 0));
            for (i = 1; i < str.size() - 1; i++)
            {
                if (str[i] >= first && str[i] <= last)
                {
                    ms.insert(make_pair(str[i], i));
                }
            }
            ms.insert(make_pair(str[str.size() - 1], str.size() - 1));
            cout << ms.rbegin()->first - ms.begin()->first << " " << ms.size() << line;
            for (auto it_1 = ms.begin(); it_1 != ms.end(); it_1++)
            {
                cout << it_1->second + 1 << " ";
            }
            cout << line;
        }
        // solve ends
    }
    return 0;
}

/*
    Ha Meem
    from BUET CSE-20
    hameem812@gmail.com
*/
