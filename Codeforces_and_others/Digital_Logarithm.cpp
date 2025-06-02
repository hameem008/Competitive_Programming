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

ll cnt;

int count_digit(ll n)
{
    cnt++;
    for (int i = 1; i < 10; i++)
    {
        long double a = n / pow(10, i);
        if (a < 1)
            return i;
    }
    return 0;
}

void solve(int I)
{
    ll i, j, k, m, n, p;
    // solve stars
    cnt = 0;
    cin >> n;
    multiset<ll> a, b, a2, b2;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        a.insert(p);
        a2.insert(p);
    }
    for (i = 0; i < n; i++)
    {
        cin >> p;
        b.insert(p);
        b2.insert(p);
    }
    for (auto it = a2.begin(); it != a2.end(); it++)
    {
        auto IT = b.find(*it);
        if (IT != b.end())
            b.erase(IT);
    }
    for (auto it = b2.begin(); it != b2.end(); it++)
    {
        auto IT = a.find(*it);
        if (IT != a.end())
            a.erase(IT);
    }
    vector<ll> va, vb;
    for (auto x : a)
        va.push_back(x);
    for (auto x : b)
        vb.push_back(x);
    for (i = 0; i < va.size(); i++)
    {
        if (va[i] > 9)
            va[i] = count_digit(va[i]);
        if (vb[i] > 9)
            vb[i] = count_digit(vb[i]);
    }
    a.clear();
    a2.clear();
    b.clear();
    b2.clear();
    for (i = 0; i < va.size(); i++)
    {
        a.insert(va[i]);
        a2.insert(va[i]);
        b.insert(vb[i]);
        b2.insert(vb[i]);
    }
    for (auto it = a2.begin(); it != a2.end(); it++)
    {
        auto IT = b.find(*it);
        if (IT != b.end())
            b.erase(IT);
    }
    for (auto it = b2.begin(); it != b2.end(); it++)
    {
        auto IT = a.find(*it);
        if (IT != a.end())
            a.erase(IT);
    }
    a.erase(1);
    b.erase(1);
    cout << cnt + a.size() + b.size() << line;
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
    10-10-2022 18:13
*/
