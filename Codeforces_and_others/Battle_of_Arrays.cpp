#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

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

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag = true;
    // solve starts
    cin >> n >> m;
    multiset<ll> ms_n, ms_m;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        ms_n.insert(a);
    }
    for (i = 0; i < m; i++)
    {
        cin >> a;
        ms_m.insert(a);
    }
    while (1)
    {
        if (ms_n.size() == 0)
        {
            cout << "Bob" << endl;
            break;
        }
        else if (ms_m.size() == 0)
        {
            cout << "Alice" << endl;
            break;
        }
        auto it_n = ms_n.end(), it_m = ms_m.end();
        it_n--, it_m--;
        ll num_n = *it_n, num_m = *it_m;
        if (flag)
        {
            if (num_n >= num_m)
            {
                ms_m.erase(it_m);
            }
            else
            {
                ms_m.erase(it_m);
                ms_m.insert(num_m - num_n);
            }
            flag = false;
        }
        else
        {
            if (num_m >= num_n)
            {
                ms_n.erase(it_n);
            }
            else
            {
                ms_n.erase(it_n);
                ms_n.insert(num_n - num_m);
            }
            flag = true;
        }
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}