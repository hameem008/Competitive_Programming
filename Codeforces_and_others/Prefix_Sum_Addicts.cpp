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
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n >> k;
    vector<ll> v(k);
    for (i = 0; i < k; i++)
    {
        cin >> v[i];
    }
    // if (I == 143)
    // {
    //     deque<ll> extract;
    //     extract.push_back(n);
    //     extract.push_back(k);
    //     for (i = 0; i < k; i++)
    //     {
    //         extract.push_back(v[i]);
    //     }
    //     for (i = 0; i < extract.size(); i++)
    //     {
    //         cout << extract[i] << "+";
    //     }
    //     cout << line;
    //     return;
    // }
    vector<ll> com;
    // if (v[0] < 0)
    //     com.push_back(v[0]);
    for (i = 0; i < k - 1; i++)
    {
        com.push_back(v[i + 1] - v[i]);
    }
    if (k == 1)
    {
        cout << "YES" << line;
        return;
    }
    ll f = com[0];
    bool flag = true;

    if (v[0] > f * (n + 1 - k))
        flag = false;

    if (flag == false)
    {
        cout << "NO" << line;
        return;
    }
    for (i = 0; i < com.size() - 1; i++)
    {
        if (com.size() == 1)
            break;
        if (com[i] > com[i + 1])
        {
            flag = false;
            break;
        }
    }
    if (flag == false)
    {
        cout << "NO" << line;
        return;
    }
    cout << "YES" << line;
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
