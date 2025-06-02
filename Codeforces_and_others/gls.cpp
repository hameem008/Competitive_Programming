/*
        "I would never fall in love again until I found her"
        I said, "I would never fall, unless it's you I fall into"
        I was lost within the darkness, but then I found her
        I found you
                                            ---Until I Found You
        lyrics from my favourite song
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define line '\n'
#define gap ' '
typedef long long ll;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

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

vector<ll> v;
ll m;

int f(ll s)
{
    for (int i = 9; i >= 0; i--)
    {
        if (i <= s)
        {
            v.push_back(i);
            break;
        }
    }
    if (v.size() == m)
        return 0;
    return f(s - v[v.size() - 1]);
}

void solve(int I)
{
    ll i, j, s, k, a, b, n, p;
    // solve stars
    cin >> m >> s;
    if ((s < 1 && m > 1) || s > m * 9)
    {
        cout << "-1 -1" << line;
        return;
    }
    f(s);
    reverse(v.begin(), v.end());
    if (v[0] == 0)
    {
        for (i = 0; i < v.size(); i++)
        {
            if (v[i] != 0)
                break;
        }
        if (v.size() != 1)
            v[0]++;
        v[i]--;
    }
    for (i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    cout << gap;
    v.clear();
    f(s);
    for (i = 0; i < v.size(); i++)
    {
        cout << v[i];
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
    // cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}

/*
    Ha Meem
    from BUET CSE-20
    hameem812@gmail.com
    09-10-2022 23:20
*/
