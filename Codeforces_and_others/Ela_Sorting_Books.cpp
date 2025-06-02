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

string test_case(int n)
{
    string test;
    for (int i = 0; i < n; i++)
    {
        test.push_back(rand() % 25 + 1 + 96);
    }
    return test;
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p, count;
    // solve stars
    cin >> n >> k;
    string str;
    cin >> str;
    // str = test_case(n);
    vector<ll> v(26);
    for (i = 0; i < v.size(); i++)
    {
        v[i] = 0;
    }
    for (i = 0; i < str.size(); i++)
    {
        v[str[i] - 96]++;
    }
    // for (i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << gap;
    // }
    // cout << line;
    string answer;
    for (j = 0; j < k; j++)
    {
        ll mini = 0;
        ll flag = true;

        count = 0;
        i = 1;
        while (count != n / k)
        {
            if (v[i] != 0)
            {
                v[i]--;
                count++;
            }
            else
            {
                if (flag == true)
                {
                    flag = false;
                    // cout << i << line;
                    mini = i;
                    count = n / k;
                    break;
                }
            }
            if (count == n / k && mini == 0)
                mini = i + 1;
            i++;
            if (i == 26)
            {
                mini = 26;
                count = n / k;
                break;
            }
        }

        // for (i = 1; i < 26; i++)
        // {
        //     count = 0;
        //     if (v[i] != 0)
        //     {
        //         v[i]--;
        //         count++;
        //     }
        //     else
        //     {
        //         if (flag == true)
        //         {
        //             flag = false;
        //             mini = i;
        //         }
        //     }

        //     if (count == n / k)
        //         break;
        // }
        answer.push_back(mini + 96);
        // cout << mini << line;
    }
    sort(answer.begin(), answer.end());
    reverse(answer.begin(), answer.end());
    sort(str.begin(), str.end());
    // cout << str << line;
    cout << answer << line;
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
    07-10-2022 20:58
*/
