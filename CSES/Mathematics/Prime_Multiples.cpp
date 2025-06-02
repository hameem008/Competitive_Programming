#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

ll N;
ll ans = 0;
void subsetgen(vector<ll> &nums)
{
    ll n = nums.size();
    ll subsetCount = 1 << n;
    for (ll mask = 0; mask < subsetCount; ++mask)
    {
        ll mul = 1;
        bool flag = true;
        ll sz = 0;
        for (ll i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                lld chk = (mul / 1e9) * (nums[i] / 1e9);
                if (chk <= 1)
                {
                    mul *= nums[i];
                }
                else
                {
                    flag = false;
                    break;
                }
                sz++;
            }
        }
        if (flag && mul > 1)
        {
            if (sz % 2 == 0)
            {
                ans -= N / mul;
            }
            else
            {
                ans += N / mul;
            }
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    N = n;
    vector<ll> v(k), emptyv;
    for (auto &x : v)
        cin >> x;
    set<ll> s(v.begin(), v.end());
    v.assign(s.begin(), s.end());
    subsetgen(v);
    cout << ans << endl;
    //  solve ends
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