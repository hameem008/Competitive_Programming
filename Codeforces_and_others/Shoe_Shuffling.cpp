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
#define gap " "
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

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    multimap<ll, pair<ll, ll>> mmp;
    multiset<ll> ms;
    for (i = 1; i <= n; i++)
    {
        cin >> p;
        ms.insert(p);
        mmp.insert(make_pair(p, make_pair(i, i)));
    }
    for (auto it = ms.begin(); it != ms.end(); it++)
    {
        if (ms.count(*it) == 1)
        {
            cout << -1 << line;
            return;
        }
    }
    auto it1 = mmp.begin();
    auto it2 = mmp.begin();
    it2++;
    for (i = 0; i < mmp.size() - 1; i++)
    {
        if (it1->first == it2->first)
        {
            //swap(it1->second.second, it2->second.second);
            ll sw=it1->second.second;
            it1->second.second=it2->second.second;
            it2->second.second=sw;
        }
        it1++;
        it2++;
    }
    auto IT = mmp.begin();
    vector<ll> v(n + 1);
    for (i = 1; i <= n; i++)
    {
        v[IT->second.first] = IT->second.second;
        IT++;
    }
    for (i = 1; i <= n; i++)
    {
        cout << v[i] << gap;
    }
    cout << line;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}

/*
    Ha Meem
    from BUET CSE-20
    hameem812@gmail.com
*/
