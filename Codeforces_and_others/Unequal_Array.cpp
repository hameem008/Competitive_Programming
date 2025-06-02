#include <bits/stdc++.h>
#define line '\n'
using namespace std;
typedef long long ll;

#define debugging(...) __f(#__VA_ARGS__, __VA_ARGS__)
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
int hameem=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, i, j, k, a, b, m, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> v(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll first_equ_i, last_equ_i, equ_count = 0;
        for (i = 0; i < n - 1; i++)
        {
            if (v[i] == v[i + 1] && equ_count == 0)
            {
                first_equ_i = i;
                equ_count++;
                continue;
            }
            if (v[i] == v[i + 1])
            {
                equ_count++;
                last_equ_i = i;
            }
        }
        if (equ_count == 0 || equ_count == 1)
        {
            cout << 0 << line;
        }
        else if (last_equ_i - first_equ_i == 1)
        {
            cout << 1 << line;
        }
        else
        {
            first_equ_i++;
            cout << last_equ_i - first_equ_i << line;
        }
    }
    return hameem;
}
