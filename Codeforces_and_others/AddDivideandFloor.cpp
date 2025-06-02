#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

ll fun(ll num, ll min_ele, ll max_ele)
{
    ll cnt_min = 0, cnt_max = 0;
    ll old_min_ele = min_ele, old_max_ele = max_ele;
    while (1)
    {
        if (num == min_ele)
        {
            break;
        }
        min_ele += num;
        min_ele /= 2;
        if (min_ele == old_min_ele)
        {
            cnt_min = infinite;
            break;
        }
        else
        {
            cnt_min++;
            old_min_ele = min_ele;
        }
    }
    while (1)
    {
        if (num == max_ele)
        {
            break;
        }
        max_ele += num;
        max_ele /= 2;
        if (max_ele == old_max_ele)
        {
            cnt_max = infinite;
            break;
        }
        else
        {
            cnt_max++;
            old_max_ele = max_ele;
        }
    }
    return max(cnt_max, cnt_min);
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    ll max_ele = *max_element(v.begin(), v.end());
    ll min_ele = *min_element(v.begin(), v.end());
    ll min_step = infinite, ans = 0;
    for (auto x : v)
    {
        ll curr_step = fun(x, min_ele, max_ele);
        if (min_step > curr_step)
        {
            min_step = curr_step;
            ans = x;
        }
        curr_step = fun(x + 1, min_ele, max_ele);
        if (min_step > curr_step)
        {
            min_step = curr_step;
            ans = x + 1;
        }
    }
    if (min_step <= n)
    {
        cout << min_step << endl;
        for (i = 1; i <= min_step; i++)
            cout << ans << gap;
        cout << endl;
    }
    else
        cout << min_step << endl;
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