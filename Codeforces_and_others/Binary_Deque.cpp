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
    ll i, j, k, a, b, m, n, p, s;
    // solve stars
    cin >> n >> s;
    deque<ll> d;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        if (p == 1)
            d.push_back(i);
    }
    if (d.size() <= s)
    {
        if (d.size() == s)
        {
            cout << 0 << line;
        }
        else
        {
            cout << -1 << line;
        }
        return;
    }
    d.push_front(-1);
    d.push_back(n);
    ll size = d.size();
    set<ll> st;
    for (i = 1; i < size - s; i++)
    {
        st.insert(d[i - 1] - d[0] + d[size - 1] - d[i + s]);
    }
    cout << *st.begin() << line;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
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
