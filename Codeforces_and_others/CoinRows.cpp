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
    vector<ll> pre_front(n + 1), pre_back(n + 1);
    for (i = 1; i <= n; i++)
        cin >> pre_back[i];
    for (i = 1; i <= n; i++)
        cin >> pre_front[i];
    for (i = 2; i <= n; i++)
        pre_front[i] = pre_front[i - 1] + pre_front[i];
    for (i = n - 1; i >= 1; i--)
        pre_back[i] = pre_back[i + 1] + pre_back[i];
    ll ans = infinite;
    for (i = 1; i <= n; i++)
    {
        ll dum_ans = 0;
        if (i - 1 >= 1)
        {
            dum_ans = max(dum_ans, pre_front[i - 1]);
        }
        if (i + 1 <= n)
        {
            dum_ans = max(dum_ans, pre_back[i + 1]);
        }
        ans = min(dum_ans, ans);
    }
    cout << ans << endl;
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