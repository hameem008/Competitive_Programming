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
#include <ext/pb_ds/tree_policy.hpp>
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

bool is_divisible(ll a, ll b)
{
    if (b / a >= 1 && b % a == 0)
        return true;
    else
        return false;
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    vector<ll> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (n == 1)
    {
        cout << "YES" << line;
        return;
    }
    vector<ll> ar(n + 1);
    ar[0] = v[0];
    for (i = 1; i < n; i++)
    {
        ar[i] = (v[i] * v[i - 1]) / __gcd(v[i], v[i - 1]);
    }
    ar[n] = v.back();
    vector<ll> lit;
    for (i = 0; i < n; i++)
    {
        lit.push_back(__gcd(ar[i], ar[i + 1]));
    }
    for (i = 0; i < n; i++)
    {
        if (v[i] != lit[i])
        {
            cout << "NO" << line;
            return;
        }
    }
    cout << "YES" << line;
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
    hameem812@gmail.com
    10-10-2022 21:17
*/
