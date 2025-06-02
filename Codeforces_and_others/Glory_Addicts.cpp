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
ll sum(deque<ll>::iterator it_start, deque<ll>::iterator it_end, int n)
{
    ll sum = 0;
    for (; it_start != it_end; it_start++)
    {
        sum=sum+*it_start;
    }
    return sum;
}
ll sum(deque<ll>::reverse_iterator it_start, deque<ll>::reverse_iterator it_end, int n)
{
    ll sum = 0;
    for (; it_start != it_end; it_start++)
    {
        sum=sum+*it_start;
    }
    return sum;
}
void solve()
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    vector<ll> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    deque<ll> one, zero;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        if (v[i] == 0)
            zero.push_back(p);
        else
            one.push_back(p);
    }
    sort(zero.begin(), zero.end());
    sort(one.begin(), one.end());
    ll cnt_0 = zero.size();
    ll cnt_1 = one.size();
    if (cnt_0 == 0)
    {
        ll ans = sum(one.begin(), one.end(), 0);
        cout << ans << line;
        return;
    }
    if (cnt_1 == 0)
    {
        ll ans = sum(zero.begin(), zero.end(), 0);
        cout << ans << line;
        return;
    }
    ll sum_1 = 0, sum_0 = 0;
    ll sum_2;
    if (cnt_0 != cnt_1)
    {
        ll mini = min(cnt_0, cnt_1);
        sum_1 = 2 * sum(one.rbegin(), one.rbegin() + mini, 0);
        sum_0 = 2 * sum(zero.rbegin(), zero.rbegin() + mini, 0);
        if (mini == cnt_0)
        {
            sum_2 = sum(one.begin(), one.begin() + cnt_1 - mini, 0);
        }
        else
        {
            sum_2 = sum(zero.begin(), zero.begin() + cnt_0 - mini, 0);
        }
        cout << sum_0 + sum_1 + sum_2 << line;
    }
    else
    {
        if (*one.begin() < *zero.begin())
        {
            ll mini = *one.begin();
            one.pop_front();
            sum_1 = 2 * sum(one.rbegin(), one.rend(), 0);
            sum_0 = 2 * sum(zero.rbegin(), zero.rend(), 0);
            cout << sum_1 + sum_0 + mini << line;
        }
        else
        {
            ll mini = *zero.begin();
            zero.pop_front();
            sum_1 = 2 * sum(one.rbegin(), one.rend(), 0);
            sum_0 = 2 * sum(zero.rbegin(), zero.rend(), 0);
            cout << sum_1 + sum_0 + mini << line;
        }
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
    Ha Meem
    from BUET CSE-20
    hameem812@gmail.com
*/
