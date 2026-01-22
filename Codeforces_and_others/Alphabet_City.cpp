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

bool pf(int mid, vector<ll> &v_cnt, vector<ll> &v_cnt_rem)
{
    bool flag = true;
    for (int i = 0; i < 26; i++)
    {
        if (v_cnt_rem[i] * mid < v_cnt[i])
        {
            flag = false;
            break;
        }
    }
    return flag;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> m;
    vector<ll> v(26, 0);
    vector<string> v_str;
    for (i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v_str.push_back(str);
        for (auto x : str)
            v[x - 'A']++;
    }
    for (auto str : v_str)
    {
        vector<ll> v_cnt_rem = v, v_cnt(26, 0);
        for (auto x : str)
        {
            v_cnt_rem[x - 'A']--;
            v_cnt[x - 'A']++;
        }
        ll hi = m, lo = 1, mid;
        while (hi - lo > 1) // FFFFTTT find first true
        {
            mid = (hi + lo) / 2;
            if (pf(mid, v_cnt, v_cnt_rem))
                hi = mid;
            else
                lo = mid + 1;
        }
        if (pf(lo, v_cnt, v_cnt_rem))
            cout << m - lo << gap;
        else if (pf(hi, v_cnt, v_cnt_rem))
            cout << m - hi << gap;
        else
            cout << -1 << gap;
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}