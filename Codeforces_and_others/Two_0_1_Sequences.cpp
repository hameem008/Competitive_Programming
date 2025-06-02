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

void solve(int I)
{
    ll i, j, k, m, n, p;
    // solve stars
    string a, b, c;
    cin >> n >> m;
    cin >> a;
    cin >> b;
    for (i = b.size() - 1, j = a.size() - 1; i > 0; i--, j--)
    {
        if (b[i] != a[j])
        {
            cout << "NO" << line;
            return;
        }
    }
    for (j = 0; j < n - m + 1; j++)
    {
        if (b[0] == a[j])
        {
            cout << "YES" << line;
            return;
        }
    }
    cout << "NO" << line;
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
    07-10-2022 01:30
*/
