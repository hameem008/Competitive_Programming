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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, i, j, k, a, b, m, n, p;
    cin >> t;
    while (t--)
    {
        // solve starts
        cin >> n;
        vector<ll> v1(n);
        for (i = 0; i < n; i++)
        {
            cin >> v1[i];
        }
        vector<ll> v2(n);
        v2[0] = v1[0];
        for (i = 1; i < n; i++)
        {
            v2[i] = v1[i] + v2[i - 1];
        }
        bool flag = true;
        for (i = 0; i < n - 1; i++)
        {
            if (v2[i] >= v1[i + 1] && v1[i + 1] != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
        {
            cout << -1 << line;
            continue;
        }
        for (i = 0; i < n; i++)
        {
            cout << v2[i] << " ";
        }
        cout << line;
        // solve ends
    }
    return 0;
}

/*
    Ha Meem
    from BUET CSE-20
    hameem812@gmail.com
*/
