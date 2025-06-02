#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q, l;
    bool flag;
    // solve starts
    cin >> n >> l >> k;
    vector<ll> position(n + 1);
    for (i = 1; i <= n; i++)
        cin >> position[i];
    position.push_back(l);
    vector<ll> time_per_km(n + 1);
    for (i = 1; i <= n; i++)
        cin >> time_per_km[i];
    ll ans = 0;
    for (i = 1; i <= n; i++)
    {
        ans += (position[i + 1] - position[i]) * time_per_km[i];
    }
    ll profit, pro_ind, total_profit = 0;
    while (k)
    {
        profit = 0;
        for (i = 2; i <= n; i++)
        {
            if ((time_per_km[i] - time_per_km[i - 1]) * (position[i + 1] - position[i]) > profit)
            {
                profit = (time_per_km[i] - time_per_km[i - 1]) * (position[i + 1] - position[i]);
                pro_ind = i;
            }
        }
        if (profit)
        {
            vector<ll> dum_postion;
            vector<ll> dum_time_per_km;
            dum_postion.push_back(0);
            dum_time_per_km.push_back(0);
            for (i = 1; i <= n + 1; i++)
            {
                if (pro_ind != i)
                    dum_postion.push_back(position[i]);
            }
            for (i = 1; i <= n; i++)
            {
                if (pro_ind != i)
                    dum_time_per_km.push_back(time_per_km[i]);
            }
            n--;
            k--;
            position = dum_postion;
            time_per_km = dum_time_per_km;
            total_profit += profit;
        }
        else
            break;
    }
    cout << ans - total_profit << endl;
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