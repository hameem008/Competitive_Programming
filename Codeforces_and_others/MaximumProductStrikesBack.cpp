#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    vector<ll> ind;
    for (i = 0; i < n; i++)
    {
        if (v[i] == 0)
            ind.push_back(i);
    }
    ind.push_back(-1);
    ind.push_back(n);
    sort(ind.begin(), ind.end());
    pair<ll, ll> ans = {n, 0};
    ll ans_cnt2 = 0;
    for (i = 0; i < ind.size() - 1; i++)
    {
        ll start = ind[i] + 1, end = ind[i + 1] - 1;
        bool sign = true; // true = positive, false = negative
        ll cnt_2 = 0;

        for (j = start; j <= end; j++)
        {
            if (v[j] < 0)
            {
                if (sign)
                    sign = false;
                else
                    sign = true;
            }
            if (abs(v[j]) == 2)
                cnt_2++;
        }
        if (cnt_2)
        {
            if (!sign)
            {
                ll cnt_2p = cnt_2, cnt_2q = cnt_2;
                for (p = start; p <= end; p++)
                {
                    if (abs(v[p]) == 2)
                        cnt_2p--;
                    if (v[p] < 0)
                    {
                        sign = true;
                        break;
                    }
                }

                sign = false;
                for (q = end; q >= start; q--)
                {
                    if (abs(v[q]) == 2)
                        cnt_2q--;
                    if (v[q] < 0)
                    {
                        sign = true;
                        break;
                    }
                }

                if (cnt_2p > cnt_2q)
                {
                    start = p + 1;
                    cnt_2 = cnt_2p;
                }
                else
                {
                    end = q - 1;
                    cnt_2 = cnt_2q;
                }
            }
        }
        if (ans_cnt2 < cnt_2)
        {
            ans_cnt2 = cnt_2;
            ans.first = start, ans.second = end;
        }
    }
    if (ans_cnt2 == 0)
    {
        cout << n << gap << 0 << endl;
        return;
    }
    cout << ans.first << gap << n - ans.second - 1 << endl;
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