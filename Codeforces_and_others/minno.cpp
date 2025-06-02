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
    string str;
    cin >> str;
    vector<ll> v;
    for (i = 0; i < str.size(); i++)
    {
        v.push_back(str[i] - 48);
    }
    vector<ll> wont_change;
    set<ll> last_mini_find;
    ll last_mini;
    last_mini_find.insert(v[v.size() - 1]);
    for (i = v.size() - 1; i >= 0; i--)
    {
        last_mini_find.insert(v[i]);
        auto it = last_mini_find.begin();
        if (*it != v[i])
        {
            last_mini = *last_mini_find.begin();
            break;
        }
        if (i == 0)
            last_mini = v[0];
    }
    for (i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] == last_mini)
        {
            wont_change.push_back(v[i]);
            v[i] = 11;
            break;
        }
        else
        {
            wont_change.push_back(v[i]);
            v[i] = 11;
        }
    }
    for (i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] <= last_mini)
        {
            wont_change.push_back(v[i]);
            last_mini = v[i];
            v[i] = 11;
        }
    }
    for (i = 0; i < v.size(); i++)
    {
        if (v[i] != 9)
            v[i]++;
    }
    vector<ll> answer;
    for (i = 0; i < v.size(); i++)
    {
        if (v[i] < 10)
            answer.push_back(v[i]);
    }
    for (i = 0; i < wont_change.size(); i++)
    {
        answer.push_back(wont_change[i]);
    }
    sort(answer.begin(), answer.end());
    for (auto x : answer)
    {
        cout << x;
    }

    cout << line;
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
    08-10-2022 12:11
*/
