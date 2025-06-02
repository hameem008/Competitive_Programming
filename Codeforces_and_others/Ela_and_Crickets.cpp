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
    ll i, j, k, a, b, m, n, p;
    // solve stars
    pair<ll, ll> cric1, cric2, cric3, mid, side1, side2, goal;
    cin >> n;
    cin >> cric1.first >> cric1.second >> cric2.first >> cric2.second >> cric3.first >> cric3.second;
    cin >> goal.first >> goal.second;
    set<pair<ll, ll>> s;
    s.insert({1, 1});
    s.insert({1, n});
    s.insert({n, 1});
    s.insert({n, n});
    if (cric1.first != cric2.first && cric1.second != cric2.second)
    {
        mid.first = cric3.first;
        mid.second = cric3.second;
        side1.first = cric1.first;
        side1.second = cric1.second;
        side2.first = cric2.first;
        side2.second = cric2.second;
    }
    else if (cric1.first != cric3.first && cric1.second != cric3.second)
    {
        mid.first = cric2.first;
        mid.second = cric2.second;
        side1.first = cric1.first;
        side1.second = cric1.second;
        side2.first = cric3.first;
        side2.second = cric3.second;
    }
    else if (cric2.first != cric3.first && cric2.second != cric3.second)
    {
        mid.first = cric1.first;
        mid.second = cric1.second;
        side1.first = cric2.first;
        side1.second = cric2.second;
        side2.first = cric3.first;
        side2.second = cric3.second;
    }
    s.insert(mid);
    if (s.size() == 4)
    {
        if (goal.first == mid.first || goal.second == mid.second)
        {
            cout << "YES" << line;
        }
        else
        {
            cout << "NO" << line;
        }
    }
    else if (mid.first % 2 == 0 && mid.second % 2 == 0)
    {
        if (goal.first % 2 != 0 && goal.second % 2 != 0)
        {
            cout << "NO" << line;
        }
        else
        {
            cout << "YES" << line;
        }
    }
    else if (mid.first % 2 != 0 && mid.second % 2 == 0)
    {
        if (goal.first % 2 == 0 && goal.second % 2 != 0)
        {
            cout << "NO" << line;
        }
        else
        {
            cout << "YES" << line;
        }
    }
    else if (mid.first % 2 == 0 && mid.second % 2 != 0)
    {
        if (goal.first % 2 != 0 && goal.second % 2 == 0)
        {
            cout << "NO" << line;
        }
        else
        {
            cout << "YES" << line;
        }
    }
    else if (mid.first % 2 != 0 && mid.second % 2 != 0)
    {
        if (goal.first % 2 == 0 && goal.second % 2 == 0)
        {
            cout << "NO" << line;
        }
        else
        {
            cout << "YES" << line;
        }
    }
    // cout << mid.first << gap << mid.second << line;
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
    08-10-2022 20:02
*/
