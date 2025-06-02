#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
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

void solve(int I, int T)
{
    ll i, j, k, c, w, h, d, m, n, p, q;
    // solve starts
    cin >> n >> w >> h;
    vector<ll> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    ll hi = INT32_MAX, lo = INT32_MIN;
    i = 0;
    bool flag = true;
    while (n--)
    {
        ll curr_hi, curr_lo;
        curr_lo = a[i] - w + h;
        curr_hi = a[i] + w - h;
        ll min_plus = curr_lo - b[i], max_plus = curr_hi - b[i];
        if (min_plus > lo && max_plus < hi)
        {
            hi = max_plus;
            lo = min_plus;
        }
        else if (min_plus > lo)
            lo = min_plus;
        else if (max_plus < hi)
            hi = max_plus;
        if (max_plus < lo || min_plus > hi || hi < lo)
        {
            flag = false;
            break;
        }
        // debug(hi, lo, curr_hi, curr_lo, max_plus, min_plus);
        i++;
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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