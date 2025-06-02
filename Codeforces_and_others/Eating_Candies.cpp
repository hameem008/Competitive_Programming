/*
        Make sure to keep my distance
        Say, "I love you," when you're not listening
        How long 'til we call this love, love, love?
        ---Distance

        lyrics from my favourite song
*/

#include <bits/stdc++.h>
#define line '\n'
using namespace std;
typedef long long ll;

// #define debugging(...) __f(#__VA_ARGS__, __VA_ARGS__)
// template <typename Arg1>
// void __f(const char *name, Arg1 arg1)
// {
//     cout << name << " : " << arg1 << endl;
// }
// template <typename Arg1, typename... Args>
// void __f(const char *names, Arg1 arg1, Args... args)
// {
//     const char *comma = strchr(names + 1, ',');
//     cout.write(names, comma - names) << " : " << arg1 << " | ";
//     __f(comma + 1, args...);
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, i, j, k, a, b, m, n;
    cin >> t;
    for (k = 0; k < t; k++)
    {
        // solve starts
        cin >> n;
        vector<ll> v(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (n == 1)
        {
            cout << 0 << line;
            continue;
        }
        if (n == 2)
        {
            if (v[0] == v[1])
                cout << 2 << line;
            else
                cout << 0 << line;
            continue;
        }
        ll sum_1 = v[0], sum_2 = v[n - 1], ans = 0, candy_count = 2;
        for (i = 0, j = n - 1; i<n - 1, j> 0;)
        {
            if (sum_1 > sum_2)
            {
                j--;
                sum_2 += v[j];
                candy_count++;
            }
            else if (sum_1 < sum_2)
            {
                i++;
                sum_1 += v[i];
                candy_count++;
            }

            if (sum_1 == sum_2)
            {
                ans = candy_count;
                if (j - i == 1)
                    break;
                i++;
                sum_1 += v[i];
                candy_count++;
            }
            if (j - i == 1)
                break;
        }
        cout << ans << line;
        // solve ends
    }
    return 0;
}

/*
    Ha Meem
    from BUET CSE-20
    hameem812@gmail.com
*/
